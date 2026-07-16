class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alpha(26,0);

        for(int i = 0;i<s.length();i++){
            alpha[s.at(i) - 'a']++;
        }
        for(int i = 0;i<t.length();i++){
            alpha[t.at(i) - 'a']--;
        }

        for(int i = 0;i<26;i++){
            if(alpha[i] != 0){
                return false;
            }
        }
        return true;
    }
};
