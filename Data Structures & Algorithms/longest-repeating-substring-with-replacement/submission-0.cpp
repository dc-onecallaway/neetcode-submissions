class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        int end = 0;

        vector<int> alphaCount(26,0);
        int maxCount = 0;
        int maxlength = 0;

        while(end < s.length()){
            alphaCount[s[end] - 'A']++;
            maxCount = max(maxCount,alphaCount[s[end] - 'A']);
            
            if(end + 1 - start - maxCount > k){
                alphaCount[s[start] - 'A']--;
                start++;
            } else {
                maxlength = max(maxlength,end + 1 - start);
            }
            end++;
        }

        return maxlength;
    }
};
