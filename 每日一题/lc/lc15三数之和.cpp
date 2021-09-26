/*
思路：
考虑使用双指针法
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int len = nums.size();
        // 目的就是要找到 a+b+c=0 a<=b<=c
        // a = nums[i] b = nums[left] c = nums[right]
        for(int i = 0;i<len;i++){
            if(nums[i]>0){
                return res;
            }//如果最小的nums[i]都大于0了就没必要继续下去了
            if(i>0 && nums[i]==nums[i-1]) continue; //去掉a的重
            int left = i + 1;
            int right = len - 1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right] > 0){
                    right--; // 如果大了，右边往左边挪
                }else if(nums[i]+nums[left]+nums[right] < 0){
                    left++;  // 如果小了，左边往右边挪
                }else{
                    res.push_back(vector<int>{nums[i],nums[left],nums[right]}); // 将三元组放进去
                    // 去掉b和c的重
                    while(left<right && nums[left] == nums[left+1]) left++;
                    while(left<right && nums[right] == nums[right-1]) right--;
                    
                    //找到最后的答案时 双指针还是需要收缩的
                    left++;
                    right--;

                }
            }
        }
        return res;
    }
};