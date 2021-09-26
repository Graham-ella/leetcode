class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return;
        int i = n - 2 , j = n - 1;

        // 从后往前找，找到相邻的升序对
        while(nums[i] >= nums[j]){
            i--;
            j--;
            if(i == -1) break;
        }
        // 如果找到了相邻的升序对
        if(i>=0){
            /*
            可以确定的是[j,n-1]上的数是递减的 从后往前找，找到第一个 > nums[i]的
            那么 >= nums[i] 呢？ 由于nums[j] > nums[i] 因此最后倒置[j,end]的数的时候
            就算是nums[k] == nums[i]新得到的数也要比之前的小
            */
            int k = n - 1;
            while(nums[k] <= nums[i]) k--;
            swap(nums[i],nums[k]);
        }

        // [j,n-1]上的数是递减的 接下来要把它们倒置

        int l = j , r = n - 1;
        while(l<r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
    }
};