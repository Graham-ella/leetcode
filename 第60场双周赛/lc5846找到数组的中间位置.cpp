class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n+1);
        for(int i = 1;i <= n;i++){
            s[i] = s[i-1] + nums[i-1];
        }//处理好前缀和数组后
        for(int i = 0;i<n;i++){
            if(s[i] == s[n]-s[i+1]){
                return i;
            }
        }
        return -1;
    }
};