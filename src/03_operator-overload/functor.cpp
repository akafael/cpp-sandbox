/**
 * Functor
 */

#include <iostream>

class MultBy {
  int mult{};

public:
  MultBy(int n = 1) : mult(n) {}

  /**
   * Overloard () operator
   */
  int operator()(int n) const { return mult * n; }
};

int main() {
  const MultBy times4(4); // Constructor call

  std::cout << "time4(5) = " << times4(5) // Functor
            << std::endl;
}