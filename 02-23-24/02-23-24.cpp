#include <iostream>

int main() {
  int data[5] {3,1,6,4,8};
  for(int* p = data; p < (data+5); p++) {
    std::cout << *p;
  }
}