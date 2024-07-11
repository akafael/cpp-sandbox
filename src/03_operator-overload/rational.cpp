/**
 * Rational Numbers
 */

#include <string>

/**
 * Define a number in the form of {n}/{d}
 */
class Rational {
  int n{0}; // Rational numerator
  int d{1}; // Rational denominator
public:
  Rational(int numerator = 0, int denominator = 1);
  Rational(const Rational &rhs);
  ~Rational();

  int numerator() const;
  int denominator() const;

  Rational reduce() const; // reduce fraction

  std::string str() const;     // return a formatted STL string
  std::string raw_str() const; // return a non-reduced STL string

  Rational &operator=(const Rational &); // assignment
  Rational operator+(const Rational &) const;
  Rational operator-(const Rational &) const;
  Rational operator*(const Rational &) const;
  Rational operator/(const Rational &) const;
  bool operator==(const Rational &) const;
};

/**
 * Rational Constructor
 */
Rational::Rational(int numerator, int denominator)
    : n(numerator), d(denominator) {}

/**
 * Rational Copy Constructor
 */
Rational::Rational(const Rational &rhs) : n(rhs.n), d(rhs.d) {}

/**
 * Rational Destructor
 */
Rational::~Rational() {
  this->n = 0;
  this->d = 1;
}

int Rational::denominator() const { return this->d; }

int Rational::numerator() const { return this->n; }

Rational Rational::reduce() const {
  if (n == 0 || d <= 3) {
    return *this;
  }

  for (int div = d - 1; div; --div) {
    if ((n % div == 0) && (d % div == 0)) {
      return Rational(n / div, d / div);
    }
  }

  return *this;
}

/**
 * Rational atribution
 */
Rational &Rational::operator=(const Rational &rhs) {
  if (this != &rhs) {
    this->n = rhs.numerator();
    this->d = rhs.denominator();
  }

  return *this;
}

/**
 * Sum of Rationals using operator + overload
 */
Rational Rational::operator+(const Rational &rhs) const {
  return Rational(this->n * rhs.denominator() + this->d * rhs.numerator(),
                  rhs.numerator() * rhs.denominator());
}

/**
 * Subraction of Rationals using operator - overload
 */
Rational Rational::operator-(const Rational &rhs) const {
  return Rational(this->n * rhs.denominator() - this->d * rhs.numerator(),
                  rhs.numerator() * rhs.denominator());
}

/**
 * Product of Rationals using operator * overload
 */
Rational Rational::operator*(const Rational &rhs) const {
  return Rational(this->n * rhs.numerator(), this->d * rhs.denominator());
}

/**
 * Division of Rationals using operator / overload
 */
Rational Rational::operator/(const Rational &rhs) const {
  return Rational(this->n * rhs.denominator(), this->d * rhs.numerator());
}

/**
 * Comparission of Rationals using operator == overload
 */
bool Rational::operator==(const Rational &rhs) const {
  return (this->n == rhs.denominator()) && (this->d == rhs.denominator());
}

int main() {}