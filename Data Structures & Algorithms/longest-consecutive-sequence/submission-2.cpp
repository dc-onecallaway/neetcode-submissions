class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int> mp;

        int ans = 0;

        for(int i = 0;i<nums.size();i++){
            if(mp.find(nums[i]-1) == mp.end()){
                mp[nums[i]] = 1;
            } else {
                mp[nums[i]] = mp[nums[i]-1] + 1;
            }
            ans = max(mp[nums[i]],ans);
        }

        return ans;
    }
};
