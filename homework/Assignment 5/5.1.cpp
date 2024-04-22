//
// By Benjamin Bassett (benonymity) on 4.19.24
//
// For CMP-201 with Dr. Seiffert at Hillsdale College
// https://github.com/benonymity/CMP-201
//

#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>

class HashMap {
  public:
    HashMap() {
    }

    int hash(std::string word) {
        int hash = 0;
        for (char letter : word) {
            hash = (3 * hash + std::tolower(letter)) % table_size;
        }
        return hash;
    }

    void insert(std::string word) {
        word = to_lower(word);
        int loc = hash(word);
        if (map[loc] == "") {
            map[loc] = word;
        } else {
            int i = 1;
            while (loc + i < table_size) {
                if (map[loc + i] == "") {
                    map[loc + i] = word;
                    break;
                }
                i += 1;
            }
        }
    }

    bool find(std::string word) {
        int loc = hash(word);
        if (to_lower(map[loc]) == to_lower(word)) {
            return true;
        } else {
            int i = 1;
            while (map[loc + i] != "") {
                if (to_lower(map[loc + i]) == to_lower(word)) {
                    return true;
                }
                i += 1;
            }
            return false;
        }
    }

    void del(std::string word) {
        int loc = hash(word);
        if (map[loc] == word) {
            map[loc] = "";
        } else {
            int i = 1;
            while (map[loc + i] != "") {
                if (map[loc + i] == word) {
                    map[loc + i] = "";
                    break;
                }
                i += 1;
            }
        }
        for (int i = 0; i < table_size; i++) {
            if (hash(map[i]) == loc) {
                map[loc] = map[i];
                map[i] = "";
            }
        }
    }

    void print() {
        for (int i = 0; i < table_size; i++) {
            std::cout << i << ": " << map[i] << std::endl;
        }
    }

  private:
    // randomly pick either 40 or 80 as the table size
    int table_size{(rand() % 2 == 0) ? 40 : 80}; // "m" (map size)
    std::map<int, std::string> map;

    std::string to_lower(std::string word) {
        std::string lower_word;
        for (char c : word) {
            lower_word += std::tolower(c);
        }
        return lower_word;
    }
};

int main() {
    srand(time(0));
    HashMap map;
    std::string word;
    std::list<std::string> words;
    std::ifstream wordlist("wordlist.txt");
    int next;

    std::cout
        << "____    __    ____  ______   .______       _______         __    "
           "__       ___           _______. __    __  \n\\   \\  /  \\  /   / "
           "/  __  \\  |   _  \\     |       \\       |  |  |  |     /   \\    "
           "     /       ||  |  |  | \n \\   \\/    \\/   / |  |  |  | |  |_)  "
           "|    |  .--.  |______|  |__|  |    /  ^  \\       |   (----`|  "
           "|__|  | \n  \\            /  |  |  |  | |      /     |  |  |  "
           "|______|   __   |   /  /_\\  \\       \\   \\    |   __   | \n   "
           "\\    /\\    /   |  `--'  | |  |\\  \\----.|  '--'  |      |  |  | "
           " |  /  _____  \\  .----)   |   |  |  |  | \n    \\__/  \\__/     "
           "\\______/  | _| `._____||_______/       |__|  |__| /__/     \\__\\ "
           "|_______/    |__|  |__| \n\n";

    for (int i = 0; i < 20; i++) {
        next = rand() % 380 + 1;
        for (int j = 0; j < next; j++) {
            std::getline(wordlist, word);
        }
        word[0] = std::toupper(word[0]);
        words.push_back(word);
    }
    wordlist.close();

    std::cout << "Word list: ";
    for (auto word : words) {
        map.insert(word);
        if (word == words.back()) {
            std::cout << word << std::endl << std::endl;
        } else {
            std::cout << word << ", ";
        }
    }

    std::cout << "Enter a word: ";
    std::string query;
    while (std::cin >> query) {
        if (map.find(query)) {
            std::cout << query << " is in the hash table";
        } else {
            std::cout << query << " is not in the hash table";
        }
        std::cout << "\\n\\nEnter a word: ";
    }
}