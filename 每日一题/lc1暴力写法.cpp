class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //暴力枚举
		vector<int> res;
		for(int i = 0;i<nums.size()-1;i++){
            for(int j = i + 1;j<nums.size();j++){
                if((nums[i]+nums[j])==target){
                    // res.push_back(i);
                    // res.push_back(j);
                    //由于这里res结果一定是非常简单的两个数，可以通过类似于初始化赋值的方式，这样能快一点
                    res = vector<int>{i,j};
                    //由于每种输入只会对应一个答案，如果能找到一种答案就不用继续往下找了，直接break即可，这样能快一点
                    //但是这里的break只是用来跳出j循环，我们想要实现的是直接返回结果
                    break;
                }
            }
            //因此为了判断是否已经有了结果，我们还要在j循环外面一层加个break
            if(res.size()>0){
                break;
            }
            
        }
        return res;

    }
};