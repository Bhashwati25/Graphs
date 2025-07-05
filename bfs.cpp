//geeksforgeeks

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

//bfs traversal with adjacency list provided
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        unordered_map<int,bool> visited;
        vector<int> ans;
        for(int i = 0; i < adj.size(); i++) {
            if(!visited[i]) {
                bfs(adj, visited, ans, i);
            }
        }
        return ans;
    }

    void bfs(vector<vector<int>> &adj, unordered_map<int,bool>& visited, vector<int> &ans, int node) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);

            for(auto neighbor : adj[frontNode]) {
                if(!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};
