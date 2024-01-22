#include <iostream>
#include <iomanip>


using namespace std;

void hello() {
    string hello [] = {"H", "e", "l", "l", "o", "!"};
    for (int i = 0; i < 6; i += 1) 
        cout << hello[i];  
    cout << endl;
}

string trimZeros(string str) {
    if(str.find('.') != std::string::npos)
    {
        // Remove trailing zeroes
        str = str.substr(0, str.find_last_not_of('0')+1);
        // If the decimal point is now the last character, remove that as well
        if(str.find('.') == str.size()-1)
        {
            str = str.substr(0, str.size()-1);
        }
    }
    return str;
}

void average() {
    int many;
    cout << "How many numbers would you like to average?\n";
    cin >> many;
    int tot = 0;
    int cur;
    cout << "Enter your numbers:\n";
    for (int i = 0; i < (many); i += 1) 
        cin >> cur;
        tot += cur;
        cout << endl;
    cout << "The average of those numbers is " + to_string(tot/many);
}

void betterAverage() {
    double total = 0;
    int count = 0;
    bool active = true;
    double entry = 0;
    string fin = "0";
    cout << "Please enter numbers to average, enter -1 when done: \n";
    while (active) {
        cin >> entry;
        if (entry == -1) {
            active = false;
            if (count == 0) {
                cout << "Well that was useless...";
                break;
            }
        }
        total += entry;
        count ++;
    }
    fin = trimZeros(to_string(total/count));
    if (count > 1) {
        cout << "The average of those numbers is " << fin << endl;
    }
    if (count == 1) {
        cout << "The average of that number is " << fin << " (obviously...)" << endl;
    }
}

void stdDeiv() {
    // arrays, ooh
    cout << "Enter 5 numbers:\n";
    int numbers[5];
    for (int i = 0; i < 5; i += 1) {
        // do things
        break;
    }
}

int main() {
    hello();
    betterAverage();
}