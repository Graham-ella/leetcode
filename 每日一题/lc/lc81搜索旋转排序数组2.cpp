/*
对于这种数组有重复元素的情况，
例如 nums = [3,1,2,3,3,3,3] target = 2 我们无法判断区间[l,mid]和[mid,r]哪个是递增的
对于这种情况，我们只能将 l++ , r-- , 然后在新区间上继续二分查找。
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 1) return nums[0] == target;
        int l = 0 , r = len - 1;
        while(l < r){
            int mid = l + (r - l)/2;
            if(nums[mid] == target) return true;
            if(nums[mid] == nums[l] && nums[mid] == nums[r]){
                l++ , r--;
            }else if(nums[l] <= nums[mid]){
                if(nums[l] <= target && target < nums[mid]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }else{
                if(nums[mid] < target && target <= nums[r]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
        }
        return nums[l] == target;
    }
};
