/*
思路一：
可以考虑对nums使用三重循环找到最接近的和

*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sumRES = -1;
        int gap = INT_MAX;
        int len = nums.size();
        for(int i = 0;i<len-2;i++){
            for(int j = i + 1;j<len-1;j++){
                for(int k = j + 1;k<len;k++){
                    if(abs(nums[i]+nums[j]+nums[k]-target)<gap){
                        sumRES = nums[i]+nums[j]+nums[k];
                        gap = abs(nums[i]+nums[j]+nums[k]-target);
                    }
                }
            }
        }
        return sumRES;

    }
};