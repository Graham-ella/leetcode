class Solution {
public:
    int deleteRepeatNumber(vector<int> &nums , int len , int k){
        int s = 2 , f = 2;
        while(f < len){
            if(nums[s-k]!=nums[f]){
                nums[s] = nums[f];
                s++;
            }
            f++;
        }
        return s;
    }
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len <= 2) return len;
        int res = deleteRepeatNumber(nums,len,2);
        return res;
    }
};
