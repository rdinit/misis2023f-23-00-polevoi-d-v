// 2022 by Polevoi Dmitry

#include <iostream>

int main() {
  int w = 0; // вес арбуза
  std::cin >> w;
  if (0 == w % 2 && 2 < w) {
    // w представимо в виде суммы двух четных отличных от нуля чисел
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
}
