#include <iostream>
#include <climits>
#include <string>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main () {


    int s;
    cin >> s;

    set<pair<int, int>> wumpi;
    string out;

    while (wumpi.size() < 4) {
        s = s + (s/13) + 15;
        int ones = s%10;
        int tens = (s%100 - ones)/10;
        wumpi.insert({tens, ones});
    }

    int guesses = 0;
    int wleft = 4;

    vector<vector<int>> killed(10, vector<int>(10));
    string guess;
    while (wleft > 0) {
        string guess;
        cin >> guess;
        if (guess.size() == 2) {
            int x = guess[0] - '0';
            int y = guess[1] - '0';
            guesses++;
            for (auto [wx, wy] : wumpi) if (!killed[wx][wy]) {
                if (wx == x && wy == y) {
                    wleft--;
                    out += "You hit a wumpus!\n";
                    killed[wx][wy] = 1;
                }
            }
            if (wleft > 0) {
                int minMan = INT_MAX;
                for (auto [wx, wy] : wumpi) if (!killed[wx][wy]) {
                    int currMan = (abs(wx-x)+abs(wy-y));
                    minMan = min(minMan, currMan);
                }
                out += to_string(minMan) + "\n";
            }
        } else break;
    }
    cout << out << "Your score is " << guesses << " moves.";
}



/*



    two wampuses on the grid

at most 250 guesses
    need to capture al wumpusues


    guess a square by entering the coordinates

    manhatten distane between your guess and the closes wupus is returned


    pesudorandom number generated

    can determine the generator


    locations of four wumpuses
*/
