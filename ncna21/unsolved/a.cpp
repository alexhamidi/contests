// #include <iostream>

// using namespace std;

// struct data {
//     int freqs[26];
//     data operator+(const data& other) {
//         for (int i = 0; i < 26; i++) {
//             freqs[i] += other.freqs[i];
//         }
//     }
// };


// class SegmentTree {
// private:
//     vector<data*> st;
//     int n;

// public:
//     SegmentTree(string& s) {
//         n = s.size();
//         st.resize(s.size()*4, null);
//         build(s, 1, 0, n-1);
//     }

//     void build(string& s, int sti, int stl, int str) {
//         if (stl == str) {
//             st[sti] = new data;
//             st[sti]->freqs[s[stl]]++;
//         } else {
//             int stm = (stl+str)/2;
//             build(s, sti*2, stl, stm);
//             build(s, sti*2+1, stm+1, str);
//             st[stm]->freqs = *st[sti*2] + *st[sti*2+1];
//         }
//     }

//     data query(int sti, int stl, int str, int ql, int qr) {
//         if (ql > qr) {
//             return 0;
//         }
//         if (ql == stl && qr == str) {
//             return st[sti]->freqsZ;
//         }
//         int stm = (stl+str)/2;
//         return *query(sti*2, stl, stm, ql, min(qr, stm)) +
//                *query(sti*2+1, stm+1, str, max(ql, stm+1), qr);
//     }

//     void update (int sti, int stl, int str, int idx, char ch) {
//         if (stl == str) {
//             st[sti] = ch;
//         } else {
//             int stm = (stl+str)/2;
//             if (idx <= stm) {
//                 update(sti*2, stl, stm, idx, ch);
//             } else {
//                 update(sti*2+1, stm+1, str, idx, ch);
//             }
//             st[stm]->freqs = *st[sti*2] + *st[sti*2+1];
//         }
//     }
// };

// int main() {

//     string s;
//     int q;
//     cin >> s >> q;
//     int n = s.size();
//     SegmentTree st(s);

//     //init st based on s


//     for (int i = 0; i < q; i++) {
//         int t;
//         cin >> t;
//         if (t == 1) {
//             int l, r;
//             cin >> l >> r;
//             int ct = st.query(1, 0, n-1, l, r);
//             cout << ct << "\n";
//         } else {
//             int i;
//             char x;
//             cin >> i >> x;
//             st.update(1, 0, n-1, i, x);
//         }
//     }


//     return 0;
// }

// /*



// */
