// Copyright 2022 by Polevoy Dmitry under Free Public License 1.0.0
// source https://codeforces.com/problemset/problem/1872/A

#include <cmath>
#include <iostream>
#include <limits>

int main() { 
  int t = 0;
  for (std::cin >> t; 0 < t; t -= 1) {
    int a = 0;
    int b = 0;
    int c = 0;
    std::cin >> a >> b >> c;
    const int d = std::abs(a - b);
    int count = 0;
    if (0 < d) {
      count = static_cast<int>(0.5 * d / c);
      const double dif = d - 2 * count * c;
      if (std::numeric_limits<double>::epsilon() < dif) {
        count += 1;
      }
    }
    std::cout << count << std::endl;
  }
}