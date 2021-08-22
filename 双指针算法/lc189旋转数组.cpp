/*
思路一：
下标为i的元素向右移动k个位置后下标为 (i+k)%len

时间复杂度:O(n)
空间复杂度:O(n)


assign函数:
函数原型：
	void assign(const_iterator first,const_iterator last);
	void assign(size_type n,const T& x = T());
功能：
将区间[first,last)的元素赋值到当前的vector容器中，(这里的区间开闭有点疑问)
或者赋n个值为x的元素到vector容器中，这个容器会清除掉vector容器中以前的内容。
*/

class Solution
{
public:
	void rotate(vector<int> &nums, int k)
	{
		int len = nums.size();
		vector<int> res(len, -1);
		for (int i = 0; i < len; i++)
		{
			res[(i + k) % len] = nums[i];
		}
		//nums = res;
		nums.assign(res.begin(), res.end());
	}
};

/*
思路二:
倒转nums中的元素

时间复杂度:O(n)
空间复杂度:O(1)
*/
class Solution
{
public:
	void myReverse(vector<int> &nums,int i,int j){
		while(i<j){
			swap(nums[i],nums[j]);
			i++;
			j--;
		}
	}
	
	void rotate(vector<int> &nums, int k)
	{
		int len = nums.size();
		k %= len;
		/*
		如果用这种方法，举个例子:
		nums: [-1] k = 2
		k比len还大的这种情况下面的两个myReverse会出现数组越界的情况
		因此要先用k对len取模
		*/
		myReverse(nums,0,len-1);
		myReverse(nums,0,k-1);
		myReverse(nums,k,len-1);
	}
};