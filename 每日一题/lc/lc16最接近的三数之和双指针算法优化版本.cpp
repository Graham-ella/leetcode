/*
思路二：
利用双指针算法 减少一重循环 时间复杂度变成O(n^2)
*/
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end()); // 先对nums进行排序
        int len = nums.size();
        int res = 100000;
        for (int i = 0; i < len - 2; i++)
        {
            int le = i + 1;
            int ri = len - 1;
            while (le < ri)
            {
                if (nums[i] + nums[le] + nums[ri] == target) // 如果有相等的情况就不用继续了 直接return target计科
                {
                    return target;
                }
                else
                {
                    if (abs(nums[i] + nums[le] + nums[ri] - target) < abs(res - target))
                    {
                        res = nums[i] + nums[le] + nums[ri];
                        //如果遇到更接近的就更新res
                    }
                    if (nums[i] + nums[le] + nums[ri] > target)
                    {
                        ri--;
                    }
                    else
                    {
                        le++;
                    }
                }
            }
        }
        return res;
    }
};