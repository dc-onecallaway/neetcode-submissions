class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for (auto it : mp) {
            pq.push({it.second, it.first});
        }
        while (k--) {
            pair<int, int> temp = pq.top();
            ans.push_back(temp.second);
            pq.pop();
        }
        return ans;
    }
};
