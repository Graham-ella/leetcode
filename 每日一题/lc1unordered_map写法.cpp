class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> res;//结果集
        unordered_map<int,int> hash;//前面的key应该指的是nums里的真实值，value指的是值对应的下标
        for (int i = 0; i < nums.size(); i ++ )
        {
            //由于数据保证有且仅有一组解，假设是[i, j](i < j)
            //则我们循环到 j时，nums[i]一定在哈希表中，且有 nums[i] + nums[j] == target
            int another = target - nums[i];//算出剩余的值
            if (hash.count(another))//如果已经有了
            {
                res = vector<int>({hash[another], i});//将i和j都存进去
                break;
            }
            hash[nums[i]] = i;//如果没有，加入表中
        }
        return res;
    }
};
