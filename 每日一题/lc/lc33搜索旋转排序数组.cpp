class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1){
            if(nums[0] == target) return 0;
            else return -1;
        }
        int l = 0 , r = n - 1;
        while(l < r){
            int mid = l + (r - l)/2;
            if(nums[mid] == target) return mid;
            if(nums[0] <= nums[mid]){
                /*
                [0,mid]递增
                */
                if(nums[0] <= target && target < nums[mid]){
                    r = mid - 1;
                }// 右半部分的数只会 比nums[0]小 或者 比nums[mid]大
                else{
                    l = mid + 1;
                }
            }else{
                /*
                nums[0] > nums[mid]
                因此[mid,right]是有序的                
                */
                if(nums[mid] < target && target <= nums[n-1]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
        }
        return (nums[l] == target)?l:-1;
    }
};