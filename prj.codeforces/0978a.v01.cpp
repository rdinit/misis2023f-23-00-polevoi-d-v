// 2023 by Polevoi Dmitry
// source https://codeforces.com/problemset/problem/978/A
 
#include <iostream>
#include <vector>

int main() {
  std::vector<int> c(1001, 0);
  int nUnique = 0;
  int nInput = 0;
  std::cin >> nInput;
  std::vector<int> a(nInput, 0);
  for (int i = 0; i < nInput; i += 1) {
    std::cin >> a[i];
    nUnique += 0 == c[a[i]] ? 1 : 0;
    c[a[i]] += 1;
  }
  std::cout << nUnique << '\n';
  for (int i = 0; i < a.size(); i += 1) {
    if (1 == c[a[i]]) {
      std::cout << a[i] << ' ';
    } else {
      c[a[i]] -= 1;
    }
  }
  return 0;
}