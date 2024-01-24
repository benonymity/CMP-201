#include <iostream>
#include <string>

using namespace std;

int main() {
    int numbers[] = {5, 6, 7, 8, 4, 3, 2};
    // These all do the same thing:
    for (int i = 0; i < 7; i++) { // Braces optional with one line
        cout << numbers[i] << endl;
    }
    cout << "---\n";
    int size = sizeof(numbers)/sizeof(*numbers);
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << endl;
    }
    cout << "---\n";
    for (int* i{numbers}; i < &numbers[size]; i++) {
        cout << *i << endl;
        // Because this is dereferenced, we have r/w access to that memory location.
        // Here we're printing, but we could also do something like `*i = 7;` to modify them.
    }
    // Doesn't do the same:
    cout << "---\n";
    for (int* i{numbers}; i < &numbers[size]; i++) {
        cout << i << " - " << *i << endl;
    }

    cout << "---\n";
    int x = 4;
    int* p = &x;
    *p = 7; // This is modifying x indirectly, because it's referencing the same address as x
    cout << *p << endl;

    cout << "---\n";
    int& r = x;
    r = 77;
    cout << r << endl;

    cout << "---\n";
    int* q = p;
    *q = 777;
    cout << x << endl;

    cout << "---\n";
    int** s = &p;
    cout << x << endl;
    // In general, don't mix references and pointers

    cout << "---\n";
    string hi = "Welcome to Hillsdale!";
    for (char i : hi) {
        cout << i << " ";
    }
    cout << endl;
}