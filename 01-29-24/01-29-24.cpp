#include <iostream>

using namespace std;

// void swap(int, int);
void swap(int*, int*);
void swap(int&, int&);
int greater_count(vector<int>, int);

int main() {
    vector<int> data = {3, 1, 65, 4, 3};
    data[1] = 77;
    for (vector<int>::size_type i{ 0 }; i < data.size(); i++) {
        cout << data[i] << ' ';
    }
    cout << endl;

    int x = 4;
    int y = 5;
    cout << x << ' ' << y << endl;
    // swap(x, y);
    // cout << x << ' ' << y << endl;
    swap(&x, &y);
    cout << x << ' ' << y << endl;
    swap(x, y);
    cout << x << ' ' << y << endl;

    vector<int> nums = {1, 5, 10, 15, 20, 25, 30};
    int many;
    int min = 14;
    many = greater_count(nums, min);
    for (int num : nums) {
        cout << num << ', ';
    }
    cout << endl;
    cout << many << " numbers greater than " << min << endl;
}

// void swap(int x, int y) {
//     int new_y = x;
//     x = y;
//     y = new_y;
// }

void swap(int* x, int* y) {
    int new_y = *x;
    *x = *y;
    *y = new_y;
}

void swap(int& x, int& y) {
    int new_y = x;
    x = y;
    y = new_y;
}

int greater_count(vector<int> vec, int threshold) {
    int count = 0;
    for (int num : vec) {
        if (num > threshold) {
            count += 1;
        }
    }
    return count;
}