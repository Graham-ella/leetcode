class Solution {
public:
    bool isPalindrome(int x) {
        // 容易知道负数和以0结尾的数都不可能
        // if(x<0||x%10==0) return false; // 这里有一个小坑 这样写的话把0也给排除了
        if(x < 0 || (x && (x%10 == 0))) return false;
        // 接下来是相当于摘数字的过程
        // 如果直接把数字倒过来可能会出现int溢出的情况
        // 所以我们可以考虑导致后面一部分的数字看看和前面的(偶数情况:是否相等)(奇数情况:...)
        int number = 0;
        while(number <= x){
            number = 10*number + x%10;
            if(number == x || number == x/10) return true;
            x /= 10;
        }
        return false;
    }
};