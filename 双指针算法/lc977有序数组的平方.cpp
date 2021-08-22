/*
思路：
利用双指针法
[i,j]跑while循环
left = nums[i]*nums[i]
right = nums[j]*nums[j]
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
		int i = 0 , j = n - 1;
		int k = n - 1;
		vector<int>  res(n);
		while(i<=j){
			int left = nums[i]*nums[i];
			int right = nums[j]*nums[j];
			if(left < right){
				res[k] = right;
				k--;
				j--;
			}else{
				res[k] = left;
				k--;
				i++;
			}
		}
		return res;
    }
};