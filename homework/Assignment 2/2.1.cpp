// 
// By Benjamin Bassett (benonymity) on 2.3.24
// 
// For CMP-201 with Dr. Seiffert at Hillsdale College
// https://github.com/benonymity/CMP-201
// 

#include <iostream>

// Declare the function
int iterate_array(int &arr, int size);

int main() {
    // Declare a variable to hold the maximum number
    int max;
    // Define an example array
    int arr[12]{1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};

    // Fun ASCII art that plays no computational role
    std::cout << " _     _     _     _____                     _     \n| |   (_)   | |   /  ___|                   | |    \n| |    _ ___| |_  \\ `--.  ___  __ _ _ __ ___| |__  \n| |   | / __| __|  `--. \\/ _ \\/ _` | '__/ __| '_ \\ \n| |___| \\__ \\ |_  /\\__/ /  __/ (_| | | | (__| | | |\n\\_____/_|___/\\__| \\____/ \\___|\\__,_|_|  \\___|_| |_|\n\n";

    std::cout << "The largest number in the list (";

    // Pass the pointer and keep the returned int
    max = iterate_array(*arr, sizeof(arr)/sizeof(*arr));

    // Print the result!
    std::cout << ") is " << max << "!" << std::endl;
}

// Implement the function
int iterate_array(int &arr, int size) {
    // Iterate size times
    int max{0};
    int num{0};
    for (int i = 0; i < size; i++) {
        // Iterate the pointer then dereference it
        num = *(&arr + i);

        // Check if this is a new maximum number
        if (num > max) {
            // If so, save it
            max = num;
        }

        // Print the current number
        std::cout << num;

        // Pretty comma printing
        if ((i + 1) < size) {
            std::cout << ", ";
        }
    }
    // Return the final maximum
    return max;
}