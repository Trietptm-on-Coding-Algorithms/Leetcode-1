class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix):
        sums(matrix.size() + 1, 
            vector<int>(
                matrix.size() ? matrix[0].size() + 1 : 1, 0))
    {
        int row = matrix.size();
        int col = matrix.size() ? matrix[0].size() + 1 : 1;

        for (int r = 1; r <= row; ++r) {
            for (int c = 1; c <= col; ++c){
                sums[r][c] += sums[r-1][c] + sums[r][c-1] 
                                + matrix[r-1][c-1];
            } 
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        return sums[row2+1][col2+1] + sums[row1][col1]
                - sums[row2+1][col1] - sums[row1][col2+1];     
    }

private:
    vector<vector<int>> sums;
};

