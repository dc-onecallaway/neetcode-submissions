class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        bool zero = false;
        int count = 0;

        long product = 1;

        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                zero = true;
                count++;
                continue;
            } else {
                product *= nums[i];
            }
        }

        vector<int> products(nums.size());

        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                if(count == 1){
                    products[i] = product;
                } else {
                    products[i] = 0;
                }
            } else {
            if(zero){
                products[i] = 0;
            } else {
                products[i] = product/nums[i];
            }
        }
        } 

        return products;

    }
};
