class Solution {
public:
    int minCost(int n,vector<int> &cost,vector<int> &dp){
        if(n == 0 || n == 1){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int cost1 = cost[n-1] + minCost(n-1,cost,dp);
        int cost2 = cost[n-2] + minCost(n-2,cost,dp);
        return dp[n] = min(cost1,cost2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return minCost(cost.size(),cost,dp);
    }
};
