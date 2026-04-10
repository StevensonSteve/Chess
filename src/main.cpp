#include <iostream>
#include <string>
#include <vector>

// --- Перечисления ---
enum class Work { None, Teacher, Student };
enum class Sex { None, Male, Female };

// Вспомогательные функции для вывода текста
std::string SexToString(Sex sex) {
    if (sex == Sex::Male) return "Male";
    if (sex == Sex::Female) return "Female";
    return "None";
}

std::string WorkToString(Work work) {
    if (work == Work::Teacher) return "Teacher";
    if (work == Work::Student) return "Student";
    return "None";
}

// --- Данные (DTO) ---
struct PersonData {
    std::string name;
    std::string secondName;
    std::string patronymic;
    int age;
    Sex sex;
    Work work;
};

// --- Базовый класс ---
class Person {
public:
    
    // PersonData d;
    // Конструктор принимает структуру данных и сохраняет её в защищенное поле d
    Person(const PersonData& data) : d(data) {}

    // Виртуальный деструктор обязателен для полиморфизма
    virtual ~Person() = default;

    // Виртуальный метод вывода (virtual)
    virtual void personalCard() const {
        std::cout << "Name: " << d.name << " " << d.secondName << " " << d.patronymic << "\n"
                  << "Age: " << d.age << " | Sex: " << SexToString(d.sex) 
                  << " | Role: " << WorkToString(d.work) << std::endl;
    }

    virtual void printTest() const {
        std::cout << "Test: " << test << std::endl;
    }

    virtual void setTest(int newTestValue) {
        test = newTestValue;
    }

protected:
    PersonData d; // Данные доступны наследникам

private:
    int test = 123;
};

// --- Наследник ---
class Teacher : public Person {
public:
    // Конструктор: передаем структуру в базу + свои поля
    Teacher(const PersonData& data, std::string sub, int exp)
        : Person(data), subject(sub), experience(exp) 
    {
        // Можно принудительно выставить тип работы, если в структуре передали не то
        d.work = Work::Teacher; 
    }

    // Переопределение метода (override)
    void personalCard() const override {
        Person::personalCard(); // Вызываем базовый вывод
        std::cout << "Subject: " << subject << " | Experience: " << experience << " years" << std::endl;
    }

private:
    std::string subject;
    int experience;
};

// --- Главная программа ---
int main() {
    // 1. Подготавливаем данные для объектов
    PersonData studentData = {
        "Steven", "Alex", "Stevenson", 14, Sex::Male, Work::Student
    };

    PersonData teacherData = {
        "Maria", "Ivanova", "Petrovna", 35, Sex::Female, Work::Teacher
    };

    // 2. Создаем объекты
    Person user1(studentData);
    Teacher teacher1(teacherData, "English", 10);
    // teacher1.

    // 3. Полиморфизм через вектор указателей
    // В векторе базового класса Person* могут лежать и Person, и Teacher
    std::vector<Person*> people;
    people.push_back(&user1);
    people.push_back(&teacher1);

    std::cout << "===== PERSONAL CARDS DATABASE =====" << std::endl;

    for (const auto* p : people) {
        // Благодаря virtual вызовется правильный метод:
        // для первого элемента — Person::personalCard()
        // для второго — Teacher::personalCard()
        p->personalCard(); 
        std::cout << "------------------------------------" << std::endl;
    }

    user1.printTest();
    user1.setTest(222);
    user1.printTest();

    return 0;
}
