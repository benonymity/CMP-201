#include <iostream>

using namespace std;

int greater_count(const vector<int>&, const int);
int* give_pointer();

class Fraction {
    int num;
    int denom;
}

int main() {
    vector<int> nums = {1, 5, 10, 15, 20, 25, 30};
    int many;
    int min = 14;
    many = greater_count(nums, min);
    for (int num : nums) {
        cout << num << ", ";
    }
    cout << endl;
    cout << many << " numbers greater than " << min << endl;

    int* new_int = give_pointer();
    cout << *new_int << endl;

    Fraction f1;
    // Next class:
    // f1.num = 22;
    // f1.denom = 7;
}

int greater_count(const vector<int>& vec, const int threshold) {
    int count = 0;
    for (int num : vec) {
        if (num > threshold) {
            count += 1;
        }
    }
    return count;
}

int* give_pointer() {
    int x{10};
    int* p = new int;
    int* q = &x;

    // return q;
    return p;
}