#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
      int n;
      cin >> n;
      vector<int> A(n);
      for (auto& a : A) cin >> a;
      set<int> ans;
      for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                  ans.insert(A[i]+A[j]);
              }

        }
    int total = (n*(n-1))/2;
    int distinct = ans.size();
    cout << total << " " << distinct << "\n";


    return 0;
}