#include <iostream>

int main() {
    int a = 10;
    int* b = &a;
    int** c = &b;
    int*** d = &c;
    int**** e = &d;
    int***** f = &e;
    int****** g = &f;
    std::cout << ******g << "\n";
}