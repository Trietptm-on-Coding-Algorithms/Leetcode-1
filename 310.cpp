class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1)
            return vector<int>(1, 0);

        vector<vector<int>> adjList(n);
        vector<int> cnts(n, 0);

        for (auto edge : edges) {
            adjList[edge.first].push_back(edge.second);
            adjList[edge.second].push_back(edge.first);

            ++cnts[edge.first], ++cnts[edge.second];
        }

        queue<int> leaves;
        for (int idx = 0; idx < n; ++idx) {
            if (adjList[idx].size() == 1)
                leaves.push(idx);
        }

        while (n > 2) {
            int numLeaves = leaves.size();
            n -= numLeaves;

            for (int idx = 0; idx < numLeaves; ++idx) {
                int now = leaves.front();
                leaves.pop();

                for (auto neighbor : adjList[now]) {
                    if (--cnts[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }

        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }

        return result;
    }
};
