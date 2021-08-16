/*
思路: 核心在于利用本身应该具有的强递减性
题目里有一些基本的计数单位:
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

给定一个字符串s,啥也不考虑的话就是遍历s，然后把每个字符对应的数字加上去
而且按理来说这个s的字符对应的数字是单调递减的存在
但是由于
IV IX
XL XC
CD CM
的存在，
所以使得s不强满足我上面说的。因此
*/

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char,int> hash;
        hash['I'] = 1;
        hash['V'] = 5;
        hash['X'] = 10;
        hash['L'] = 50;
        hash['C'] = 100;
        hash['D'] = 500;
        hash['M'] = 1000;
        
        int len = s.size();
        for(int i = 0;i<len;i++){
            //如果不满足强递减的情况就是出现了特殊情况需要减去
            if(i<len - 1 && hash[s[i+1]]>hash[s[i]]){
                res -= hash[s[i]];
            }else{
                res += hash[s[i]];
            }
        }
    }
};