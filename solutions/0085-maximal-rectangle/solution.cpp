class Solution {
private:
    int largestRectangleArea(vector<int>& heights)
    {
        stack<int> stk;
        heights.push_back(0);
        int maxi = 0;
        for (int i = 0; i<heights.size(); i++)
        {
            while(!stk.empty() && heights[stk.top()]>heights[i])
            {
                int h = heights[stk.top()];
                stk.pop();
                int w;
                if (stk.empty()) w = i;
                else w = i - stk.top() - 1;
                maxi = max(maxi,h*w);
            }
            stk.push(i);
        }
        return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int sz = matrix.size();
        int az = matrix[0].size();
        int ans = 0;
        vector<int> heights(az,0);
        for (int i = 0; i<sz; i++)
        {
            for (int j = 0; j<az; j++)
            {
                if (matrix[i][j]=='1') heights[j]++;
                else heights[j] = 0;
            }
            ans = max(ans,largestRectangleArea(heights));
        }
        return ans;
    }
};
