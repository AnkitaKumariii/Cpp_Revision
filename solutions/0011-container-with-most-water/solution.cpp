class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int i = 0;
        int j = n - 1;
        while(i<j) {
            int area = (j - i) * min(height[i], height[j]);
            ans = max(ans, area);
            if(height[i] < height[j]) i++;
            else if(height[i] > height[j]) j--;
            else j--;
        }
        return ans;
    }
};
