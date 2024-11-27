#include <iostream>
#include <cmath>
#include <numbers>
#include <iomanip>
using namespace std;

int sq(int a) {
    return a * a;
}

double sq(double a) {
    return a * a;
}


double getDistance(pair<double, double> p1, pair<double, double> p2) {
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    return sqrt(sq(x1-x2) + sq(y1-y2));
}

bool lineOnCircle(int x1, int y1, int x2, int y2, int xc, int yc, int r) {
    int a = sq(x2-x1) + sq(y2-y1);
    int b = 2 * (((x2 - x1) * (x1 - xc)) + ((y2 - y1) * (y1 - yc)));
    int c = sq(x1-xc) + sq(y1-yc) - sq(r);
    int disc = sq(b) - 4 * a * c;
    return (disc >= 0);
}

const int BS_ITERS = 10000;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int xa, ya, xb, yb, xc, yc, r;
        cin >> xa >> ya >> xb >> yb >> xc >> yc >> r;
        pair<int, int> a = {xa, ya};
        pair<int, int> b = {xb, yb};
        double theta = M_PI/2;
        pair<double, double> currPos = {xc, yc+r};
        for (int _ = 0; _ < BS_ITERS; _++) {
            auto [currX, currY] = currPos;

            double relX = currX-xc;
            double relY = currY-yc;

            pair<double, double> ccw = {xc + (relX*cos(theta)-relY*sin(theta)),
                                        yc + (relX*sin(theta)+relY*cos(theta))};

            pair<double, double> cw = {xc + (relX*cos(-theta)-relY*sin(-theta)),
                                        yc + (relX*sin(-theta)+relY*cos(-theta))};

            double ccwD = getDistance(a, ccw) + getDistance(b, ccw);
            double cwD = getDistance(a, cw) + getDistance(b, cw);

            if (ccwD < cwD) {
                currPos = ccw;
            } else {
                currPos = cw;
            }
            theta /= 2;
        }
        double ans = getDistance(a, currPos) + getDistance(b, currPos);
        cout << setprecision(7) << ans << "\n";
    }
    return 0;
}
/*
what does it mean to go to the left or right 1/nths of a circle?

for now, assume it leads to a global optimum and wait for counterexamples.

binary seach

*/


/*
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define RFOR(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define SZ(a) int(a.size())
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
#define F first
#define S second

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef double db;

const db EPS = 1e-9;
const db PI = acos(-1.0);

struct Pt
{
	db x, y;
	Pt operator-(const Pt& p) const
	{
		return {x - p.x, y - p.y};
	}
};

db sq(const Pt& p)
{
	return p.x * p.x + p.y * p.y;
}

db abs(const Pt& p)
{
	return sqrt(sq(p));
}

int sgn(db x)
{
	return (EPS < x) - (x < -EPS);
}

Pt perp(const Pt& p)
{
	return {-p.y, p.x};
}

db dot(const Pt& p, const Pt& q)
{
	return p.x * q.x + p.y * q.y;
}

db cross(const Pt& p, const Pt& q)
{
	return p.x * q.y - p.y * q.x;
}

struct Line
{
	Pt n;
	db c;
	Line (const Pt& p, const Pt& q):
		n(perp(q - p)), c(-dot(n, p)) {}
	db side(const Pt& p) const
	{
		return dot(n, p) + c;
	}
	db dist(const Pt& p) const
	{
		return abs(side(p)) / abs(n);
	}
	bool cmpProj(const Pt& p, const Pt& q) const
	{
		return sgn(cross(p, n) - cross(q, n)) < 0;
	}
};

db segPt(const Pt& a, const Pt& b, const Pt& p)
{
	Line l(a, b);
	assert(sgn(sq(l.n)) != 0);
	if (l.cmpProj(a, p) && l.cmpProj(p, b))
		return l.dist(p);
	return min(abs(p - a), abs(p - b));
}

void solve()
{
	Pt a, b, c;
	db rad;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> rad;
	if (sgn(abs(b - a)) == 0)
	{
		db ac = abs(c - a);
		if (sgn(ac - rad) <= 0)
			cout << "0\n";
		else
			cout << 2 * (ac - rad) << "\n";
		return;
	}
	if (sgn(segPt(a, b, c) - rad) <= 0)
	{
		cout << abs(b - a) << "\n";
		return;
	}
	db ans = 1e7;
	FOR(i, 0, 4)
	{
		db l = i * PI / 2, r = (i + 1) * PI / 2;
		FOR(it, 0, 74)
		{
			db m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
			Pt p1(c.x + rad * cos(m1), c.y + rad * sin(m1));
			Pt p2(c.x + rad * cos(m2), c.y + rad * sin(m2));
			db f1 = abs(p1 - a) + abs(b - p1);
			db f2 = abs(p2 - a) + abs(b - p2);
			ans = min(ans, f1);
			ans = min(ans, f2);
			if (f1 < f2)
				r = m2;
			else
				l = m1;
		}
	}
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}


*/
