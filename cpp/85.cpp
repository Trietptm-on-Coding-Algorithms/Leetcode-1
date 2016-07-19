class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
            
        const int row = matrix.size();
        const int col = matrix[0].size();
        
        vector<int> left(col, 0);
        vector<int> right(col, col);
        vector<int> height(col, 0);
        
        int maxArea = 0;
        
        for (int r = 0; r < row; ++r) {
            int curLeft = 0, curRight = col;
            
            for (int c = 0; c < col; ++c) {
                if (matrix[r][c] == '1') {
                    ++height[c];
                    left[c] = max(left[c], curLeft);  
                } else {
                    height[c] = 0;
                    left[c] = 0;
                    curLeft = c + 1;
                }
            }
            
            for (int c = col - 1; c >= 0; --c) {
                if (matrix[r][c] == '1') {
                    right[c] = min(right[c], curRight);
                } else {
                    right[c] = col;
                    curRight = c;
                }
            }
            
            for (int c = 0; c < col; ++c) {
                maxArea = max(maxArea, (right[c] - left[c]) * height[c]);
            }
        }
        
        
        return maxArea;
    }
};