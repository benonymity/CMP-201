#include <iostream>

int fibonacci(int n);
int fib(int n);

int main() {
  // O(n^2)
  int data[5]{18,4,74,79,53};
  for (int i = 0; i < 5; i++) {
    for (int j = i+ 1; j < 5; j++) {
      if (data[j] < data[i]) {
        int temp = data[j];
        data[j] = data[i];
        data[i] = temp;
      }
    }
  }
  for (int i = 0; i < 5; i++) {
    std::cout << data[i] << ", ";
  }
  std::cout << "\n\n";


  std::cout << fibonacci(40) << "\n";
  std::cout << fib(50) << "\n";

  // O(n^3)
  int N{10}; // Dimension of matrix
  for (int i = 0; i < N; i++) {
    for(int j = 0; j < N; i++) {
      for(int k = 0; k < N; k++) {
        // Matrix multiplication:
        // c[i][j] += A[i][k] + B[k][j];
        exit(1);
      }
    }
  }
}

// O(2^n)
// VERY BAD! This won't work at all
int fibonacci (int n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int fib(int n)
{
    int a = 0, b = 1, c, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}