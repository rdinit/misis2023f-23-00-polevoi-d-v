// Copyright 2022 by Polevoy Dmitry under Free Public License 1.0.0
// task source https://codeforces.com/problemset/problem/1721/B

#include <iostream>
#include <cmath>

bool isDestructed(
  const int iRow, const int iCol,
  const int sx, const int sy, const int d
) {
  return std::abs(iRow - sx) + std::abs(iCol - sy) <= d;
}

void printField(const int n, const int m, const int sx, const int sy, const int d) {
  for (int iRow = 1; iRow <= n; iRow += 1) {
    for (int iCol = 1; iCol <= m; iCol += 1) {
      char type = '.';
      if (sx == iRow && sy == iCol) {
        // лазер
        type = '*';
      } else if (isDestructed(iRow, iCol, sx, sy, d)) {
        // зона поражения
        type = '@';
      }
      std::cout << type;
    }
    std::cout << '\n';
  }
}

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i += 1) {
    int n = 0;  // количество строк
    int m = 0;  // количество столбцов
    int sx = 0; // номер строки
    int sy = 0; // номер столбца
    int d = 0;
    std::cin >> n >> m >> sx >> sy >> d;
    //printField(n, m, sx, sy, d);
    // финиш не накрыт лазером
    bool canGetToTheCorner = !isDestructed(n, m, sx, sy, d);
    // есть проход
    bool hasPath = !isDestructed(1, sy, sx, sy, d) && !isDestructed(sx, m, sx, sy, d);
    hasPath = hasPath || !isDestructed(sx, 1, sx, sy, d) && !isDestructed(n, sy, sx, sy, d);
    canGetToTheCorner = canGetToTheCorner && hasPath;
    // печать ответа
    std::cout << (canGetToTheCorner ? n + m - 2 : -1) << std::endl;
  }
}
