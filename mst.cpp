#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum cost to connect all the cities
int findMST(int n, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> adj(n + 1); // 1-based indexing

    // Convert edge list to adjacency list (1-based indexing adjustment)
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    // Min-Heap (Priority Queue) to store {weight, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<bool> inMST(n + 1, false); // To keep track of included nodes
    pq.push({0, 1});  // Start from node **1** instead of 0
    int mstCost = 0;  // Store MST Cost

    while (!pq.empty()) {
        auto tmp = pq.top(); // Get the node with the smallest weight
        int w = tmp.first;
        int u = tmp.second;
        pq.pop();

        // If the node is already in MST, ignore it
        if (inMST[u]) continue;
        inMST[u] = true;
        mstCost += w; // Add weight to MST cost

        // Process all adjacent nodes
        for (auto& it : adj[u]) {
            
            int weight = it.first;
            int v = it.second;
            
            if (!inMST[v]) {
                pq.push({weight, v});
            }
        }
    }

    return mstCost;
}

// Driver function
int main() {
    // Input: List of edges {u, v, weight} (1-based indexing)
    vector<vector<int>> city1 = {
        {1, 2, 1}, {1, 3, 2}, {1, 4, 3}, {1, 5, 4},
        {2, 3, 5}, {2, 5, 7}, {3, 4, 6}
    };
    cout <<findMST(5, city1) << endl;

    vector<vector<int>> city2 = {
        {1, 2, 1}, {1, 3, 1}, {1, 4, 100},
        {2, 3, 1}, {4, 5, 2}, {4, 6, 2}, {5, 6, 2}
    };
    cout <<findMST(6, city2) << endl;

    return 0;
}
