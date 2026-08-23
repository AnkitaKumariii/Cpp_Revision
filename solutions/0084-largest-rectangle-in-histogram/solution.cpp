class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>stk;
        int maxiArea = 0;
        for(int i = 0; i<n; i++) {
            while(!stk.empty() && heights[stk.top()] > heights[i]) {
                int element = stk.top();
                stk.pop();
                int nse = i, psee = stk.empty() ? -1: stk.top();
                maxiArea = max(heights[element]* (nse-psee-1), maxiArea);
            }
            stk.push(i);
        }
        while(!stk.empty()) {
            int nse = n;
            int element = stk.top();
            stk.pop();
            int psee = stk.empty() ? -1: stk.top();
            maxiArea = max(maxiArea, (nse - psee - 1) * heights[element]);
        }
        return maxiArea;
    }
};
