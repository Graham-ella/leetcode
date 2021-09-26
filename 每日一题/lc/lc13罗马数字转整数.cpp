/*
思路:
由于题目的简单性，可以考虑将13中罗马数字进行分类
I IV IX
V
X XL XC
L 
C CD CM
D
M

遍历给定的字符串s，s[i]和上面的进行匹配(要注意类似C CD CM这种有共同前缀'C'的这种情况)
*/

class Solution {
public:
    int romanToInt(string s) {
        int len = s.size();
        int res = 0;
        for(int i = 0;i<len;i++){
            if(s[i] == 'V'){
                res += 5;
            }else if(s[i] == 'L'){
                res += 50;
            }else if(s[i] == 'D'){
                res += 500;
            }else if(s[i] == 'M'){
                res += 1000;
            }else if(s[i] == 'I'){
                if(i<len-1 && s[i+1] == 'V'){
                    res += 4;
                    i++;
                }else if(i<len-1 && s[i+1] == 'X'){
                    res += 9;
                    i++;
                }else{
                    res += 1;
                }
            }else if(s[i] == 'X'){
                if(i<len-1 && s[i+1] == 'L'){
                    res += 40;
                    i++;
                }else if(i<len-1 && s[i+1] == 'C'){
                    res += 90;
                    i++;
                }else{
                    res += 10;
                }
            }else if(s[i] == 'C'){
                if(i<len-1 && s[i+1] == 'D'){
                    res += 400;
                    i++;
                }else if(i<len-1 && s[i+1] == 'M'){
                    res += 900;
                    i++;
                }else{
                    res += 100;
                }
            }
        }
        return res;
    }
};