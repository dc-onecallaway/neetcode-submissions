class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") {
            return 0;
        }
        int start = 0;
        int end = 0;

        set<char> st;

        int maxlength = 0;

        while (end < s.length()) {
            if (st.find(s.at(end)) != st.end()) {
                while (s.at(start) != s.at(end)) {
                    st.erase(s.at(start));
                    start++;
                }
                start++;
            } else {
                st.insert(s.at(end));
                maxlength = max(maxlength, end - start + 1);
            }
            end++;
            
        }

        return maxlength;
    }
};
