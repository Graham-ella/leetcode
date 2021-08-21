/*
寻找左侧边界的二分搜索
*/
int left_bound(int[] nums,int target){
    if(nums.size() == 0) return -1;
    int left = 0;
    int right = nums.size();
    while(left<right){
        int mid = (left+right)/2;
        if(nums[mid] == target){
            right = mid;
        }else if(nums[mid] < target){
            left = mid + 1;
        }else if(nums[mid] > target){
            right = mid;
        }
    }
    return left; //这种情况是默认能找到的情况下

    /*
    如果存在找不到的情况
    if(left == nums.size()) return -1;
    return nums[left] == target ? left : -1;

    */
}