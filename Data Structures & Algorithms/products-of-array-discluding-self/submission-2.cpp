class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProduct(nums.size());
        vector<int> suffixProduct(nums.size());

        vector<int> ans(nums.size());

        for(int i = 0;i<nums.size();i++){
            if(i == 0){
                prefixProduct[i] = nums[i];
                suffixProduct[nums.size() - 1 - i] = nums[nums.size() - 1 - i];
            } else {
                prefixProduct[i] = nums[i] * prefixProduct[i-1];
                suffixProduct[nums.size() - 1 - i] = nums[nums.size() -1 - i] * suffixProduct[nums.size() - i];
            }
        }

        for(int i = 0;i<nums.size();i++){
            if(i == 0){
                ans[i] = suffixProduct[i+1];
            } else if(i == nums.size() - 1){
                ans[i] = prefixProduct[i-1];
            } else {
                ans[i] = prefixProduct[i-1]*suffixProduct[i+1];
            }
        }

        return ans;
    }
};
