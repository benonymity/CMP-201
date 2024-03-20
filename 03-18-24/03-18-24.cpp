#include <iostream>

class A {
  public:
    void print() {
        std::cout << x << "\n";
    }
    int x = 0;
};

class B : virtual public A {
  public:
    B() {
        std::cout << "B\n";
    }
    void print() {
        std::cout << y << "\n";
        A::print();
    }
    int y = 1;
};

class C : virtual public A {
  public:
    C() {
        std::cout << "C\n";
    }
    void print() {
        std::cout << z << "\n";
        A::print();
    }
    int z = 2;
};

class D : public B, public C {
  public:
    void print() {
        std::cout << w << "\n";
        B::print();
        C::print();
    }
    int w = 5;
};

int main() {
    D d;
    d.print();
    d.B::y = 4;
    d.print();
    d.C::z = 8;
    d.print();
}
