/*
思路：题目很简单，题干中给了13个单位，，可以利用贪心的思想，
根据题目中给的数字，每次在单位中选择符合条件的最大的那个单位减掉即可
*/

class Solution {
public:
    string intToRoman(int num) {
        int weight[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string name[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res = "";
        while(num){
            for(int i = 0;i < 13; i++){
                if(num>=weight[i]){
                    num -= weight[i];
                    res += name[i];
                    break;
                }
            }
        }
        return res;
    }
};