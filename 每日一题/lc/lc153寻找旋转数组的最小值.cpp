/*
leetcode153:寻找旋转数组的最小值
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = left + (right - mid)/2;
            if(nums[mid] > nums[right]){ 
                // 说明[left,mid]是单调递增的 而且由于右边界的数一定比左边的小
                // 因此最小的数此时一定在右边
                // left往右
                left = mid + 1;
            }else if(nums[mid] < nums[right]){
                // 在while循环里一定有 left<=mid mid<right
                // 说明[mid,right]是单调递增的 
                // 最小值在mid处或者左半边
                right = mid;
            }
        }
        // while退出的条件就是 left == right
        return nums[left];
    }
};