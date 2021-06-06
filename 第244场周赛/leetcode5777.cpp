//找到最大值，将最大值变为严格次大值
//最终的结果：必然全都最小值
//因此每个数变的次数等于比它小的数字个数
//用s表示从第一个数到当前数不同的数的个数
//原题链接:
//https://leetcode-cn.com/problems/reduction-operations-to-make-the-array-elements-equal/
class Solution {
public:
    int reductionOperations(vector<int>& a) {
        sort(a.begin(), a.end());//先将所有数排序
        int res = 0;
        for (int i = 1,s = 0; i < a.size(); i++) {
            if (a[i] != a[i - 1]) {
                s++;
            }
            res += s;
        }
        return res;
    }
};