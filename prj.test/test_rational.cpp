#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <cstdint>

class Rational {
  public:
    Rational(const int64_t num = 0, const int64_t den = 1);
    int64_t num() const { return num_;  }
    int64_t den() const { return den_; }
private:
    int64_t num_ = 0;
    int64_t den_ = 1;
};

Rational::Rational(const int64_t num, const int64_t den)
  : num_(num), den_(den) {
  if (0 == den_) {
    throw std::invalid_argument("Zero denumenator in Rational ctor");
  }
}

TEST_CASE("rational ctor") {
  Rational r_def;
  CHECK(0 == r_def.num());
  CHECK(1 == r_def.den());

  Rational r_int(3);
  CHECK(3 == r_int.num());
  CHECK(1 == r_int.den());

  CHECK_THROWS(Rational(1, 0));
}