class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int len = nums.size();
        if(len < 4) return res;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size() - 3; k++)
        {
            if (k > 0 && nums[k] == nums[k - 1])
            {
                continue;
            } // 对k去重
            for (int i = k + 1; i < nums.size() - 2 ; i++)
            {
                if (i > k + 1 && nums[i] == nums[i - 1])
                {
                    continue;
                }
                int left = i + 1, right = nums.size() - 1;
                while (left < right)
                {
                    long long sum=(long long)nums[i]+nums[k]+nums[left]+nums[right];
                    if (sum > target)
                    {
                        right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        res.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        //去重left,right

                        right--;
                        left++;
                        //去重后两边同时收缩
                    }
                }
            } // 对i去重
        }
        return res;
    }
};