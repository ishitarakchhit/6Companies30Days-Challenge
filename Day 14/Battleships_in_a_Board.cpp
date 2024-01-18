class Solution {
public:
    

    int countBattleships(vector<vector<char>>& board) {
        int count = 0;

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == 'X'){
                    bool chain = false;
                    if(i>0)
                        if(board[i-1][j]=='X') chain = true;
                    if(j>0)
                        if(board[i][j-1] == 'X') chain = true;
                    if((i==0 && j== 0) || !chain) count++;
                    
                }
            }
        }
        return count;
    }
};
