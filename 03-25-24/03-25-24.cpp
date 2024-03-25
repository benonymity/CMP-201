#include <iostream>
#include <map>
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
    // data[i] equiv to *(data + i)

    std::map<std::string, std::string> planananananents;
    planananananents["Mercury"] = "Hot planet";
    planananananents["Venus"] = "Atmosphere of sulfuric acid";
    planananananents["Earth"] = "Home";
    planananananents["Mars"] = "The red planet";
    planananananents["Jupiter"] = "Big red spot 🔴";
    planananananents["Saturn"] = "Rings (of power)";
    planananananents["Uranus"] = "We don't talk about this one";
    planananananents["Neptune"] = "Pretty chilly";
    planananananents["Pluto"] = "Yes";

    std::cout << "Jupiter: " << planananananents["Jupiter"] << "\n";

    if (planananananents.find("Pluto") != planananananents.end()) {
        std::cout << "Pluto is in the map.\n\n";
    }

    // for (std;:pair<std::string, std::string> p : planananananents) {
    for (auto p : planananananents) {
        std::cout << p.first << ": " << p.second << "\n";
    }

    /* map template class

    map <KeyType, T>

    m.insert(Element) // insert element into map. element is of type
                      // Pair<KeyType, T>. return a value f pair<iterator,
                      // bool>.
    m.erase(key)
    m.find(key)
    m[Key]            // Returns a reference to the object associated with
                      // Key. If the map does not already contain Key, then a
                      // default tobject of type T is inserted

    m.size()
    m.empty()
    m1 == m2

    pair type is in #include <utility>
    */
