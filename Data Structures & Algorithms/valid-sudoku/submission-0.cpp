class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i<board.size();i++){
            set<int> s1;
            set<int> s2;
            set<int> s3;
            for(int j = 0;j<board.size();j++){
                int row = 3*(i/3) + (j/3);
                int col = 3*(i%3) + (j%3);
                if(board[row][col] != '.'){
                    if(s3.find(board[row][col]) != s3.end()){
                        return false;
                    }
                    s3.insert(board[row][col]);
                }
                if(board[i][j] != '.'){
                    if(s1.find(board[i][j]) != s1.end()){
                        return false;
                    }
                    s1.insert(board[i][j]);
                }
                if(board[j][i] != '.'){
                    if(s2.find(board[j][i]) != s2.end()){
                        return false;
                    }
                    s2.insert(board[j][i]);
                }
            }
        }
        return true;
    }
};
