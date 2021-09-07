/*
删除有序数组中的重复项

如何删除？
第0个元素可以直接略过
l = 1 r = 1
让r往右走，走到不能走，如果r当前元素变了就可以进行更换

*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len == 0 || len == 1) return len;
        int l = 1 , r = 1;
        while(r<len){
            if(nums[r]!=nums[r-1]){ //有新的值出现了
                nums[l] = nums[r];
                l++;
            }
            r++;
        }
        return l;
    }
};