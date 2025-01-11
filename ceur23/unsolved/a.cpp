
/*
problem - collats, not overlaps

*/
#include <iostream>

using namespace std;

vector<pair<int, int>> intervals;


int getShots() {
    //assumes intervals is sorted
    int shots = 0;
    int n = intervals.size();



    vector<pair<int, int>> currShot;

    int ece = intervals[0].first;

    // single problem - how many, if we do it as late as possible
    /*
        already doing first sequentially, just need to delay, def possiblem,.?

        sort by nds?d

        we want cutoffs to be monotonic - maybe currently truek
        -----
         ------
          -
            --

    */
    for (int i = 0; i < n; i++) {
        if (intervals[i].first > ece) {
            shots++;
            ece = intervals[i].second;
        } else {
            ece = max(ece, intervals[i].second);
        }

    }

    return shots;
}
/*

            --
             ------
             -------
               -------
-
           ----------
  -
012345678912345678901234567890
*/



int main() {

    int n;
    cin >> n;
    int cid = 1;


    /*
        needs to be sorted


        just do n^2 /  n^2logn
    */
    //simply needs to be sorted by left

    while (n--) {
        int a;
        cin >> a;
        if (a < 0) {
            int tr = -a;
        } else {
            int b;
            cin >> b;
            intervals.push_back({a, b});
        }
        cout << getShots() << "\n";
    }

    return 0;
}
/*
  |
            --
             ------
             -------
               -------
-
           ----------
  -
012345678912345678901234567890


*/




// //shouldsolve

// #include <iostream>
// using namespace std;


// struct ITNode {
//     pair<int, int> iv;
//     int maxEnd;
//     int numOverlap;
//     ITNode* left;
//     ITNode* right;
//     ITNode* parent;
//     ITNode(ITNode* parent, pair<int, int> iv) {
//         this->iv = iv;
//         this->parent = parent;
//         maxEnd = iv.second;
//         numOverlap = 1; //only itself
//         left = nullptr;
//         right = nullptr;
//     }
// };

// ITNode* root = nullptr;

// //mayve updateranges - how does everything impact numranges?

// void updateMax(ITNode* node) { //maybe do parents, since only one child will be affeting
// //updating only the parent
//     if (node->parent == nullptr) {
//         return;
//     }

//     if (node->iv.second > node->parent->maxEnd) {
//         node->parent->maxEnd = node->iv.second;
//         updateMax(node->parent);
//     }
// }

// void updateOverlap(ITNode* node) { //maybe do parents
//     if (node->parent == nullptr) {
//         return;
//     }

//     if (node->iv.first > node->parent->iv.second || node->iv.second < node->parent->iv.first) {
//         node->parent->numOverlap++; //not necessarily true
//     }
//     /*
//         wird - just cuz

//         why don't you need to hold all?


//         start with left

//         max can  be greater

//         if left->max < left then we know, without a doubt, that we add 1 to the left
//     */


// }

// ITNode* insert(ITNode* node, pair<int, int> iv) {
//     if (node == nullptr) {//only happens at the root
//         root = new ITNode(nullptr, iv);
//         root->numOverlap = 1;
//         return;
//     }
//     if (iv.first > node->iv.first) {
//         if (node->right == nullptr) {
//             node->right = new ITNode(node, iv);//max auto updated
//             updateMax(node->right);
//             updateOverlap(node->right);
//             return node->right;
//         } else {
//             insert(node->right, iv);
//         }
//     } else {
//         if (node->left == nullptr) {
//             node->left = new ITNode(node, iv);
//             updateMax(node->left);
//             updateOverlap(node->left);
//             return node->left;
//         } else {
//             insert(node->left, iv);
//         }
//     }
// }

// void remove(ITNode* node) {
//     if (node->left == nullptr && node->right == nullptr) {
//         if (node->parent) {
//             if (node->parent->left == node) {
//                 node->parent->left = nullptr;
//             } else {
//                 node->parent->right = nullptr;
//             }
//         } else {
//             root = nullptr;
//         }
//     } else if (node->left == nullptr || node->right == nullptr) {
//         ITNode* child = (node->left) ? node->left : node->right;
//         if (node->parent) {
//             if (node->parent->left == node) {
//                 node->parent->left = child;
//             } else {
//                 node->parent->right = child;
//             }
//         } else {
//             root = child;
//         }
//         child->parent = node->parent;
//     } else {
//         ITNode* successor = node->right;
//         while (successor->left != nullptr) {
//             successor = successor->left;
//         }
//         node->iv = successor->iv;
//         remove(successor);
//         return;
//     }
//     updateMax(node);
//     updateOverlap(node);
// }



// int main() {

//     int n;
//     cin >> n;
//     unordered_map<int, ITNode*> nodes;
//     int cid = 1;

//     while (n--) {
//         int a;
//         cin >> a;
//         if (a < 0) {
//             remove(nodes[-a]);
//         } else {
//             int b;
//             cin >> b;
//             nodes[cid++] = insert(root, {a, b});
//         }
//         cout << (root->numOverlap ? root->numOverlap : 0) << "\n";
//     }

// }

/*
dealing with intervals, number of noncontiguous intervals with the ability to remove or add

can do logn

use an interval tree
- create a BST where the left endpoint is the key
- store max endpoint in the subtree rooted at the node

insert
- insert based on left
- update maxes


requirement - only affects
*/
