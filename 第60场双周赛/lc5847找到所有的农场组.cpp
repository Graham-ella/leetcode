class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        int row = land.size();
        int col = land[0].size();
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(land[i][j]){
                    int x = i , y = j;
                    for(int a = i; a < row && land[a][j];a++){
                        for(int b = j;b < col && land[a][b];b++){
                            land[a][b] = 0;
                            y = max(y,b);
                        }
                        x = max(x,a);
                    }
                    res.push_back(vector{i,j,x,y});
                }
            }
        }
        return res;
    }
};