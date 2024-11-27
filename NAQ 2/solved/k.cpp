#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int cp(int c) {
    return min(c, 10);
}
//wrong - need to consider the fact that there are only 4 of each card
int main() {
    int n;
    cin >> n;


    vector<int> amountLeft(14, 4);

    int j1, j2;
    cin >> j1 >> j2;

    amountLeft[j1]--;
    amountLeft[j2]--;

    int jtp = cp(j1)+cp(j2);



    int m1, m2;
    cin >> m1 >> m2;

    amountLeft[m1]--;
    amountLeft[m2]--;

    int mtp = cp(m1)+cp(m2);

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;

        amountLeft[c]--;

        jtp+=cp(c);
        mtp+=cp(c);

    }


    //at this point, we have the cumulative total of the amount of each card that is left.
    //enumerate all the possibilites

    for (int i = 1; i <= 13; i++) if (amountLeft[i] > 0) {

        if ((mtp+cp(i)==23) || (jtp+cp(i)>23 && mtp+cp(i) < 23)) {
            cout << i;
            return 0;
        }

    }


    cout << -1;
    return 0;
}


/*
two values: minimum to make jake bust if j is higher, and minimum to hit 23 if mary is lower.


lowest: either win or otherbust.




1. All cards are placed in a stack and each player recieves two cards
2. A card is taken from the stack and set face up. this card counts for all players.
3. If a player busts, they leave the game. If a player wins or is the only one left, they win the game
4. repeat #3 until there is a winner.

note: there may be more than one winner (if more than one add up to 23) or zero winners (if everyone busts).

problem: determine the lowest value of a card to be taken for mary to win the game, or -1 if she cannot with the game in the next hand.



just add common cards to their things





game - 23

variation of blacck

4 cards of each value


picture: 10pts
ace: 1pt


player with the most points wins as long as it is not higher than 23.

we get the number of rounds played

j represented by 11, q represents by 12, k represented by 13, but this is not their points.

*/
