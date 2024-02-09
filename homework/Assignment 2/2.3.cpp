// 
// By Benjamin Bassett (benonymity) on 2.6.24
// 
// For CMP-201 with Dr. Seiffert at Hillsdale College
// https://github.com/benonymity/CMP-201
// 

// Include all the appropriate headers
#include <iostream>
#include <random>
#include <cmath>
#include <ctime>

// Define the pile class
class Pile {
    public:
        // Pile constructor (it's a whole function because the 
        // shortened declaration syntax doesn't allow for 
        // salting the randomizer)
        Pile() {
            // Define the maximum and minimum pile size
            max = 150;
            min = 50;
            
            // Salt based on time and generate a random pile size
            srand(time(0));
            tokens = rand() % (max - min + 1) + min;
        }

        // Function to actually remove tokens
        void remove_tokens(int num) {
            tokens -= num;
        }

        // Returns half the pile, rounded up
        int max_legal_move() const {
            return ceil(tokens/2);
        }

        // Returns how many tokens are in the pile
        int get_tokens() const {
            return tokens;
        }
    private:
        // Explicitly defining the maximum and minimum pile sizes
        int max;
        int min;
        // How many tokens are in the pile
        int tokens;
};

// Define the player class
class Player {
    public:
        // Simple constructor
        Player(std::string user): name{user}, computer{name.find("Computer") != std::string::npos} {}

        // Get the player name
        std::string get_name() {
            return name;
        }

        // Define the operator to allow comparison
        bool operator==(const Player& p2) const {
            return name == p2.name;
        }

        // The chunky function to actually make moves
        void make_move(Pile& pile, bool optimal) {
            // Create this once to prevent callign them 10 times
            int max_move{pile.max_legal_move()};
            int curr{pile.get_tokens()};
            int move{0};

            // Print active player
            std::cout << name << "'s turn:\n";
            
            // Computer playing optimally case
            if (computer && optimal) {
                std::cout << "There are " << pile.get_tokens() << " tokens in the pile\n";
                
                // List of losing numbers to force your opponent to
                // https://oeis.org/A126646
                int goals[15]{1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767};
                
                // Iterate through and find the next lowest goal number
                for (int goal : goals) {
                    if (((goal + 1) * 2 - 1) > curr) {
                        if ((curr - goal) < 1 || (curr - goal) > pile.max_legal_move()) {
                            move = 1;
                        } else {
                            move = curr - goal;
                        }
                    }
                }
                
            // Picking a random valid number—don't play optimally case
            } else if (computer && !optimal) {
                // Still do nice printing when the computer moves
                std::cout << "There are " << curr << " tokens in the pile\n";
                
                // Pick a random number
                move = rand() % (max_move) + 1;
                
                // Sometimes rand() goes crazy, and I'm not really sure
                //  why, so check to make sure it's rational
                if (move > max_move) {
                    move = 1;
                }
            // It's a human case
            } else {
                // Loop for checking validity
                while (move < 1 || move > max_move) {
                    // Print current pile size
                    std::cout << "There are " << curr << " tokens in the pile\nYour move: ";
                    
                    // Ask for move
                    std::cin >> move;
                    
                    // Check failure case (I know this wasn't required, but 
                    // it was annoying when I pressed a wrong key and got a
                    // wall of text)
                    if (std::cin.fail()) {
                        // Reset cin
                        std::cin.clear();
                        
                        // Ignore the rest of the input (thanks Stack Overflow! ;)
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input. Please enter a number.\n\n";
                        move = 0;
                    // Check whether the move is valid
                    } else if (move < 1 || move > max_move) {
                        std::cout << "That's an invalid move. Try again.\n\n";
                    }
                }
            }
            
            // Apply the move to the pile
            pile.remove_tokens(move);
            // Print the move
            std::cout << name << " took away " << move << " tokens\n\n";
        }
    private:
        // Define name and type
        std::string name;
        bool computer;
};

