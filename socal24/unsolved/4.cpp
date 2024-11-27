#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

struct eq {
    double w;
    double b;
    eq() : w(0), b(0) {}
    eq(double w, double b) : w(w), b(b) {}

    eq wrap(eq other) {
        eq currEq;
        currEq.w = w * other.w;
        currEq.b = b * other.w + other.b;
        return currEq;
    }
    eq wrapI(eq other) {
        eq currEq;
        currEq.b = (b - other.b) / other.w;
        currEq.w = w/other.w;
        return currEq;
    }
};

unordered_map<string, pair<string, eq>> parents;
unordered_map<string, pair<string, eq>> upMemo;
unordered_map<string, pair<string, eq>> downMemo;

pair<string, eq> up(string currUnit) {
    if (upMemo.count(currUnit)) {
        return upMemo[currUnit];
    }
    if (parents[currUnit].first == currUnit) {
        return upMemo[currUnit] = {currUnit, eq(1, 0)};
    }
    pair<string, eq> parentRes = up(parents[currUnit].first);
    eq currEq = parents[currUnit].second.wrap(parentRes.second);
    return upMemo[currUnit] = {parentRes.first, currEq};
}

pair<string, eq> down(string currUnit) {
    if (downMemo.count(currUnit)) {
        return downMemo[currUnit];
    }
    if (parents[currUnit].first == currUnit) {
        return downMemo[currUnit] = {currUnit, eq(1, 0)};
    }
    pair<string, eq> parentRes = down(parents[currUnit].first);
    eq currEq = parentRes.second.wrapI(parents[currUnit].second);
    return downMemo[currUnit] = {parentRes.first, currEq};
}

int main() {
    string line;
    string out = "";

    while (getline(cin, line)) {
        istringstream ss(line);
        if (line[0] == 'G') {
            break;
        } else if (line[0] == 'K') {
            string lunit, runit;
            double weight, bias = 0;
            char type, eql, addop = '+';

            ss >> type >>  lunit >> eql >> weight >> runit;
            if (ss.peek() != EOF) ss >> addop >> bias;

            bias *= 1-2*(addop == '-');

            if (!parents.count(lunit) && !parents.count(runit)) { //
                parents[lunit] = {lunit, eq(1, 0)};
            }

            string newUnit;
            if (parents.count(lunit)) {
                parents[runit] = {lunit, eq(weight, bias)};
                newUnit = runit;
            } else {
                parents[lunit] = {runit, eq(1/weight, -bias)};
                newUnit = lunit;
            }
            up(newUnit);
            down(newUnit);

        } else if (line[0] == 'H') {
            double amt;
            string lunit, runit;
            char type, eql, ques;
            ss >> type >> amt >> lunit >> eql >> ques >> runit;
            if (!upMemo.count(lunit) || !downMemo.count(runit)) {
                out += "Too hard!\n";
                continue;
            }
            auto [rootL, lCumUp]  = upMemo[lunit];
            auto [rootR, rCumDown]  = downMemo[runit];
            if (rootL != rootR) {
                out += "Too hard!\n";
            } else {
                double LtoRoot = amt*lCumUp.w + lCumUp.b;
                double ans = LtoRoot*rCumDown.w + rCumDown.b;
                out += to_string(ans) + "\n";
            }
        }
    }
    cout << out;
    return 0;
}




            // out += "\nCurrent state of memos:\n";
            // out += "Up: \n";
            // for (auto [origin, mem] : upMemo) {
            //     auto [root, currEq] = mem;
            //     out += root + " = " + to_string(currEq.w) + origin + " + " + to_string(currEq.b) + "\n";
            // }
            // out += "Down: \n";
            // for (auto [origin, mem] : downMemo) {
            //     auto [root, currEq] = mem;
            //     out += origin + " = " + to_string(currEq.w) + root + " + " + to_string(currEq.b) + "\n";
            // }


// #include <iostream>
// #include <stack>
// #include <sstream>
// #include <unordered_map>
// using namespace std;
// //i ended up implementing a version of union find without even knowing it
// struct eq {
//     double w;
//     double b;
//     eq(double w, double b) {
//         this->w = w;
//         this->b = b;
//     }
// };

// int main() {
//     string line;
//     unordered_map<string, pair<string, eq>> parents;
//     unordered_map<string, pair<string, eq>> memo; //curr -> root, only store w/b and then apply (dont start with amt.)
//     //need to do for up and down
//     //if we can do a varaible then we're gooda

//     string out = "";

//     while (getline(cin, line)) {
//         istringstream ss(line);
//         if (line[0] == 'G') {
//             break;
//         } else if (line[0] == 'K') { //worry about this for now
//             string lunit, runit;
//             double weight, bias;
//             char type, eql, addop;

//             ss >> type >>  lunit >> eql >> weight >> runit;

//             if (ss.peek() != EOF) {
//                 ss >> addop >> bias;
//             } else {
//                 addop = '+';
//                 bias = 0;
//             }
//             if (addop == '-') bias *= -1;

//             // out += "\nCurrent equation: \n";
//             // out +df= lunit + " " + eql + " " + to_string(weight) + " " + runit + " " + addop + " " + to_string(bias) + "\n"; //not processing properly.l

//             if (!parents.count(lunit) && !parents.count(runit)) { //
//                 parents[lunit] = {lunit, eq(1, 0)};
//             }
//             if (parents.count(lunit)) {
//                 parents[runit] = {lunit, eq(weight, bias)};
//             } else {
//                 parents[lunit] = {runit, eq(1/weight, -bias)}; //double -?
//             }
//             // out += "\n";
//             // for (auto [origin, edge] : parents) {
//             //     auto [par, equa] = edge;
//             //     out += origin + ": " + par + ",["+to_string(equa.w) + "," + to_string(equa.b) + "]\n";
//             // }
//         } else if (line[0] == 'H') {

//             double amt;
//             string lunit, runit;
//             char type, eql, ques;
//             ss >> type >> amt >> lunit >> eql >> ques >> runit;

//             string rootL = lunit;
//             string rootR = runit;

//             if (!parents.count(lunit) || !parents.count(runit)) {
//                 out += "Too hard!\n";
//                 continue;
//             }

//             while (parents[rootL].first != rootL) { //need to do it
//                 amt = (amt * parents[rootL].second.w + parents[rootL].second.b);//0, 32
//                 rootL = parents[rootL].first;
//             }

//             stack<eq> eqs;
//             while (parents[rootR].first != rootR) {
//                 eqs.push(eq(parents[rootR].second.w, parents[rootR].second.b));
//                 rootR = parents[rootR].first;
//             }

//             while (!eqs.empty()) { //compose changes in the opposite direction
//                 eq curr = eqs.top();
//                 eqs.pop();
//                 amt = ((amt - curr.b) * 1/curr.w); //invert direction & operations
//             }

//             if (rootL != rootR) { //says they are diff, should both be kb
//                 out += "Too hard!\n";
//             } else {
//                 out += to_string(amt) + "\n";
//             }
//         }
//     }
//     cout << out;
//     return 0;
// }
// //worst case - n^2, need to memoize
// //


// //adding this messes it
// // H 1.000 kB = ? b how does a query effect


// /*


// rooted tree, go all the way to the root and all the way back down each time, logn

// at most 2 * 10^5 knowledge


// bidirectional



// tree, each only has one parent

// vector of nodes, each with a single parent pair, only going up
// */
