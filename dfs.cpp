#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
bool vis[100];

void dfs(int node)
{
    vis[node] = true;          // mark visited

    cout << node << " ";       // process current node

    for(int child : adj[node]) // visit neighbours
    {
        if(!vis[child])
            dfs(child);
    }
}

int main()
{
    adj[0]={1,2};
    adj[1]={0,3,4};
    adj[2]={0};
    adj[3]={1};
    adj[4]={1};

    dfs(0);
}
