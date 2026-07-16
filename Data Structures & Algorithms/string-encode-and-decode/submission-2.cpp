class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(int i = 0;i<strs.size();i++){
            s += strs[i];
            s += '~';
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> vec;
        for(int i = 0;i<s.size();i++){
            string temp = "";
            while(s[i] != '~'){
                temp += s[i];
                i++;
            }
            vec.push_back(temp);
        }
        return vec;
    }
};
