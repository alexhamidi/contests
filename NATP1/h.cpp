

#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

struct node {
    int label;
    int parent;
    set<int> children;
};

node* cities[200010];
bool reachable[200010];

void set_unreachable(int n) {
    node* curr = cities[n];
    reachable[n] = false;
    if (curr->children.empty()) {
        return;
    }
    for (int child: curr->children) {
        set_unreachable(child);
    }

}



int main() {
    memset(reachable, 1, sizeof(reachable));


    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cities[i] = new node;
        cities[i]->label = i;
        cities[i]->parent = 0;
    }

    //construct graphs
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        cities[a]->children.insert(b);
        cities[b]->parent = a;
    }

    int ans = 0;

    for (int i = 0; i < m; i++) {
        int dest;
        cin >> dest;

        if (reachable[dest]) {
            ans++;
            continue;
        }

        if (!reachable[dest]) {
            break;
        }

        int curr = dest;

        int iterations = 0;

        bool startReached = false;

        while (!startReached) {
            if (iterations > (n + 10)) {
                exit(1);
            }
            if (curr == 1) {
                startReached = true;
                continue;
            }
            int parent = cities[curr]->parent;

            if (parent == 0) {
                break;
            } else {
                set<int> prevChildren = cities[parent]->children;
                for (int child : prevChildren) {
                    if (child < curr) {
                        cities[parent]->children.erase(child);
                        cities[child]->parent = 0;
                        set_unreachable(child);

                    }
                }
            }
            curr = parent;
            iterations++;
        }
        if (!startReached) {
            break;
        } else {
            ans++;
        }
    }

    cout << ans;

    return 0;
}


/*



*/
