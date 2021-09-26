class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int> &nums , int start , int n){
        res.push_back(path);
        if(start == n) return;
        
        for(int i = start ; i < n ; i++){
            path.push_back(nums[i]);
            dfs(nums,i+1,n);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return res;
        if(n == 1){
            res.push_back(nums);
            res.push_back(path);
            return res;
        }
        dfs(nums,0,n);
        return res;
    }
};
