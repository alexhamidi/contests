#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main() {
    int p, t;
    cin >> p >> t;

    vector<vector<char>> adj;

    for (int i = 0; i < t; i++) {
        string ct;
        cin >> ct;
        bool currValid = true;
        set<char> cts(ct.begin(), ct.end());
        if (cts.size() != ct.size()) {
            currValid = false;
        }
        for (int i = 25; i >= p; i--) {
            if (cts.count(char(i+'A'))) {
                currValid = false;
            }
        }
        if (currValid) {
            adj.push_back({});
            for (char c : cts) {
                adj.back().push_back(c);
            }
        }
    }


    t = adj.size();


    int maxSatisfiedTeams = 0; //2^20

    //brute force

    cout << maxSatisfiedTeams;
    return 0;
}

/*


maximize the number of teams to have all initials matching


ignore all that have multiple of the same
ignore all that have chars after
only consider unique (reduce each team to 26)

can it be reduced to a graph problem entirely?2

very low constraingts

 SI:        -         -
 MI:        -   -
WMU:            -       - -
    ABCDEFGHIJKLMNOPQRSTUVWXYZ


#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int numResources, numTeams;

    // Read the number of resources and teams
    cin >> numResources >> numTeams;

    // Store each team's requested resources
    vector<string> teamRequests(numTeams);
    for (int i = 0; i < numTeams; i++) {
        cin >> teamRequests[i];
    }

    // Variable to track the maximum number of teams that can be satisfied
    int maxSatisfiedTeams = 0;

    // Explicit subset generation without recursion
    for (int subsetSize = 0; subsetSize <= numTeams; subsetSize++) {
        // Generate all subsets of size `subsetSize`
        vector<int> subset(subsetSize);
        for (int i = 0; i < subsetSize; i++) {
            subset[i] = i; // Initialize subset indices
        }

        while (true) {
            // Validate the current subset
            set<char> usedResources;
            bool isValid = true;

            for (int team : subset) {
                for (char resource : teamRequests[team]) {
                    int resourceIndex = resource - 'A';

                    // Check for invalid or duplicate resource
                    if (resourceIndex >= numResources || usedResources.count(resource)) {
                        isValid = false;
                        break;
                    }
                    usedResources.insert(resource);
                }
                if (!isValid) break;
            }

            // Update the maximum if this subset is valid
            if (isValid) {
                maxSatisfiedTeams = max(maxSatisfiedTeams, (int)subset.size());
            }

            // Generate the next combination of this size
            int i = subsetSize - 1;
            while (i >= 0 && subset[i] == numTeams - subsetSize + i) {
                i--;
            }
            if (i < 0) break; // No more subsets of this size

            subset[i]++;
            for (int j = i + 1; j < subsetSize; j++) {
                subset[j] = subset[j - 1] + 1;
            }
        }
    }

    // Output the result
    cout << maxSatisfiedTeams << endl;

    return 0;
}

*/
