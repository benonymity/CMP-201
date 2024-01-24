#include <iostream>

using namespace std;

int main() {
    int numbers[] = {1, 2, 3, 4, 9, 50};

    // // These three things do the same thing, but never use the last two. ick.
    // cout << numbers[1] << endl;
    // cout << *(numbers + 1) << endl;
    // cout << 1[numbers] << endl;

    cout << "Here's the modified list: ";

    int length = sizeof(numbers)/sizeof(*numbers)-1;

    for (int& num : numbers) {
        if (num == numbers[length])
            cout << num * 2;
        else
            cout << num * 2 << ", ";
    }
    cout << endl;

    cout << "Here's the original list: ";

    for (int num : numbers) {
        if (num == numbers[length])
            cout << num;
        else
            cout << num << ", ";
    }
    cout << endl;

    // for (int i = 0; i < sizeof(numbers)/sizeof(*numbers); i += 1) 
    //     cout << numbers[i] << endl;
}