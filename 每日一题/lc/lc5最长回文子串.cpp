class Solution {
public:
    string longestPalindrome(string s) {
        int res = 0;//结果
        string str;//返回的结果字符串
        for (int i = 0; i < s.size(); i++)//当作回文字符串的中心
        {
            /*
            回文字符串有两种:
            长度为偶数的 abba
            长度为奇数的 acdca
            */

            //长度为奇数的情况:
            for (int j = 0; i - j >= 0 && i + j < s.size(); j++)
                //从回文字符串的中心向外扩展，扩展j，当然要保证i-j>=0 i+j<s.size()
                if (s[i - j] == s[i + j])//如果满足回文字符串的形式
                {
                    if (j * 2 + 1 > res)
                    {
                        res = j * 2 + 1;
                        str = s.substr(i - j, j * 2 + 1);
                    }
                }
                else break;//如果不满足直接break就行了

            //这里直接break是什么意思呢？
            /*
            我们利用i这层循环遍历可能存在的回文字符串的中心，然后利用j这层循环来试图找到比当前更长的回文字符串
            如果能找到更长的我们直接修改res和str，如果找不到那就说明这个中心点没有什么用，直接break就行
            */

            //相当于双指针的感觉，一个往前走一个往后走
            for (int j = i, k = i + 1; j >= 0 && k < s.size(); j--, k++)
                if (s[j] == s[k])//要满足回文字符串的要求
                {
                    if (k - j + 1 > res)
                    {
                        res = k - j + 1;
                        str = s.substr(j, k - j + 1);
                    }
                }
                else break;
        }
        return str;
    }
};

