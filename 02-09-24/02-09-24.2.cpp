#include <iostream>

// Apparantly I'm not supposed to use this anymore
// using namespace std;

class Entity {
    public:
        Entity(){};
        Entity(int val){make(val);}
        Entity(const Entity& new_data) {
            data = new int;
            *data = *new_data.data;
        }
        ~Entity() {
            std::cout << "hey there!\n";
        }

        void make(int val) {
            data = new int;
            *data = val;
        }

        void set(int val) const {
            *data = val;
        }

        int get() const {
            return *data;
        }

        void release() {
            delete data;
        }

        void operator=(const Entity& new_data) {
            *this->data = *new_data.data;
        }

    private:
        int* data;
};

template <class T>
class Cell {
    public:
        Cell(): data{} {}
        Cell(T val): data{val} {}

        T get_data() const {
            return data;
        }

        void set_data(T val) {
            data = val;
        }
    private:
        T data;
};


int main() {
    Entity a(4);
    Entity b{5};
    std::cout << a.get() << std::endl;
    b = a;;
    std::cout << b.get() << std::endl;
    b.set(7);
    std::cout << a.get() << std::endl;

    Cell<int> c{9};
    Cell<Entity> c{b};
}

void f() {
    Entity c{2};
    // deallocate to prevent memory leak
    c.release();
}