#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const ll MOD = 1000000000 + 7;

vector<int> indices[26];
ll sums[26];
ll sums_squared[26];

int main(void) {
  string s;
  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    indices[s[i] - 'A'].push_back(i+1);
  }

  for (int i = 0; i < 26; i++) {
    ll sum = 0;
    ll sum2 = 0;
    for (ll x : indices[i]) {
      sum += x;
      sum2 += ((ll)x * x);
      sum %= MOD;
      sum2 %= MOD;
    }
    sums[i] = sum;
    sums_squared[i] = sum2;
  }

  ll ans = 0;
  for (int i = 0; i < 26; i++) {
    if (indices[i].size() == 0) continue;
    for (ll x : indices[i]) {
      for (int j = i+1; j < 26; j++) {
        ans += sums_squared[j] - ((2LL * (ll) x * sums[j]) % MOD) + indices[j].size() * (((ll)x * x) % MOD);
        ans %= MOD;
      }
    }
  }

  while (ans < 0) ans += MOD;
  cout << ans << endl;

  return 0;

}
