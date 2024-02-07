#include <iostream>

using namespace std;

class Fraction {
    public:
        Fraction(): num{0}, denom{0} {cout << "constructing\n";}
        Fraction(int whole): num{whole}, denom{1} {}
        Fraction(int num, int denom): num{num}, denom{denom} {}

        Fraction(const Fraction& f) {
            num = f.num;
            denom = f.denom;
            cout << "copy constructor\n";
        }

        ~Fraction(){cout << "destructing " << num << "/" << denom << endl;}

        string to_string() const {return std::to_string(num) + "/" + std::to_string(denom);};
        void set_num(int num) {this->num = num;}
        void set_denom(int denom) {this->denom = denom;}

        int get_num() const {return num;}
        int get_denom() const {return denom;}

        Fraction add(const Fraction& rhs) {
            int sum_num{num * rhs.get_denom() + denom * rhs.get_num()};
            int sum_denom{denom * rhs.get_denom()};
            Fraction result(sum_num, sum_denom);
            return result;
        }

        Fraction operator+(const Fraction& rhs) {
            int sum_num{num * rhs.get_denom() + denom * rhs.get_num()};
            int sum_denom{denom * rhs.get_denom()};
            Fraction result(sum_num, sum_denom);
            return result;
        }

        Fraction operator=(const Fraction& rhs) {
            num = rhs.num;
            denom = rhs.denom;
            cout << "assignment\n";
            return rhs;
        }
    private:
        int num;
        int denom;
};

Fraction add_fractions(const Fraction& lhs, const Fraction& rhs);

int main() {
    Fraction f1;

    f1.set_num(22);
    f1.set_denom(7);

    // Fraction f2(3, 4);
    Fraction f2{3, 4};

    Fraction added = add_fractions(f1, f2);

    cout << f1.to_string() << " + " << f2.to_string() << " = " << added.to_string() << endl;


    added = f1.add(4);

    cout << f1.to_string() << " + 4 = " << added.to_string() << endl;

    Fraction f3{8, 11};

    added = f2 + f3;

    cout << f2.to_string() << " + " << f3.to_string() << " = " << added.to_string() << endl;

    Fraction f4;
    f4 = f1;
    cout << f4.to_string() << endl;

    Fraction f5 = f4; // copy constructor, not assignment!

    cout << f5.to_string() << endl;
}

Fraction add_fractions(const Fraction& lhs, const Fraction& rhs) {
    int sum_num{lhs.get_num() * rhs.get_denom() + lhs.get_denom() * rhs.get_num()};
    int sum_denom{lhs.get_denom() * rhs.get_denom()};
    Fraction result(sum_num, sum_denom);
    return result;
}