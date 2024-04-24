#include <iostream>
#include <vector>
#include <memory>
#include <string>

int* ptr_factory(int x) {
    return new int (x);
}

void ptr_use_factory(int x) {
    int* p = ptr_factory(x);
    // Use the pointer but don't delete it

} // p goes out of scope but is not deallocated

std::shared_ptr<int> factory(int x) {
    return std::make_shared<int>(x);
}

void use_factory(int x) {
    std::shared_ptr<int> p = factory(x);
    // Use the pointer but don't delete it
} // p goes out of scope, and memory is automatically deleted

std::unique_ptr<int> process_u(int x) {
    std::unique_ptr<int> ret(new int(x));
    // Use the pointer
    return ret;
}

int main() {
    std::shared_ptr<std::string> p1;
    p1 = std::make_shared<std::string>("dinner is soon");
    std::cout << *p1 << std::endl;
}