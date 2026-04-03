#include <iostream>

// struct Complex {
//     int real;
//     int img;
// };

// struct Point {
//     Complex x;
//     Complex y;
// };

// void test(Point& point) {
//     point.x.img = 1;
//     point.x.real = 1;
//     point.y.real = 3;
//     point.y.img = 3;
// }

// void test2(int& test) {
//        test += 1; 
// }















// void sumTraengularSides1(int x1, int x2, int x3, int y1, int y2, int y3) {
//     // sum
//     int sum = int x1, int x2, int x3, int y1, int y2, int y3
// }

// struct Point {
//     int x;
//     int y;
// };

// void sumTraengularSides1(Point p1, Point p2, Point p3) {
//     // sum
//     int sum = p1.x + p1.y + p2.x + p3.y;
// }

// struct Traengular {
//     Point p1;
//     Point p2;
//     Point p3;
// };


// void sumTraengularSides3(Traengular t) {
//     // sum
// }


// void squareTraengular1Traengular2(Traengular t1, Traengular t2) {
//     // sum
//     t1.p1.x + 
// }










// void printUserData(User user) {

//     // User : Ivanov Ivan Tetrovich
//     // Age: 12 yeas
//     // Departmet: 
//     std::cout << user.name << std::endl;
// }










// enum class Departmet { None, IT, Transpotr, Shop };


// struct  User {
//     int ID = 1232;
//     std::string name = "";
//     std::string secondName = "";
//     std::string patronomic = "";
//     int age = 12;
//     std::string sex = "";
//     Departmet departmet = Departmet::None;

//     int getAge() const {
//         return age;
//     }


// };






// enum class Side { None, White, Black };
// enum class PieceType { None, King, Queen, Rook, Bishop, Knight, Pawn };

// struct Piece {
//     PieceType type = PieceType::None;
//     Side side = Side::None;
//     int age = 0;
//     Departmet departmet = Departmet::None;

//     bool isEmpty() const { 
//         return type == PieceType::None; 
//     }

//     bool isEnemy(Side other) const { 
//         return side != Side::None && side != other; 
//     }
// };

enum class Model {None, Audi, BMW, Mercedes, Volvo, Volkswagen};

enum class Currency {None, USD, FR, EUR};

struct Price {
    int dollars = 0;
    int cents = 0;
    Currency currency = Currency::None;

    Price(int d, int c, Currency curr) {
        dollars = d + c / 100;
        cents = c % 100;
        currency = curr;
    }

    Price() = default;

    std::string currencyToString(Currency currency) {
        // std::cout << "-------------------" << currency << std::endl;
        switch (currency) {
            case Currency::USD: return "USD";
            case Currency::FR: return "FR";
            case Currency::EUR: return "EUR";
            
            default: return "None";
        }
    }
};

struct Car {
    int milage = 0;
    Model model = Model::None;
    Price price = {
        0,
        0,
        Currency::None,
    };
};



std::string modelToString(Model model) {
    switch (model) {
        case Model::Audi: return "Audi";
        case Model::Mercedes: return "Mercedes";
        case Model::Volkswagen: return "Volkswagen";
        case Model::Volvo: return "Volvo";
        case Model::BMW: return "BMW";
        
        default: return "None";
    }
}

void carCard(Car car) {
    std::cout << "Model: " << modelToString(car.model) << std::endl;
    std::cout << "Milage: " << car.milage << std::endl;
    std::cout << "Price: " << car.price.dollars << "." << car.price.cents << " " << car.price.currencyToString(car.price.currency) << std::endl;
}



int main() {  

Car mercedes = {
    .milage = 67529,
    .model = Model::Mercedes,
    .price = { 
        71203, 
        246,
        Currency::USD
    },
};

    // User teacher = {
    //     .name = "Sofia",
    //     .secondName = "Ivanova",
    //     .patronomic = "Petrovna",
    //     .age = 25,
    //     .sex = "Female",
    //     .departmet = "Biology"
    // };

    carCard(mercedes);

    return 0;
}