// Define the game class
class Game {
    public:
        // Game constructor with player names and optimal flag
        Game(std::string player1, std::string player2, bool optimal_play): p1{player1}, p2{player2}, optimal{optimal_play}, pile{} {}

        // Active player switcher
        void switch_players() {
            if (*player == p1) {
                player = &p2;
            } else if (*player == p2) {
                player = &p1;
            }
        }

        // The big one
        void play() {
            // Individualize response based on player types
            if (p1.get_name().find("Computer") != std::string::npos) {
                std::cout << "Welcome " << p2.get_name() << ", let's play some Nim!\n\n";
            } else if (p2.get_name().find("Computer") != std::string::npos) {
                std::cout << "Welcome " << p1.get_name() << ", let's play some Nim!\n\n";
            } else {
                std::cout << "Welcome " << p1.get_name() << " and " << p2.get_name() << ", let's play some Nim!\n\n";
            }

            // Define variables for play
            int tokens{pile.get_tokens()};
            player = &p1;
            bool playing{true};

            // Playing loop
            while (playing) {
                // Generate a move
                (*player).make_move(pile, optimal);
                // Update pile size
                int tokens = pile.get_tokens();
                // End the game
                if (tokens <= 1) {
                    // More ASCII art (gotta have fireworks)
                    std::cout << "                                   .''.       \n       .''.      .        *''*    :_\\/_:     . \n      :_\\/_:   _\\(/_  .:.*_\\/_*   : /\\ :  .'.:.'.\n  .''.: /\\ :   ./)\\   ':'* /\\ * :  '..'.  -=:o:=-\n :_\\/_:'.:::.    ' *''*    * '.\'/.' _\\(/_'.':'.'\n : /\\ : :::::     *_\\/_*     -= o =-  /)\\    '  *\n  '..'  ':::'     * /\\ *     .'/.\'.   '\n      *            *..*         :\n        *\n        *\n";
                    std::cout << "Congratulations " << (*player).get_name() << "! You won!\n";
                    // Exit the loop
                    playing = false;
                }
                // Switch the active player
                switch_players();
            }
        }
    private:
        // Define players
        Player p1;
        Player p2;
        // Define current player pointer
        Player* player;
        // Whether the computer (if it exists) will play optimally
        bool optimal;
        // Instantiate the pile the game uses
        Pile pile;
};

// Actually run the thing
int main() {
    // Fun ASCII art that plays no computational role
    std::cout << "    __         __ _                __               _   ___           __\n   / /   ___  / /( )_____   ____  / /___ ___  __   / | / (_)___ ___  / /\n  / /   / _ \\/ __/// ___/  / __ \\/ / __ `/ / / /  /  |/ / / __ `__ \\/ / \n / /___/  __/ /_  (__  )  / /_/ / / /_/ / /_/ /  / /|  / / / / / / /_/  \n/_____/\\___/\\__/ /____/  / .___/_/\\__,_/\\__, /  /_/ |_/_/_/ /_/ /_(_)   \n                        /_/            /____/                           \n";
    
    // Declare input variables
    std::string p1;
    std::string p2;
    bool optimal{false};
    
    // Ask user(s) for input
    std::cout << "Enter the name of Player 1: ";
    std::cin >> p1;
    std::cout << "Enter the name of Player 2: ";
    std::cin >> p2;
    
    // Make sure the player == operator doesn't get 
    // thrown off by duplicated names
    if (p1 == p2) {
        std::cout << "Sorry, you can't have two players with the same name!\n";
        exit(1);
    }
    
    // Inquire about optimal play
    // (fuzzy finding "Computer" to allow two at once)
    if (p1.find("Computer") != std::string::npos || p2.find("Computer") != std::string::npos) {
        std::string Yn;
        std::cout << "Would you like the computer to play optimally? (Y/n) ";
        std::cin >> Yn;
        if (Yn == "Y") {
            optimal = true;
        }
    }
    
    // Play the game!
    Game game{p1, p2, optimal};
    game.play();

    // Close the program gracefully
    exit(1);
}