class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        for (int num : nums) {
            if (st.find(num - 1) == st.end()) {
                int current = num;
                int length = 1;

                while (st.find(current + 1) != st.end()) {
                    current++;
                    length++;
                }
                ans = max(length, ans);
            }
        }

        return ans;
    }
};
