class Solution {
public:
    int maxRobb(int n,vector<int> &nums,vector<int> &dp){
        if(n < 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int way1 = nums[n] + maxRobb(n-2,nums,dp);
        int way2 = maxRobb(n-1,nums,dp);

        return dp[n] = max(way1,way2);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return maxRobb(nums.size() - 1 ,nums,dp);
    }
};
