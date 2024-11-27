#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<string> mins;
set<string> seen;

void help( vector<string> A) {
  string memo = "";
  sort(A.begin(), A.end());
  for (auto item : A) memo += (item + " ");
  if (seen.count(memo)) {
     return;
  }
  seen.insert(memo);
  int n = A.size();
  if (n == 1) {
    mins.push_back(A[0]);
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      //first test post a, pre b;
      string a = A[i];
      string b = A[j];
      int m = min(a.size(), b.size());
      for (int k = 0; k < m; k++) {
          string currA = a.substr(a.size()-1-k);
          string currB = b.substr(0, k+1);
          cout << ".";
          if (currA == currB) {
            vector<string>  temp = A;
            if (i < j) {
               temp.erase(temp.begin()+j);
               temp.erase(temp.begin()+i);
            } else {
              temp.erase(temp.begin()+i);
              temp.erase(temp.begin()+j);
            }
            string merged = a.substr(0, a.size()-k-1) + b;
            temp.push_back(merged);
            help(temp);
         }
      }
    }
  }
}
