class Solution {
public:
    static bool cmp(string a, string b) { //compare wala
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> arr;
        for (int i = 0; i<n; i++) {
            arr.push_back(to_string(nums[i]));
        }
        sort(arr.begin(), arr.end(), cmp); //cmp: decide order of elements in sorting
        string ans = "";
        for (string s : arr) {
            ans += s;
        }
        if (ans[0] == '0') // ex: "0000" 
            return "0";   //return karega sirf "0"

        return ans;
    }
};
