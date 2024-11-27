#include <iostream>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int>(m));

    for (auto& v : A) for (auto& a : v) cin >> a;





    return 0;
}

/*



ones are only used to connect



are connected, can do a bfs dp

any two cells can be nonconnected, so if there is more than one zero the answer is zero
*/

//want to know, but dont think i do
