#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm:
// question: minimum time difference
// example:
// answer:
// explanation:
// tags:

int findMinDifference(vector<string> &timePoints)
{
    // step 1 : covert time string into minutes integer value
    vector<int> minutes;
    for (int i = 0; i < timePoints.size(); i++)
    {
        string curr = timePoints[i];
        int hours = stoi(curr.substr(0, 2));
        int min = stoi(curr.substr(3, 2));
        int totalMinutes = hours * 60 + min;
        minutes.push_back(totalMinutes);
    }
    // step 2 : sort minutes vector
    sort(minutes.begin(), minutes.end());
    // step 3 : difference and calculate min diff
    int mini = INT_MAX;
    for (int i = 0; i < minutes.size() - 1; i++)
    {
        int diff = minutes[i + 1] - minutes[i];
        mini = min(mini, diff);
    }
    // special case
    int lastDiff = (minutes[0] + 1440) - minutes[minutes.size() - 1];
    mini = min(mini, lastDiff);
    return mini;
}

int main()
{
    vector<string> timePoints{"00:00", "23:59", "00:00"};
    int ans = findMinDifference(timePoints);
    cout << ans << endl;
    return 0;
}