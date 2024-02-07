#include <iostream>

using namespace std;

class Entity {
    public:
        Entity(){};
        Entity(int val){make(val);}
        Entity(const Entity& new_data) {
            data = new int;
            *data = *new_data.data;
        }
        ~Entity() {
            cout << "hey there!\n";
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


int main() {
    Entity a(4);
    Entity b{5};
    cout << a.get() << endl;
    b = a;;
    cout << b.get() << endl;
    b.set(7);
    cout << a.get() << endl;
}

void f() {
    Entity c{2};
    // deallocate to prevent memory leak
    c.release();
}