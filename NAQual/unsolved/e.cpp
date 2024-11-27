
#include <iostream>
#include <cmath>
#include <string>
#include <numeric>

using namespace std;

int main() {
    int b = 9;
    int d = 6;
    int n;
    cin >> n;
    string out;

    for (int i = 0; i < n; i++) {
        int b, d;
        cin >> b >> d;
        int currWays = 0;
        //if it doesnt work, just invert it
        int anums = ((b-1) * gcd(b, d))/d;

        out += (to_string(anums) + "\n");
    }
    cout << out;
    return 0;
}


/*


Rearranging: c = b - a*d/b

Since 'c' is a positive integer, (b - a*d/b) must be a positive integer.

This means that 'ad' must be divisible by 'b'. Let's call the quotient 'k': ad = k*b, where 'k' is some integer

Substituting this back into our equation for 'c': c = b - k

Now, we need to find how many valid values of 'k' exist. 'k' must satisfy:

k < b (because c > 0)

k*b is divisible by d

The second condition means that 'k' must be a multiple of b/gcd(b,d).

Therefore, the possible values for 'k' are: 0, b/gcd(b,d), 2b/gcd(b,d), 3b/gcd(b,d), ..., up to but not including b

The number of such values is: (b-1) * gcd(b,d) / b

Simplifying: ((b-1) * gcd(b,d)) / d

This is our final answer. It represents the number of ways to choose integer values for 'a' and 'c' that are consistent with Edward's measurements.

The reason this works is because it counts all the possible integer solutions for 'k' (and thus 'a' and 'c') that satisfy the constraints of the problem. The gcd(b,d) term accounts for the relationship between 'b' and 'd', ensuring we only count integer solutions.



*/
// while (d * a < b*b) {
        //     currWays++;
        //     a += g;
        // }

/*
enumerate in o(n)
how many WAYS to choose c and d




measure the rate of pumping of two pumps

first pump does a liters in b seconds
second pup does c liters in d second

together, they pump b liters in d seconds

return the number of different ways to choose a and c

//solved

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;


int main() {
    int n;
    cin >> n;
    string out;

    for (int i = 0; i < n; i++) {
        int b, d;
        cin >> b >> d;
        int currWays = 0;
        int g = d/gcd(b, d);
        int ans = (b-1)/g;

        out += (to_string(ans) + "\n");
    }
    cout << out;
    return 0;
}
*/


/*
enumerate in o(n)
how many WAYS to choose c and d




measure the rate of pumping of two pumps

first pump does a liters in b seconds
second pup does c liters in d second

together, they pump b liters in d seconds

return the number of different ways to choose a and c



*/


