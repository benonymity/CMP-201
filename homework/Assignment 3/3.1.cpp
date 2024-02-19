//
// By Benjamin Bassett (benonymity) on 2.18.24
//
// For CMP-201 with Dr. Seiffert at Hillsdale College
// https://github.com/benonymity/CMP-201
//

// I started using the official clang formatter, so I guess all this is proper
// syntax. If formattering is wonky, blame LLVM ;)

#include <cmath>
#include <iostream>
#include <string>

// Define the item class
class Item {
  public:
    // Item constructor
    Item(std::string Name, int Mass, bool glass, bool explode,
         std::string Color, std::string Shape)
        : name{Name},
          mass{Mass},
          is_glass{glass},
          might_explode{explode},
          color{Color},
          shape{Shape} {
    }

    // Straightforward getters
    std::string get_name() {
        return name;
    }

    int get_weight() {
        return std::round(mass * gravity);
    }

    // Converts each item to a string, changes depending on boolean attributes
    std::string to_string() {
        std::string str;
        str = "Name: " + name + "\nMass: " + std::to_string(mass) +
              ((mass <= 1) ? " kg\nWeight: " : " kgs\nWeight: ") +
              std::to_string(get_weight()) + " Newtons\n";
        if (is_glass) {
            str += "This item is glass!\n";
        }
        if (might_explode) {
            str += "This item might explode!\n";
        }
        str += "Color: " + color + "\nShape: " + shape + "\n";
        return (str);
    }

  private:
    std::string name;
    int mass; // Weight independent of gravity–maybe this is the Space Academy
    bool is_glass;
    bool might_explode;
    std::string color;
    std::string shape;
    // Gravity, to three significant digits because we're not engineers ;)
    double gravity{9.81};
};

// Define the backpack class
class Backpack {
  public:
    // Simple constructor
    Backpack(int Capacity)
        : capacity{Capacity},
          contents() { // calling contents like this fills it will NULL pointers
    }
    // Copy constructor
    Backpack(Backpack& backpack) {
        capacity = backpack.capacity;
        weight = backpack.weight;
        for (int i = 0; i < 10; i++) {
            if (backpack.contents[i] != NULL) {
                contents[i] = new Item(*(backpack.contents[i]));
            }
        }
    }
    // Destructor to free up pointers in contents
    ~Backpack() {
        for (Item* item : contents) {
            delete item;
        }
    }
    // The all-important add function, returning it's success
    bool add(Item* new_item) {
        // If the new item fits
        if ((weight + new_item->get_weight()) <= capacity) {
            for (Item*& item : contents) {
                if (item == NULL) {
                    // This next line requires some explaining: creating a new
                    // item pointer isn't very efficient, but because the
                    // assignment asks for a destructor to free up the pointers
                    // in backpack, I'm creating a new pointer that's owned by
                    // the backpack and can't be interfered with. Otherwise, if
                    // a pointer from main() is passed and then it gets deleted
                    // (either by remove or the destructor), malloc freaks out
                    // because the memory it's trying to free is already gone.
                    // So while this isn't the most efficient implementation, it
                    // seems to best follow the instructions.
                    item = new Item(*new_item);
                    weight += new_item->get_weight();
                    // Success
                    return true;
                }
            }
        } else {
            // Not enough space left
            std::cout << "The backpack doesn't have enough capacity for " +
                             new_item->get_name() + "\n";
            return false;
        }
        // Contents[] are full
        std::cout << "The backpack is full\n";
        return false;
    }
    // Removal function
    bool remove(std::string name) {
        // The *& took a while to figure out, but now it's referencing a
        // pointer, so it can directly modify contents without having to iterate
        // and address it directly.
        for (Item*& item : contents) {
            if (item != NULL) {
                if (item->get_name() == name) {
                    // Free up the memory, then make space in contents[]
                    delete item;
                    item = NULL;
                    return true;
                }
            }
        }
        std::cout << "That item doesn't seem to exist in this backback\n";
        return false;
    }
    // Return an item pointer from its name alone
    Item* find(std::string name) {
        for (Item* item : contents) {
            if (item != NULL) {
                if (item->get_name() == name) {
                    return item;
                }
            }
        }
        return NULL;
    }
    // Iterate through contents and return their names
    std::string to_string() {
        std::string result{"["};
        for (Item* item : contents) {
            // Only return items that exist
            if (item != NULL) {
                // Gracefully handle commas
                if (result.length() > 1) {
                    result += ", " + item->get_name();
                } else {
                    result += item->get_name();
                }
            }
        }
        result += "]";
        return result;
    }

  private:
    // The essential list of item pointers
    Item* contents[10];
    // Backpack capacity
    int capacity;
    // Current backpack weight
    int weight{0};
};

