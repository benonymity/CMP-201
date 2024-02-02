    // 
    // By Benjamin Bassett (benonymity) on 1.29.24
    // 
    // For CMP-201 with Dr. Seiffert at Hillsdale College
    // https://github.com/benonymity/CMP-201
    // 

    #include <iostream>

    using namespace std;

    int main() {
        // Input variables
        float mileage{0.0};
        float price{0.0};
        float budget{0.0};
        // Calculated variables & constant
        const int miles{57};
        // const int miles{78}; It is in reality a 78 drive to Ypsilanti! But I'll use the given 57 miles
        float percent{0.0};
        float travelable{0};

        // Fun ASCII art that plays no computational role
        cout << " _                          _ _             _   _ \n| |_ ___    _   _ _ __  ___(_) | __ _ _ __ | |_(_)\n| __/ _ \\  | | | | '_ \\/ __| | |/ _` | '_ \\| __| |\n| || (_) | | |_| | |_) \\__ \\ | | (_| | | | | |_| |\n \\__\\___/   \\__, | .__/|___/_|_|\\__,_|_| |_|\\__|_|\n            |___/|_|\n\n     .--------.\n____/_____|___ \\___\nO    _   - |   _   ,*\n'--(_)-------(_)--'\n\n";
        cout << "So you'd like to get to Ypsilanti! I'll need a bit more information to discover your chances.\n\n";

        // Requesting inputs
        cout << "What is your car's gas mileage? ";
        cin >> mileage;

        cout << "How about current gas prices? ";
        cin >> price;

        cout << "And finally, how much money are you willing to spend? $";
        cin >> budget;
        cout << endl;

        // Calculating possible travel distance
        travelable = budget / price * mileage;

        // Response based on success
        if (travelable >= miles) {
            cout << "Based on that info, you'll be able to make it to Ypsilanti with no trouble!" << endl;
        } else {
            cout << "Uh oh, looks like you'll only make it " << (int)(travelable/miles * 100) << "% of the way to Ypsilanti :(\nMaybe stop in Jackson instead!" << endl;
        }
    }