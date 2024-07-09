/**
 * Increment and Decrement operators overload
 */

#include <iostream>

class num {
    int value {};
public:
    num(int x = 0) : value{x} {}

    int getvalue() const { return value; }
    void setvalue(int x) { value = x; }
    operator int () { return value; }      ///< Implicity conversor to int

    num& operator++ ();    //
    num operator++ (int);
    num& operator-- ();
    num operator-- (int);
};


// pre-increment
num& num::operator++ () {
    std::cout << "pre-increment: " << std::endl;
    value += 1;
    return *this;
}

// post-increment
num num::operator++ (int) {
    std::cout << "post-increment: " << std::endl;
    auto temp = *this;
    value += 1;
    return temp;
}

// pre-decrement
num& num::operator-- () {
    std::cout << "pre-decrement: " << std::endl;
    value -= 1;
    return *this;
}

// post-decrement
num num::operator-- (int) {
    std::cout << "post-decrement: " << std::endl;
    auto temp = *this;
    value -= 1;
    return temp;
}

int main() {
    num n(42);

    std::cout << "value is: " << n << std::endl;
    std::cout << "value is: " << n++ << std::endl;
    std::cout << "value is: " << n << std::endl;

    return 0;
}