#include <cmath>
#include <iostream>

// Define the math processor
class Mathy {
  public:
    // Useless initializer
    Mathy() {
    }

    // Execution function from string
    int execute(std::string exec) {
        // Filter the string
        if (exec.find("push") == 0) {
            // Strip away "push " to get the int
            exec.erase(0, 5);
            push(std::stoi(exec));
        } else if (exec == "pop") {
            return pop();
        } else if (exec == "peek") {
            return peek();
        } else if (exec == "+") {
            add();
        } else if (exec == "-") {
            subtract();
        } else if (exec == "*") {
            multiply();
        } else if (exec == "/") {
            divide();
        } else if (exec == "sin") {
            sin();
        } else if (exec == "sincos") {
            sincos();
        } else if (exec == "sqrt") {
            sqrt();
        }
        // To fulfill int return
        return 0;
    }

    // Convert the stack to a string
    std::string to_string() {
        std::string result;
        for (int i = 0; i < stack.size(); i++) {
            result += std::to_string(stack[i]);
            if (i < (stack.size() - 1)) {
                result += ", ";
            }
        }
        result += "\n";
        return result;
    }

  private:
    // Declare the stack
    std::vector<int> stack;

    // Add to the top of the stack
    void push(int n) {
        stack.push_back(n);
    }

    // Reutrn the top item from the stack
    int peek() {
        if (is_empty()) {
            return 0;
        }
        return stack.back();
    }

    // Remove the top item from the stack
    int pop() {
        if (is_empty()) {
            return 0;
        }
        int top = peek();
        stack.pop_back();
        return top;
    }

    // Check whether the stack is empty
    bool is_empty() {
        return stack.empty();
    }

    // Add top two nubmers
    void add() {
        // Make sure there are enough items
        if (stack.size() < 2) {
            std::cout << "Not enough elements present for addition\n";
            return;
        }
        // Pop top two and replace with their sum
        int sum = peek() + (stack.end()[-2]);
        pop();
        pop();
        push(sum);
    }

    // Subtract the top two numbers
    void subtract() {
        // Make sure there are enough items
        if (stack.size() < 2) {
            std::cout << "Not enough elements present for subtraction\n";
            return;
        }
        // Pop top two and replace with their difference
        int difference = peek() - (stack.end()[-2]);
        pop();
        pop();
        push(difference);
    }

    // Multiply the top two numbers
    void multiply() {
        // Make sure there are enough items
        if (stack.size() < 2) {
            std::cout << "Not enough elements present for multiplication\n";
            return;
        }
        // Pop top two items and replace with their product
        int product = peek() * (stack.end()[-2]);
        pop();
        pop();
        push(product);
    }

    // Divide the top two numbers
    void divide() {
        // Make sure there are enough items
        if (stack.size() < 2) {
            std::cout << "Not enough elements present for division\n";
            return;
        }
        // Make sure there won't be a division by zero scenario
        if (stack.end()[-2] == 0) {
            std::cout << "Division by zero isn't permitted\n";
            return;
        }
        // Find the quotient and remainder, then replace the top two
        int quotient = peek() / stack.end()[-2];
        int remainder = peek() % (stack.end()[-2]);
        pop();
        pop();
        push(quotient);
        push(remainder);
    }

    // Get the sin of the top number
    void sin() {
        // Make sure there are enough items
        if (is_empty()) {
            std::cout << "Not enough elements present for the sine function\n";
            return;
        }
        int top = peek();
        pop();
        push(std::sin(top));
    }

    // Get the cosine of the top number
    void cos() {
        // Make sure there are enough items
        if (is_empty()) {
            std::cout
                << "Not enough elements present for the cosine function\n";
            return;
        }
        int top = peek();
        pop();
        push(std::cos(top));
    }

    // Get the cosine of the top number and sine of the second
    void sincos() {
        // Make sure there are enough items
        if (stack.size() < 2) {
            std::cout << "Not enough elements present for the sine and cosine "
                         "functions\n";
            return;
        }
        // Replace with sine and cosine
        int top = int(peek());
        int second = int(stack.end()[-2]);
        pop();
        pop();
        push(int(std::sin(second)));
        push(int(std::cos(top)));
    }

    // Get the square root of the top number
    void sqrt() {
        // Make sure there are enough items
        if (is_empty()) {
            std::cout
                << "Not enough elements present for the square root function\n";
            return;
        }
        // Replace top with square root
        int top = peek();
        pop();
        push(std::sqrt(top));
    }
};

// Main function
int main() {
    // Initialize processor
    Mathy math;
    // Demonstratory instruction set
    std::string instructions[18]{
        "push 1", "push 2", "push 3", "push 4", "push 5", "push 6",
        "push 7", "push 8", "push 9", "pop",    "peek",   "+",
        "-",      "*",      "sqrt",   "/",      "sin",    "sincos"};

    // Fun ASCII art that plays no computational role
    std::cout << " ____    ____       _     _________  ____  ____  ____  ____  "
                 "\n|_   \\  /   _|     / \\   |  _   _  ||_   ||   _||_  _||_ "
                 " _| \n  |   \\/   |      / _ \\  |_/ | | \\_|  | |__| |    "
                 "\\ \\  / /   \n  | |\\  /| |     / ___ \\     | |      |  __ "
                 " |     \\ \\/ /    \n _| |_\\/_| |_  _/ /   \\ \\_  _| |_    "
                 "_| |  | |_    _|  |_    \n|_____||_____||____| |____||_____| "
                 " |____||____|  |______|   \n\n";

    int out;
    // Iterate through instructions
    for (std::string instruction : instructions) {
        // Execute each one
        out = math.execute(instruction);
        // Print the instuction and it's effect on the coprocessor
        std::cout << instruction << ": " << math.to_string();
        // If there's valuable returned, print it
        if (out != 0) {
            std::cout << out << "\n";
        }
    }

    // Reset the processor
    math = Mathy{};
    std::cout << "\nQUADRATIC FORMULA IMPLEMENTATION\n\n";
    // The quadratic formula: a = 2, b = 5, c = 2
    // (-5 ± \sqrt{5^2 - 4•2•2})/(2•2)
    // Weird order of operations, but if you think about it enough it works
    std::string instructions2[18]{
        "push 2", "push 2",  "*",      "push 4", "push 2", "*",
        "push 2", "*",       "push 5", "push 5", "*",      "-",
        "sqrt",   "push -5", "-",      "/",      "pop",    "peek"};
    // We could also solve for 0.5, but this is a demonstration of one of the
    // roots
    // See above, more iteration and execution
    for (std::string instruction : instructions2) {
        out = math.execute(instruction);
        std::cout << instruction << ": " << math.to_string();
        if (out != 0) {
            std::cout << out << "\n";
        }
    }
}