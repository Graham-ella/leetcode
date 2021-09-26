class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(int n , int k , int start){
        if(path.size() == k){
            res.push_back(path);
            return;
        }
        for(int i = start ; i <= n ; i++){
            path.push_back(i);
            dfs(n, k, i + 1); // 这里的i+1已经保证不会重复往前取数了
            path.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        if(n < k) return res;
        dfs(n,k,1);
        return res;
    }
};