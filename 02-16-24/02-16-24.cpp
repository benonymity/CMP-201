#include <iostream>
#include <list>

template <typename T> class List;

template <typename T> class Node {
    friend class List<T>;

  public:
    Node(const T& value)
        : data(value), next(NULL) {
    }
    // Node(const T& value, const pointer): data{value}, next(NULL) {}

    void set_next(Node<T>* item) {
        next = item;
    }

    Node<T>* get_next() {
        return next;
    }

  private:
    T data;
    Node<T>* next;
};

template <typename T> class List {
  public:
    List()
        : first(NULL),
          last(NULL) 

    ~List() {
      while(!is_empty()) {
        pop_front()
      }
    }

              bool is_empty() const {
        return !(first || last);
    }

    void print() const {
        Node<T>* curr = first;
        while (curr != NULL) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    void push_front(const T& item) {
        Node<T>* new_node = new Node<T>{item};
        if (is_empty()) {
            first = new_node;
            last = new_node;
        } else {
            new_node->set_next(first);
            first = new_node;
        }
    }

    void push_back(const T& item) {
        if (is_empty()) {
            push_front(item);
        } else {
            Node<T>* new_node = new Node<T>{item};
            last->next = new_node;
            last = new_node;
        }
    }

    void pop_front() {
        Node<T>* temp = first;
        if (first == last) {
            first = NULL;
            last = NULL;
        } else {
            first = first->get_next();
        }
        delete temp;
    }

    void pop_back() {
        if (first == last) {
            pop_front()
        } else {
            Node<T>* iter = first;
            while (iter->next != last) {
                iter = iter->next;
            }
            delete last;
            iter->next = NULL;
            last = iter;
            delete iter;
        }
    }

  private:
    Node<T>* first;
    Node<T>* last;
};

int main() {
    List<int> data;
    data.push_front(4);
    data.push_back(1);
    data.push_front(3);
    data.push_back(7);
    data.pop_front();
    data.pop_back();
    data.print();
}
