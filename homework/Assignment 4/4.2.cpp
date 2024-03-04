#include <iostream>

// Define the basic task element——basically a tuple with a fancy name
class Task {
  public:
    // Constructor
    Task(std::string Interrupt, int Priority) {
        interrupt = Interrupt;
        priority = Priority;
    }

    // Get value/"interrupt"
    std::string get_interrupt() {
        return interrupt;
    }

    // Get priority
    int get_priority() {
        return priority;
    }

  private:
    // Declare interrupt and priority
    std::string interrupt;
    int priority;
};

// Define the priority queue——basically a fancy vector
class PriorityQueue {
  public:
    // Useless constructor
    PriorityQueue() {
    }

    // Pop top task
    void pop() {
        values.erase(values.begin());
    }

    // Push a task to it's appropriate priority in the queue (if tie, priority
    // in time defines precedence)
    void push(Task item) {
        int priority = item.get_priority();
        // Empty vector case
        if (is_empty()) {
            values.push_back(item);
            // If it's the smallest priority, go first
        } else if (values[0].get_priority() > priority) {
            values.insert((values.begin()), item);
        } else {
            // Otherwise, iterate through until the priority is big enough
            for (int i = 0; i < values.size(); i++) {
                if (values[i].get_priority() > priority) {
                    values.insert((values.begin() + i), item);
                    return;
                }
            }
            // If that fails, go last
            values.push_back(item);
        }
    }

    // Return the next priority task (front of the vector)
    Task* next() {
        return &(values.front());
    }

    // Check if the vector is empty
    bool is_empty() {
        return values.empty();
    }

    // Clear the vector
    void clear() {
        values.clear();
    }

  private:
    std::vector<Task> values;
};

// Define the big interrupt handler
class InterruptHandler {
  public:
    // Useless constructor
    InterruptHandler() {
    }

    // Create and push a task onto the priority queue
    void poll(std::string task, int priority) {
        queue.push(Task{task, priority});
    }

    // Or do nothing if it's empty (for the "none" tasks)
    void poll() {
        return;
    }

    // Process the next priority task
    void process() {
        if (!queue.is_empty()) {
            std::cout << queue.next()->get_interrupt() << "\n";
            queue.pop();
        }
    }

    // Check if the priority queue is empty
    bool is_empty() {
        return queue.is_empty();
    }

  private:
    // Initialize the queue
    PriorityQueue queue;
};

// Main function
int main() {
    // Initialize the handler
    InterruptHandler handler;
    // Create the given list of interrupts
    std::tuple<std::string, int> interrupts[13]{
        std::make_tuple("timer1", 2),    std::make_tuple("timer2", 4),
        std::make_tuple("serial", 3),    std::make_tuple("", 0),
        std::make_tuple("external1", 2), std::make_tuple("timer1", 5),
        std::make_tuple("", 0),          std::make_tuple("external2", 3),
        std::make_tuple("serial", 1),    std::make_tuple("timer0", 3),
        std::make_tuple("", 0),          std::make_tuple("external1", 4),
        std::make_tuple("serial", 2)};

    // Fun ASCII art that plays no computational role
    std::cout << "  _____       _                             _     _    _     "
                 "            _ _           \n |_   _|     | |                 "
                 "          | |   | |  | |               | | |          \n   | "
                 "|  _ __ | |_ ___ _ __ _ __ _   _ _ __ | |_  | |__| | __ _ _ "
                 "__   __| | | ___ _ __ \n   | | | '_ \\| __/ _ \\ '__| '__| | "
                 "| | '_ \\| __| |  __  |/ _` | '_ \\ / _` | |/ _ \\ '__|\n  "
                 "_| |_| | | | ||  __/ |  | |  | |_| | |_) | |_  | |  | | (_| "
                 "| | | | (_| | |  __/ |   \n |_____|_| |_|\\__\\___|_|  |_|   "
                 "\\__,_| .__/ \\__| |_|  |_|\\__,_|_| |_|\\__,_|_|\\___|_|   "
                 "\n                                     | |                   "
                 "                            \n                               "
                 "      |_|                                               \n\n";

    // Iterate through the interrupts 2 at a time, then process once
    for (int i = 0; i < 13; i += 2) {
        // If it has a priority, poll it
        if (std::get<1>(interrupts[i])) {
            handler.poll(std::get<0>(interrupts[i]),
                         std::get<1>(interrupts[i]));
        } else {
            handler.poll();
        }
        // Same thing here
        if (std::get<1>(interrupts[i + 1])) {
            handler.poll(std::get<0>(interrupts[i + 1]),
                         std::get<1>(interrupts[i + 1]));
        } else {
            handler.poll();
        }
        // Process once
        handler.process();
    }
    // Then process everything left over
    while (!handler.is_empty()) {
        handler.process();
    }
}