class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int row = board.size();//代表行
        int col = board[0].size();//代表列
        int dx[8] = {0,-1,-1,-1,0,1,1,1};
        int dy[8] = {1,1,0,-1,-1,-1,0,1};
        for(int i = 0;i<8;i++){
            int state = 0;
            //得到相邻的点坐标
            int newr = rMove + dx[i];
            int newc = cMove + dy[i];
            while(newr>=0&&newr<row&&newc>=0&&newc<col){
                if(board[newr][newc]=='.'){
                    break;
                }
                if(board[newr][newc]!=color){
                    state = 1;
                }else{
                    if(state){
                        return true;
                    }else{
                        break;
                    }
                }
                newr += dx[i];
                newc += dy[i];
            }
        }
        return false;
    }
};