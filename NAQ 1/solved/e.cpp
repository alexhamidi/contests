#include <iostream>
#include <map>

using namespace std;


int main() {

    int n;
    cin >> n;
    int numRes = n * 10; //n * 10 results

    map<int, int> freqs;


    for (int i = 0; i < numRes; i++) {
        int n1, n2, n3, n4, n5;
        cin >> n1 >> n2 >> n3 >> n4 >> n5;
        freqs[n1]++;
        freqs[n2]++;
        freqs[n3]++;
        freqs[n4]++;
        freqs[n5]++;
    }

    string ans = "";

    for (auto it = freqs.begin(); it != freqs.end(); it++) {
        if (it->second > (n*2)) {
            ans += to_string(it->first) + " ";
        }

    }
    if (ans.empty()) {
        ans = "-1";
    } else {
        ans.pop_back();
    }
    cout << ans;
    return 0;
}



/*


flag any
*/
