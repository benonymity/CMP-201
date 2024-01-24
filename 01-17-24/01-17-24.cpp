#include <iostream>
#include <ctime>

using namespace std;

void hello() {
    string name;
    cout << "Welcome to CS!\nWhat's your name? ";
    // cin >> name
    // To ignore whitespace, use getline() instead of std::cin
    getline (cin, name);
    cout << "Hello " + name + "! Welcome to CMP201\n";
}

void age() {
    int age;
    cout << "How old are you?" << endl;
    cin >> age;
    std::time_t t = std::time(nullptr);
    std::tm *const pTInfo = std::localtime(&t);
    const int year = 1900 + pTInfo->tm_year;
    cout <<  "Hillsdale College is " + to_string(year-1844-age) + " years older than you!\n";
}

int main() {
    hello();
    age();
    return 0;
}