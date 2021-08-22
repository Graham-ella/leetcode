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



// 换一种写法
int left_bound(int[] nums,int target){
	int left = 0,right = nums.length()-1;
	while(left<=right){
		int mid = left + (right-left)/2;
		if(nums[mid]<target){
			/*
			搜索区间变为:[mid+1,right]
			*/
			left = mid + 1;
		}else if(nums[mid]>target){
			/*
			搜索区间变为:[left,mid-1]
			*/
			right = mid - 1;
		}else if(nums[mid] == target){
			right = mid - 1;
		}
	}

	if(left>=nums.length() || nums[left] != target){
		return -1;
	}
	return left;
}