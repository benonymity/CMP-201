// 
// By Benjamin Bassett (benonymity) on 1.30.24
// 
// For CMP-201 with Dr. Seiffert at Hillsdale College
// https://github.com/benonymity/CMP-201
// 

#include <iostream>

using namespace std;

int main() {
    // Input variables
    string original{""};
    // Constants and internal variables
    vector<string> bits;
    int iter{1};
    int total{0};
    string final_zip{""};
    const int weights[5]{7, 4, 2, 1, 0};

    // Fun ASCII art that plays no computational role
    cout << " ____  __  ____    ____  __  ____  ____ \n(__  )(  )(  _ \\  (  _ \\(  )(_  _)/ ___)\n / _/  )(  ) __/   ) _ ( )(   )(  \\___ \\ \n(____)(__)(__)    (____/(__) (__) (____/\n\n";

    // Prompt for input until a 27 byte string is given
    while (original.length() != 27) {
        cout << "Please enter your 27 bit string: ";
        cin >> original;
        if (original.length() != 27) {
            cout << "Please make it exactly 27 bits!\n";
        }
    }
    cout << endl;

    // Example string for testing without inputs
    // original = "110100110001100011000100101";

    // Iterating through the string to translate it to a vector
    for (int i = 0; i < original.length(); i++) {
        bits.push_back(original.substr(i, 1));
    }
    
    // Removing the first and last elements of the vector
    bits.pop_back();
    bits.erase(bits.begin());

    // Iterating through the remaining binary and summing the weights
    for (string bit : bits) {
        // Add to final string if this is the 5th byte
        if (iter == 5) {
            if (total == 11) {
                final_zip += "0";
            } else {
                final_zip += to_string(total);
            }
            iter = 0;
            total = 0;
        }
        // Add this weight if 1
        if (bit == "1") {
            total += weights[iter - 1];
        }
        // Tick the iterator
        iter += 1;
    }

    // Output the final zip code
    cout << "Ignoring the first and last bit, and proceeding in groups of 5 weighted [7, 4, 2, 1, 0], that string translates to the zip code " << final_zip << "!" << endl;
}