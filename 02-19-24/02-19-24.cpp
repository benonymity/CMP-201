#include <iostream>
#include <string>

int main() {
  int x = 4;
  std::cout << &x << " - " << x << "\n";
  std::string y = "Hillsdale";
  std::cout << &y << " - " << y << "\n";
}