class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == ""){
            return 0;
        }
        int i = 0;
        int j = 0;

        map<int,int> mp;
        int maxLength = 0;
        while(j<s.length()){
            if(mp[s[j]] == 1){
                while(s[i] != s[j]){
                    mp[s[i]]--;
                    i++;
                }
                mp[s[i]]--;
                i++;
            }
            mp[s[j]]++;
            maxLength = max(maxLength,j-i+1);
            j++;
        }

        return maxLength;
        
    }
};
