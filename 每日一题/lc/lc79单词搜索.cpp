/*
bool check(i,j,k)
表示从board[i][j]开始能否和word[k...]匹配上
如果board[i][j] != word[k] 直接返回false就行
如果board[i][j] == word[k] 且 k = string.size() - 1已经到了字符串末尾 返回true
其它情况下:
要根据四个方向 选出新的 (newi , newj) 继续调用check(newi , newj , k + 1)
*/
class Solution {
public:
    int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    bool check(vector<vector<char>>& board , vector<vector<bool>>& visited , int i , int j , int k , string &word){
        if(board[i][j] != word[k]) return false;
        if(k == word.size() - 1) return true;
        visited[i][j] = true;
        for(int p = 0 ; p < 4 ; p++){
            int newi = i + direction[p][0];
            int newj = j + direction[p][1];
            if(newi>=0 && newi < board.size() && newj >= 0 && newj < board[0].size() && !visited[newi][newj]){
                bool temp = check(board, visited, newi, newj, k+1, word);
                if(temp) return true;
            }
        }
        visited[i][j] = false; // 如果这里(i,j)这里走不下去的话把它重新设为false
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                bool temp = check(board,visited,i,j,0,word);
                if(temp) return true;
            }
        }
        return false;
    }
};
