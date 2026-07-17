#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlap(vector<vector<int>> &arr) {
    int n = arr.size();

    sort(arr.begin(), arr.end());
    vector<vector<int>> res;

    // Checking for all possible overlaps
    for (int i = 0; i < n; i++) {
        int start = arr[i][0];
        int end = arr[i][1];

        // Skipping already merged intervals
        if (!res.empty() && res.back()[1] >= end)
            continue;

        // Find the end of the merged range
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end)
                end = max(end, arr[j][1]);
        }
        res.push_back({start, end});
    }
    return res;
}

int main() {
    vector<vector<int>> arr = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};
    vector<vector<int>> res = mergeOverlap(arr);

    for (auto interval : res)
        cout << interval[0] << " " << interval[1] << endl;

    return 0;
}
