class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int countZero = 0;
        int zeroPosition = -1;
        long long product = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                product *= nums[i];
            } else {
                countZero++;
                zeroPosition = i;
            }
        }
        if (countZero > 1) {
            return ans;
        }

        if (countZero == 1) {
            ans[zeroPosition] = product;
            return ans;
        }

        for (int i = 0; i < nums.size(); i++) {
            ans[i] = product / nums[i];
        }

        return ans;
    }
};
