#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        // Initialize distances for each edge
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            dist[u][v] = weight;
            dist[v][u] = weight;
        }
        
        // Distance to self is zero
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        
        // Floyd-Warshall Algorithm
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        int minReachable = n;
        int cityWithMin = -1;
        
        // Find the city with the smallest number of reachable cities
        for (int i = 0; i < n; ++i) {
            int reachableCount = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    ++reachableCount;
                }
            }
            
            // Update the result, choosing the city with the largest index in case of ties
            if (reachableCount < minReachable || (reachableCount == minReachable && i > cityWithMin)) {
                minReachable = reachableCount;
                cityWithMin = i;
            }
        }
        
        return cityWithMin;
    }
};


int main(){
    int n = 5;
    int distanceThreshold = 10;
    vector<vector<int>> edges = {{0, 1, 10}, {0, 2, 1}, {2, 3, 1}, {1, 3, 1}, {1, 4, 1}, {4, 3, 1}};
    Solution sol;
    cout << "City with the smallest number of reachable cities: " << sol.findTheCity(n, edges, distanceThreshold) << endl;
}