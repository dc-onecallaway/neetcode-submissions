class Solution {
public:
    bool checkAnagrams(string s1,string s2){
        if(s1.length() != s2.length()){
            return false;
        }
        vector<int> arr(26,0);
        for(int i = 0;i<s1.length();i++){
            arr[s1[i] - 'a']++;
            arr[s2[i] - 'a']--;
        }
        for(int i = 0;i<26;i++){
            if(arr[i] != 0){
                return false;
            }
        }

        return true;

    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        ans.push_back({strs[0]});
        for(int i = 1;i<strs.size();i++){
            bool done = false;
            for(int j = 0;j<ans.size();j++){
                if(checkAnagrams(ans[j][0],strs[i])){
                    ans[j].push_back(strs[i]);
                    done = true;
                    break;
                }
            }
            if(!done){
                ans.push_back({strs[i]});
            }
        }

        return ans;
    }

};
