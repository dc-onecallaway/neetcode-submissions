class Solution {
   public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) {
            return "";
        }

        map<char, int> mp1;
        map<char, int> mp2;

        int formed = 0;

        for (int i = 0; i < t.length(); i++) {
            mp1[t[i]]++;
        }

        int start = 0;
        int end = 0;

        string ans = "";
        int length = INT_MAX;

        while (end < s.length()) {
            mp2[s[end]]++;
            if (mp1.count(s[end]) && mp2[s[end]] == mp1[s[end]]) {
                formed++;
            }
            while (formed == mp1.size()) {
                if ((end - start + 1 < length)) {
                    length = end - start + 1;
                    ans = s.substr(start, end - start + 1);
                }
                if (mp1.count(s[start]) && mp2[s[start]] == mp1[s[start]]) {
                    formed--;
                }
                mp2[s[start]]--;
                start++;
            }
            end++;
        }

        return ans;
    }
};
