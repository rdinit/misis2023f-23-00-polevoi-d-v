#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <cstdint>
#include <iosfwd>

class Rational {
  public:
    Rational() = default;
    Rational(const Rational&) = default;
    Rational(const std::int64_t num) noexcept : num_(num) { }
    Rational(const std::int64_t num, const std::int64_t den);
    ~Rational() = default;
    [[nodiscard]] Rational& operator=(const Rational&) = default;

    [[nodiscard]] std::int64_t num() const noexcept { return num_;  }
    [[nodiscard]] std::int64_t den() const noexcept { return den_; }

    [[nodiscard]] bool operator==(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator!=(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator<(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator<=(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator>(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator>=(const Rational& rhs) const noexcept;

    [[nodiscard]] Rational operator-() const noexcept { return {-num_, den_}; }

    Rational& operator+=(const Rational& rhs) noexcept;
    Rational& operator-=(const Rational& rhs) noexcept;
    Rational& operator*=(const Rational& rhs) noexcept;
    Rational& operator/=(const Rational& rhs);

  //! \brief Форматированный вывод в поток ostrm рационального числа в виде num/den.
  //!
  //! \param[in,out] ostrm - поток
  //! \retval поток
  [[nodiscard]] std::ostream& WriteTo(std::ostream& ostrm) const noexcept;

  //! \brief Форматированный ввод из потока istrm комплексного числа в виде num/den.
  //!
  //! \param[in,out] istrm - поток
  //! \retval поток
  [[nodiscard]] std::istream& ReadFrom(std::istream& istrm) noexcept;

private:
    std::int64_t num_ = 0; //!< числитель
    std::int64_t den_ = 1; //!< знаменатель, > 0
};

Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator/(const Rational& lhs, const Rational& rhs);

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept;

std::istream& operator>>(std::istream& ostrm, Rational& rhs) noexcept;



Rational::Rational(const std::int64_t num, const std::int64_t den)
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