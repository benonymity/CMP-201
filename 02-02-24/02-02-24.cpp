#include <iostream>

using namespace std;

class Fraction {
    public:
        Fraction(): num{0}, denom{0} {}
        Fraction(int num, int denom): num{num}, denom{denom} {}

        string to_string() const;
        void set_num(int num); // {this->num = num;}
        void set_denom(int denom) {this->denom = denom;}
    private:
        int num;
        int denom;
};

int main() {
    Fraction f1;

    f1.set_num(22);
    f1.set_denom(7);

    cout << f1.to_string() << endl;

    // Fraction f2(3, 4);
    Fraction f2{3, 4};

    cout << f2.to_string() << endl;
}

string Fraction::to_string() const {
    return std::to_string(num) + "/" + std::to_string(denom);
}

void Fraction::set_num(int num) {
    this->num = num;
}

// void Fraction::set_denom(int denom) {
//     this->denom = denom;
// }