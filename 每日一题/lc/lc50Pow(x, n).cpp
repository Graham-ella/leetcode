/*
非常牛逼 十分巧妙 
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        long long N = n;
        if(n < 0){
            x = 1/x;
            /*
            n = -n;
            这里遇到问题 n可以取到 [INT_MIN , INT_MAX]
            INT_MIN在绝对值上比INT_MAX还大 直接翻转的话会出现溢出
            */
            N = -N;
        }
        double cur = x;
        double res = 1;
        for(long long i = N ; i > 0 ; i/=2){
            if(i%2) res *= cur;
            cur *= cur;
        }
        return res;
    }
};
