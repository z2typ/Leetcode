class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char> > rows(9),cols(9);
        vector<vector<unordered_set<char> > > sub_box(3,vector<unordered_set<char>>(3));
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(rows[i].count(board[i][j]) ||
                   cols[j].count(board[i][j]) ||
                   sub_box[i/3][j/3].count(board[i][j])){
                    return false;
                }else if(board[i][j]>='0' && board[i][j]<='9'){
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    sub_box[i/3][j/3].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};