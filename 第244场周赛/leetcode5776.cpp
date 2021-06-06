//原题链接：
//https://leetcode-cn.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/

class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>> a) {
        auto b = a;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0, k = n - 1; j < n; j++, k--) {
                b[i][j] = a[k][i];
            }
        }
        return b;
    }
    
    
    bool findRotation(vector<vector<int>>& a, vector<vector<int>>& b) {
        for (int i = 0; i < 4; i++) {
            a = rotate(a);
            if (a == b) {
                return true;
            }
        }
        return false;
    }
};