/*
寻找右侧边界的二分搜索
*/
int right_bound(int[] nums,int target){
	if(nums.length() == 0) return -1;
	int left = 0,right = nums.length();
	while(left<right){
		int mid = (left + right)/2;
		if(nums[mid] == target){
			left = mid + 1;
		}else if(nums[mid] < target){
			left = mid + 1;
		}else if(nums[mid] > target){
			right = mid;
		}
	}

	/*
	while终止的条件是 left == right , 也就是说left的取值范围是[0,nums.length] , 当
	left取到0时，left-1显然索引越界了
	*/
	if(left == 0) return -1;
	return nums[left-1] == target?(left-1):-1;
}


/*
闭区间写法
*/
int right_bound(int[] nums,int target){
	int left = 0,right = nums.length()-1;
	while(left<=right){
		int mid = left + (right-left)/2;
		if(nums[mid] == target){
			left = mid + 1;
		}else if(nums[mid] < target){
			left = mid + 1;
		}else if(nums[mid] > target){
			right = mid - 1;
		}
	}

	/*
	当target比所有元素都小时，right会被减到-1，所以需要在最后防止越界
	*/
	if(right < 0 || nums[right] != target){
		return -1;
	}
	return right;
}