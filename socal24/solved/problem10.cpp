#include <iostream>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
      int x1, y1, x2, y2, x3, y3, x4, y4;
      cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

      int ABx = x2 - x1;
      int ABy = y2 - y1;
      int ACx = x3 - x1;
      int ACy = y3 - y1;
      int ADx = x4 - x1;
      int ADy = y4 - y1;

      if ((ABx * ACy - ABy * ACx) == 0 && (ABx * ADy - ABy * ADx) == 0) {
        cout << "No" << endl;
      } else {
         cout << "Yes" << endl;
      }
  }
  return 0;
}