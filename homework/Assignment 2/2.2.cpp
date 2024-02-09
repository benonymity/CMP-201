// 
// By Benjamin Bassett (benonymity) on 2.4.24
// 
// For CMP-201 with Dr. Seiffert at Hillsdale College
// https://github.com/benonymity/CMP-201
// 

#include <iostream>

// Define the lock class
class Lock {
    public:
        // Constructor to set the correct values
        Lock(int first, int second, int third): first_real{first}, second_real{second}, third_real{third} {}

        // Turn left
        void turn_left(int ticks) {
            // Only tick if this is the first or third try
            if (active == first && !jammed) {
                first_guess = ticks;
                active = second;
            } else if (active == third && !jammed) {
                third_guess = ticks;
                active = done;
            } else {
                // Otherwise jam the lock
                jammed = true;
            }
        }

        // Turn right
        void turn_right(int ticks) {
            // Only tick if we've moved left once
            if (active == second && !jammed) {
                second_guess = ticks;
                active = third;
            } else {
                // Otherwise jam the lock
                jammed = true;
            }
        }

        // Check if openable
        std::string open() {
            if (first_real == first_guess && second_real == second_guess && third_real == third_guess) {
                return "Open";
            } else {
                return "Locked";
            }
        }

        // Reset the lock
        void reset() {
            // Reset the opening progression
            active = first;
            jammed = false;
            
            // Reset guesses
            first_guess = 0;
            second_guess = 0;
            third_guess = 0;
        }
    private:
        // Solutions
        int first_real;
        int second_real;
        int third_real;

        // User guesses
        int first_guess{0};
        int second_guess{0};
        int third_guess{0};

        // Whether the sequence has been followed
        bool jammed{false};

        // Active part of the unlock progression
        // (using fancy enums)
        enum Active{first, second, third, done};
        Active active{first};
};

int main() {
    // Arbitrary lock state
    Lock lock{7, 15, 23};

    // Fun ASCII art that plays no computational role
    std::cout << "  #####                                                                            #                               \n #     #   ####   #    #  #####   #  #    #    ##    #####  #   ####   #    #      #         ####    ####   #    # \n #        #    #  ##  ##  #    #  #  ##   #   #  #     #    #  #    #  ##   #      #        #    #  #    #  #   #  \n #        #    #  # ## #  #####   #  # #  #  #    #    #    #  #    #  # #  #      #        #    #  #       ####   \n #        #    #  #    #  #    #  #  #  # #  ######    #    #  #    #  #  # #      #        #    #  #       #  #   \n #     #  #    #  #    #  #    #  #  #   ##  #    #    #    #  #    #  #   ##      #        #    #  #    #  #   #  \n  #####    ####   #    #  #####   #  #    #  #    #    #    #   ####   #    #      #######   ####    ####   #    # \n\n";

    // Introduction
    std::cout << "The combination lock is currently closed. To unlock it, you will need to turn the dial in the proper sequence. Good luck!\n\n";

    // Define user parameters
    int ticks{0};
    bool locked{true};
    std::string response;
    std::string open;

    // Run loop
    while (locked) {
        // Give options
        std::cout << "Would you like to turn the lock left, right, try to open it, or reset the dial? ";
        std::cin >> response;
        // Handle cases
        if (response == "left" || response == "Left") {
            // Turn left
            std::cout << "How far left would you like to turn dial? ";
            std::cin >> ticks;
            
            // Actually try to turn it
            lock.turn_left(ticks);
            std::cout << std::endl;
        } else if (response == "right" || response == "Right") {
            // Turn right
            std::cout << "How far right would you like to turn the dial? ";
            std::cin >> ticks;
            
            // Actually try to turn it
            lock.turn_right(ticks);
            std::cout << std::endl;
        } else if (response == "open" || response == "Open") {
            // Attempt to open the lock
            open = lock.open();
            
            if (open != "Open") {
                std::cout << "That's not the correct combination; the lock remains closed! Try resetting.\n\n";
            } else {
                // End the loop
                std::cout << "\nCongratulations! You opened the lock!\n";
                locked = false;
            }
        } else if (response == "reset" || response == "Reset") {
            // Reset the lock
            lock.reset();
            std::cout << "The dial has been reset.\n\n";
        } else {
            // Handle everything else
            std::cout << "Sorry, I don't recognize that command. Try again.\n\n";
        }
    }

    // Exit the program gracefully
    exit(1);
}