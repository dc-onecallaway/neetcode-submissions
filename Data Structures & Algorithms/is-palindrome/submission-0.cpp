class Solution {
public:
    bool isPalindrome(string s) {
        
        string newS;

        for(char c : s){
            if(c <= 'z' &&  c >= 'a'){
                newS += c;
            }else
            if(c <= 'Z' &&  c >= 'A'){
                newS += (char)(c - 'A' + 'a');
            }else
            if(c <= '9' &&  c >= '0'){
                newS += c;
            }
        }

        bool ans = true;

        cout << newS << endl;

        for(int i = 0;i<newS.length()/2;i++){
            if(newS.at(i) != newS.at(newS.length() - 1 - i)){
                ans = false;
                break;
            }
        }

        return ans;
    }
};
