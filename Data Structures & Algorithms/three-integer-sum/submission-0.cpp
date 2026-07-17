class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> mp;
            for (int j = i+1; j < nums.size(); j++) {
                if(mp.find(-(nums[i] + nums[j]))!= mp.end()){
                    vector<int> temp = {nums[i],nums[j],-(nums[i]+ nums[j])};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                }
                mp.insert(nums[j]);
            }
        }
        vector<vector<int>> arr(ans.begin(), ans.end());
        return arr;
    }
};
