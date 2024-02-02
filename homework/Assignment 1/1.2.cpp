// 
// By Benjamin Bassett (benonymity) on 1.29.24
// 
// For CMP-201 with Dr. Seiffert at Hillsdale College
// https://github.com/benonymity/CMP-201
// 

#include <iostream>
#include <random>

using namespace std;

int main() {
    // Input variables
    int min{0};
    int max{0};
    // Calculable variables & constants
    int guess{0};
    int num{0};
    int response{0};
    // Lists of possible responses to reduce repetitiveness
    string high[4]{"A little too high!\n", "Close, but too far north!\n", "Try guessing a lower number\n", "Good effort, but bring down the digits a bit!\n"};
    string low[4]{"Try guessing a bit higher\n", "A little too modest a guess; shoot for the stars!\n", "Try moving your mark a bit higher\n", "Seek your quarry in more northern climes!\n"};

    // Fun ASCII art that plays no computational role
    cout << " ██████  ██    ██ ███████ ███████ ███████ ██ ███    ██  ██████       ██████   █████  ███    ███ ███████ \n██       ██    ██ ██      ██      ██      ██ ████   ██ ██           ██       ██   ██ ████  ████ ██      \n██   ███ ██    ██ █████   ███████ ███████ ██ ██ ██  ██ ██   ███     ██   ███ ███████ ██ ████ ██ █████   \n██    ██ ██    ██ ██           ██      ██ ██ ██  ██ ██ ██    ██     ██    ██ ██   ██ ██  ██  ██ ██      \n ██████   ██████  ███████ ███████ ███████ ██ ██   ████  ██████       ██████  ██   ██ ██      ██ ███████ \n\n";
    cout << "Let's play a guessing game!\n\n";

    // Prompt for input
    cout << "Start by entering the minimum number you're willing to guess: ";
    cin >> min;

    cout << "And the maxiumum: ";
    // Verify that the maximum is greater than the minimum
    while (max < min) {
        cin >> max;
        if (max < min) {
            cout << "Enter a number greater than your minimum!\n";
            cout << "Enter the maximum number you're willing to guess: ";
        }
    }

    // Choose a random number (though the modulo isn't perfectly random, as it's very slightly skewed toward lower numbers)
    num = rand() % (max-min) + 1;

    cout << "Let's begin!\n\n——————————————\n";

    // Guessing loop
    while (guess != num) {
        cout << "Guess a number: ";
        cin >> guess;
        response = rand() % 4 + 1;
        // Check bounds
        if (guess > max) {
            cout << "Whoops, you've guessed even higher than the upper boundary!\n";
        } else if (guess < min) {
            cout << "That's lower than you said you wanted to go!\n";
        } else if (guess > num) {
            // Randomize responses
            cout << high[response];
        } else if (guess < num ) {
            // Randomize responses
            cout << low[response];
        }
    }
    // Correct guess response
    cout << "Nicely done! You've guessed the number! (if you couldn't tell, it was " << num << " ;)\n";
}