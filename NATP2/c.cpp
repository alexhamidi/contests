#include <iostream>
#include <vector>


using namespace std;


struct Node {
    vector<int> p;
    Node* children[2];
};

int main() {



    int n, m, q;
    cin >> n >> m >> q;


    vector<string> A(n);  //n x m

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    Node* root = new Node;
    root->children[0] = nullptr;
    root->children[1] = nullptr;
    for (int i = 0; i < n; i++) {
        root->p.push_back(i);
    }

    for (int i = 0; i < n; i++) {
        string s = A[i];
        Node* it = root;
        for (int j = 0; j < m; j++) {
            if (it->children[s[j] == 'Y'] == nullptr) {
                Node* temp = new Node;
                temp->children[0] = nullptr;
                temp->children[1] = nullptr;
                it->children[s[j] == 'Y'] = temp;
            }
            it = it->children[s[j] == 'Y'];
            it->p.push_back(i);
        }
    }

    // vector<int> temp = root->children[0]->p;


    vector<char> target(m, '*');

    for (int i = 0; i < q; i++) {
        int idx;
        char val;
        cin >> idx;
        cin >> val;

        target[idx-1] = val;
    }

    vector<Node*> prevs;
    prevs.push_back(root);

    for (int i = 0; i < m; i++) {
        char c = target[i];
        vector<Node*> nextNodes;

        for (Node* n : prevs) {
            if (c == '*' || c == 'N') {
                if (n->children[0] != nullptr) {
                    nextNodes.push_back(n->children[0]);
                }
            }
            if (c == '*' || c == 'Y') {
                if (n->children[1] != nullptr) {
                    nextNodes.push_back(n->children[1]);
                }
            }
        }
        prevs = nextNodes;
    }

    vector<int> answers;

    for (Node* n : prevs) {
        for (int idx : n->p) {
            answers.push_back(idx+1);
        }
    }

    if (answers.size() == 1) {
        cout << "unique" << "\n" << answers[0];
    } else {
        cout << "ambiguous" << "\n" << answers.size();
    }

    return 0;
}

/*

5 5 3
YYYYY
NNNNN
YNYNY
YYYNN
NNYYY

*/
