// 2023 by Polevoi Dmitry
// source https://codeforces.com/problemset/problem/978/A

#include <array>
#include <iostream>

int main() {
  const int nMax = 50;
  std::array<int, nMax> a{0};
  int nInput = 0;
  std::cin >> nInput;
  for (int i = 0; i < nInput; i += 1) {
    std::cin >> a[i];
  }
  std::array<int, nMax> u{ 0 };
  int nUnique = 1;
  u[0] = a[nInput - 1];
  for (int iInp = nInput - 2; 0 <= iInp; iInp -= 1) {
    bool isUnique = true;
    for (int iUni = 0; isUnique && iUni < nUnique; iUni += 1) {
      if (u[iUni] == a[iInp]) {
        isUnique = false;
      }
    }
    if (isUnique) {
      u[nUnique] = a[iInp];
      nUnique += 1;
    }
  }
  std::cout << nUnique << '\n';
  for (int i = nUnique - 1; 0 <= i; i -= 1) {
    std::cout << u[i] << ' ';
  }
  return 0;
}
