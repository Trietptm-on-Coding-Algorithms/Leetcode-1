class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        heights.push_back(0);
        
        stack<int> index;
        
        for (int i = 0; i < heights.size(); ++i) {
            
            while (!index.empty() && heights[index.top()] >= heights[i]) {
                int height = heights[index.top()];
                index.pop();
                
                int sidx = !index.empty() ? index.top() : -1;
                result = max(result, height * (i - sidx - 1));
            }
            
            index.push(i);
        }
        
        return result;
    }
};