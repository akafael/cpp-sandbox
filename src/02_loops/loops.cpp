#include <iostream>
#include <sstream>

/**
 * Example index for
 */
std::string loopFor() {
  std::stringstream ss;

  for (int i = 10; i > 0; i--) {
    ss << i << " ";
  }

  return ss.str();
}

/**
 * Example For each
 */
std::string loopForEach() {
  std::stringstream ss;

  const int list[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (int i : list) {
    ss << i << " ";
  }

  return ss.str();
}

int main() {
  std::cout << "for loop: " << loopFor() << std::endl;
  std::cout << "for loop each: " << loopForEach() << std::endl;
}