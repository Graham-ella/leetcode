//原题链接：https://leetcode-cn.com/problems/substrings-of-size-three-with-distinct-characters/



class Solution {
public:
    int countGoodSubstrings(string s) {
        int res = 0;//代表最后结果
        for(int i = 0;i+2<s.length();i++){
            if(s[i]!=s[i+1] && s[i+1]!=s[i+2]&&s[i]!=s[i+2]){
                res++;
            }
		//leetcode的编译器问题，如果写成i<s.length()-2是通不过的，可能是<和-运算顺序的问题
        }
        return res;
    }
};


//yxc的写法：
/*
class Solution {
public:
    int countGoodSubstrings(string s) {
        int res = 0;
        for (int i = 0; i + 2 < s.size(); i ++ ) {
            int a = i, b = i + 1, c = i + 2;
            if (s[a] != s[b] && s[b] != s[c] && s[a] != s[c])
                res ++ ;
        }
        return res;
    }
};

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/1300758/
*/
