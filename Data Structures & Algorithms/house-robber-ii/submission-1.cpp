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
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> dp1(nums.size()-1,-1);
        vector<int> dp2(nums.size()-1,-1);
        vector<int> arr1(nums.size()-1,-1);
        vector<int> arr2(nums.size()-1,-1);
        for(int i = 1;i<nums.size();i++){
            arr1[i-1] = nums[i];
            arr2[i-1] = nums[i-1];
        }
    
        return max(maxRobb(arr1.size() - 1,arr1,dp1),maxRobb(arr2.size() - 1,arr2,dp2));
    }
};