// Define the student class
class Student {
  public:
    // Simple, but long, constructor
    Student(std::string Name, std::string Gender, std::string Class,
            int Credits, int Capacity, std::string Height)
        : name{Name},
          backpack{Capacity},
          gender{Gender},
          class_rank{Class},
          credits{Credits},
          height{Height} {
    }
    // Copy constructor
    Student(Student& student)
        : name{student.name},
          backpack{(student.backpack)}, // Blame pointers for this
          gender{student.gender},
          class_rank{student.class_rank},
          credits{student.credits},
          height{student.height} {
    }
    // Straightforward adding, pawning the work off on the backpack class
    bool add(Item* item) {
        return backpack.add(item);
    }
    // Same for remove, though it can take either an item pointer...
    bool remove(Item* item) {
        return backpack.remove(item->get_name());
    }
    // ...or a string
    bool remove(std::string item) {
        return backpack.remove(item);
    }
    // Basic give if an item pointer is being passed
    void give(Item* item, Student* student) {
        if (student->add(item)) {
            remove(item);
        }
    }
    // It's a little more complicated with a string
    void give(std::string item, Student* student) {
        // Find the pointer
        Item* transfer;
        transfer = backpack.find(item);
        // Make sure it actually exists
        if (transfer == NULL) {
            std::cout << "That item doesn't seem to exist in the backpack\n";
        } else {
            if (student->add(transfer)) {
                remove(transfer);
            }
        }
    }
    // Get an item pointer (another backpack proxy)
    Item* get_item(std::string name) {
        return backpack.find(name);
    }
    // Return a backpack for the copy constructor
    Backpack* get_backpack() {
        return &backpack;
    }
    // Another to string with attributes and backpack items
    std::string to_string() {
        return "student: " + name + "\nClass Rank: " + class_rank +
               "\nGender: " + gender + "\nCredits: " + std::to_string(credits) +
               "\nHeight: " + height + "\nItems: " + backpack.to_string() +
               "\n";
    }

  private:
    // Basic name
    std::string name;
    // Backpack object
    Backpack backpack;
    // Other attributes
    std::string gender;
    std::string class_rank;
    int credits;
    std::string height;
};

// Let's test it all out!
int main() {
    // Fun ASCII art that plays no computational role
    std::cout << " ██████╗ █████╗ ███╗   ███╗██████╗ ██╗   ██╗███████╗    "
                 "███████╗██╗███╗   ███╗\n██╔════╝██╔══██╗████╗ "
                 "████║██╔══██╗██║   ██║██╔════╝    ██╔════╝██║████╗ "
                 "████║\n██║     ███████║██╔████╔██║██████╔╝██║   ██║███████╗  "
                 "  ███████╗██║██╔████╔██║\n██║     ██╔══██║██║╚██╔╝██║██╔═══╝ "
                 "██║   ██║╚════██║    ╚════██║██║██║╚██╔╝██║\n╚██████╗██║  "
                 "██║██║ ╚═╝ ██║██║     ╚██████╔╝███████║    ███████║██║██║ "
                 "╚═╝ ██║\n ╚═════╝╚═╝  ╚═╝╚═╝     ╚═╝╚═╝      ╚═════╝ "
                 "╚══════╝    ╚══════╝╚═╝╚═╝     ╚═╝\n\n";

    // Create and print a student
    std::cout << "Let's make a student!\n";
    Student Ben{"Ben Bassett", "male", "freshman", 18, 100, "6' 0\""};
    std::cout << Ben.to_string() << "\n";

    // Create and print an item
    std::cout << "Create an item...\n";
    Item computer{"Computer", 2, true, false, "rectangular", "silver"};
    std::cout << computer.to_string() << "\n";

    // Add the item to a student, then reprint it
    std::cout << "Add the item to Ben\n";
    Ben.add(&computer);
    std::cout << Ben.to_string() << "\n";

    // Create and print a second student
    std::cout << "Another student enters the picture:\n";
    Student EvilBen{"Evil Ben", "male", "∞", 180, 100, "160' 0\""};
    std::cout << EvilBen.to_string() << "\n";

    // Give the computer
    Ben.give(&computer, &EvilBen);
    // Ben.give("Computer", &EvilBen); // This does the same thing
    std::cout << "Giving the computer to Evil Ben:\n";
    std::cout << Ben.to_string() << "\n";
    std::cout << EvilBen.to_string() << "\n";

    // Make a copy of the second student
    std::cout << "Copying Evil Ben:\n";
    Student EvilerBen{EvilBen};
    std::cout << EvilerBen.to_string() << "\n";

    // Remove item from the second student, then print the second student and
    // its copy
    std::cout << "Removing the computer from Evil Ben\n";
    EvilBen.remove(computer.get_name());
    std::cout << EvilBen.to_string() << "\n";
    std::cout << "The copy of Evil Ben with the computer still there:\n";
    std::cout << EvilerBen.to_string() << "\n";

    std::cout << "Let's print the computer in Evil Ben's copy:\n";
    std::cout << EvilerBen.get_item("Computer")->to_string();
}