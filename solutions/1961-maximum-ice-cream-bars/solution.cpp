class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(), costs.end());
        int count = 0; 
        int sum = 0;
        for(int i = 0; i<n; i++) {
            if(sum + costs[i] <= coins) {
                sum += costs[i];
                count++;
            }
            else break;
        }
        return count;
    }
};
