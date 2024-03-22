#include <iostream>
#include <string>
#include <vector>

int main() {
    int val{5};
    int n{10};
    std::vector<int> v1;         // default
    std::vector<int> v2(v1);     // copy
    std::vector<int> v3{v1};     // copy
    std::vector<int> v4{n, val}; // create vector with n elements of value val
    std::vector<int> v5{n};      // create with n elements of default values (0)
    std::vector<int> v6{3, 2, 1}; // initializer list

    // note that
    std::vector<int> v7(10, 2);
    // is very different from
    std::vector<int> v8{10, 2};

    // add elements with push_back
    v1.push_back(5);

    // An iterator is general way to access elements of a container. Like
    // pointers, they give us indirect access to elements
    std::vector<int>::iterator iter_b = v1.begin();
    std::vector<int>::iterator iter_e = v1.end();

    std::vector<int>::const_iterator c_iter = v1.cbegin();

    // new, and very awesome, keyword!
    auto b = v1.cbegin();
    auto y{5};
    auto z{6.7};

    std::string s{"some string"};
    auto it = s.begin();
    *it = toupper(*it);
}
