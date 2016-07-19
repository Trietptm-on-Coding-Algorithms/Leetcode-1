class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> tables(rows, vector<int>(cols, 0));
        int longestPath = 1;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int path = dfs(matrix, r, c, rows, cols, tables);
                longestPath = max(longestPath, path);
            }
        }

        return longestPath;
    }

private:
    int dfs(vector<vector<int>>& matrix, int r, int c, int rows, int cols,
            vector<vector<int>>& tables) {
        if (tables[r][c] != 0)
            return tables[r][c];

        int path = 1;
        for (auto dir : dirs) {
            int curR = r + dir[0], curC = c + dir[1];
            if (curR < 0 || curR >= rows ||
                curC < 0 || curC >= cols ||
                matrix[curR][curC] <= matrix[r][c])
                continue ;
            int len = 1 + dfs(matrix, curR, curC, rows, cols, tables);
            path = max(path, len);
        }

        tables[r][c] = path;
        return path;
    }

private:
    vector<vector<int>> dirs = 
    {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};