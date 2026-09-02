#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
    struct DSU {
        vector<int> parent;
        vector<int> rank;

        DSU(int n) {
            parent.resize(n);
            rank.assign(n, 0);
            iota(parent.begin(), parent.end(), 0); // Fills parent with 0, 1, ..., n-1
        }

        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]); // Path compression
        }

        void unionSets(int a, int b) { // Renamed from 'union' since 'union' is a C++ keyword
            int pa = find(a);
            int pb = find(b);
            if (pa == pb) return;

            if (rank[pa] < rank[pb]) {
                parent[pa] = pb;
            } else if (rank[pb] < rank[pa]) {
                parent[pb] = pa;
            } else {
                parent[pb] = pa;
                rank[pa]++;
            }
        }
    };

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    dsu.unionSets(i, j);
                }
            }
        }

        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) {
                provinces++;
            }
        }

        return provinces;
    }
};

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of cities must be greater than 0." << endl;
        return 0;
    }

    vector<vector<int>> isConnected(n, vector<int>(n));
    cout << "Enter the adjacency matrix (row by row, space-separated 0s and 1s):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    Solution sol;
    int components = sol.findCircleNum(isConnected);

    cout << "\nTotal number of provinces: " << components << endl;

    return 0;
}
