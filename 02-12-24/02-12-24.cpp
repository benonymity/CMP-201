#include <iostream>
#include <list>

template<typename T>
class Node {
    public:
        Node(const T& value): data{value}, next(NULL) {}
        // Node(const T& value, const pointer): data{value}, next(NULL) {}
    private:
        T data;
        Node<T> next;
};

template<typename T>
class List {
    public:
        List(): first{NULL}, last{NULL} {}

        bool is_empty() {
            if (first | last) {
                return true;
            }
            return false;
        }

        void push_front(const T&) {
            Node<T>* new_node = new Node<T>{item};
            if (is_empty()) {
                first = new_node;
                last = new_node;
            } else {
                new_node->next = first;
                first = new_node;
            }
        }
    private:
        Node<T>* first;
        Node<T>* last;
};

int main() {
    List<int> data;
}