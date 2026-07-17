class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        map<char, int> mp;

        for (int i = 0; i < s1.length(); i++) {
            mp[s2.at(i)]--;
            mp[s1.at(i)]++;
        }

        bool ans = true;
        for (auto curr : mp) {
            if (curr.second != 0) {
                ans = false;
                break;
            }
        }

        if (ans) {
            return true;
        }

        for (int i = s1.length(); i < s2.length(); i++) {
            mp[s2[i]]--;
            mp[s2[i - s1.length()]]++;
            ans = true;
            for (auto curr : mp) {
                if (curr.second != 0) {
                    ans = false;
                    break;
                }
            }
            if (ans) {
                return true;
            }
        }
        return false;
    }
};
