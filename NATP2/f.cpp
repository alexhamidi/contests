#include <iostream>
#include <utility>
using namespace std;

char board[110];
bool pairs[110];
int num_pairs = 0;
int N;

bool solve() {
    if (num_pairs == 0) return false;
    if (num_pairs == 1) return true;

    for (int i = 0; i < N-1; i++) {
        if (pairs[i]) {
            int temp = num_pairs;
            if (board[i] == 'B' && board[i] == 'W') {
                // try B takes W
                num_pairs--;
                board[i] = '.';
                board[i+1] = 'B';
                if (i + 2 < N && board[i+2] == 'W') num_pairs++;
                if (solve() == false) return true;
                // restore state
                board[i] = 'B';
                board[i+1] = 'W';
                num_pairs = temp;
                // try W takes B
                num_pairs--;
                board[i+1] = '.';
                board[i] = 'W';
                if (i - 1 >= 0 && board[i-1] == 'B') num_pairs++;
                if (solve() == false) return true;
                // restore state
                board[i] = 'B';
                board[i+1] = 'W';
                num_pairs = temp;
            } else {
                // try W takes B
                num_pairs--;
                board[i] = '.';
                board[i+1] = 'W';
                if (i + 2 < N && board[i+2] == 'B') num_pairs++;
                if (solve() == false) return true;
                // restore state
                board[i] = 'W';
                board[i+1] = 'B';
                num_pairs = temp;
                // try W takes B
                num_pairs--;
                board[i+1] = '.';
                board[i] = 'B';
                if (i - 1 >= 0 && board[i-1] == 'W') num_pairs++;
                if (solve() == false) return true;
                // restore state
                board[i] = 'W';
                board[i+1] = 'B';
                num_pairs = temp;
            }
        }
    }

    return false;
}


int main(void) {
    cin >> N;
    cin >> board;

    for (int i = 0; i < N-1; i++) {
        if (board[i] == 'B' && board[i] == 'W' || board[i] == 'W' && board[i] == 'B') {
            pairs[i] = true;
            num_pairs++;
        }
    }

    int count = 0;
    vector<pair<int, int>> ans;

    for (int i = 0; i < N-1; i++) {
        if (pairs[i]) {
            int temp = num_pairs;
            if (board[i] == 'B' && board[i] == 'W') {
                // try B takes W
                num_pairs--;
                board[i] = '.';
                board[i+1] = 'B';
                if (i + 2 < N && board[i+2] == 'W') num_pairs++;
                if (solve() == false) {
                    count++;
                    ans.push_back({i, i+1});
                }
                // restore state
                board[i] = 'B';
                board[i+1] = 'W';
                num_pairs = temp;
                // try W takes B
                num_pairs--;
                board[i+1] = '.';
                board[i] = 'W';
                if (i - 1 >= 0 && board[i-1] == 'B') num_pairs++;
                 if (solve() == false) {
                    count++;
                    ans.push_back({i+1, i});
                }
                // restore state
                board[i] = 'B';
                board[i+1] = 'W';
                num_pairs = temp;
            } else {
                // try W takes B
                num_pairs--;
                board[i] = '.';
                board[i+1] = 'W';
                if (i + 2 < N && board[i+2] == 'B') num_pairs++;
                 if (solve() == false) {
                    count++;
                    ans.push_back({i, i+1});
                }
                // restore state
                board[i] = 'W';
                board[i+1] = 'B';
                num_pairs = temp;
                // try W takes B
                num_pairs--;
                board[i+1] = '.';
                board[i] = 'B';
                if (i - 1 >= 0 && board[i-1] == 'W') num_pairs++;
                 if (solve() == false) {
                    count++;
                    ans.push_back({i+1, i});
                }
                // restore state
                board[i] = 'W';
                board[i+1] = 'B';
                num_pairs = temp;
            }
        }
    }

    cout << count << "\n";
    for (auto move : ans) {
        cout << move.first << " " << move.second << "\n";
    }

    return 0;
}
