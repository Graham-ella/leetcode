//原题链接：https://leetcode-cn.com/problems/minimize-maximum-pair-sum-in-array/

//Sort函数有三个参数：（第三个参数可不写）
//（1）第一个是要排序的数组的起始地址。
//（2）第二个是结束的地址（最后一位要排序的地址）
//（3）第三个参数是排序的方法，可以是从大到小也可是从小到大，还可以不写第三个参数，此时默认的排序方法是从小到大排序。
// 对于第三个参数:less<数据类型>()//从小到大排序   greater<数据类型>()//从大到小排序


class Solution {
public:
    int minPairSum(vector<int>& nums) {
    //可以猜测要想得到最下的最大数对和，分组的时候最小和最大元素分在一起，依此类推
    sort(nums.begin(),nums.end());
    int res = 0;
    for(int i = 0 , j = nums.size()-1; i < j;i++,j--){
        res = max(res,nums[i]+nums[j]);
    }
    return res;
    

    }
};


//yxc的做法
//链接为：https://www.acwing.com/activity/content/code/content/1300769/
/*
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0, j = nums.size() - 1; i < j; i ++, j -- )
            res = max(res, nums[i] + nums[j]);
        return res;
    }
};
*/