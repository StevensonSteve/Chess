#include <iostream>

enum class Work { None, Teatcher, Student };
enum class Sex { None, Male, Female };

std::string SexToString(Sex sex) {
    switch (sex) {
        case Sex::Male: return "Male";
        case Sex::Female: return "Female";
        
        default: return "None";
    }
};

std::string WorkToString(Work work) {
    switch (work) {
        case Work::Teatcher: return "Teatcher";
        case Work::Student: return "Student";
        
        default: return "None";
    }
};

struct Person {
    std::string name = "";
    std::string secondName = "";
    std::string patronymic = "";
    int age = 0;
    Sex sex = Sex::None;
    Work work = Work::None;

    void personalCard() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Second name: " << secondName << std::endl;
        std::cout << "Patronymic: " << patronymic << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Sex: " << SexToString(sex) << std::endl;
        std::cout << "Work: " << WorkToString(work) << std::endl;
    }
};

struct Teacher : public Person {
    std::string subject = ""; 
    int experience = 0;

    void personalCard() const {
        Person::personalCard();
        std::cout << "Subject: " << subject << std::endl;
        std::cout << "Experience: " << experience << std::endl;
    }
};


int main() {  

    Person User1 = {
        .name = "Steven",
        .secondName = "Alex",
        .patronymic = "Stevenson",
        .age = 14,
        .sex = Sex::Male,
        .work = Work::Student
    };

    Teacher teacher = {
        {
            .name = "Steven",
            .secondName = "Alex",
            .patronymic = "Stevenson",
            .age = 14,
            .sex = Sex::Male,
            .work = Work::Student 
        },
        .subject = "English",
        .experience = 5
    };

    User1.personalCard();
    std::cout << "****************************************" << std::endl;
    teacher.personalCard();

    return 0;
}
