class Solution {
public:
    string maxValue(string n, int x) {
        string res = "";
        if(n[0]!='-'){
            int i = 0;
            for(; i< n.size(); i++){
                if(n[i]-'0'< x){
                    res = n.substr(0,i)+to_string(x)+n.substr(i);
                    break;
                }
            }
             if(i==n.size()){
                return n + to_string(x);
            }
            return res;
        }else{
            int i = 1;
              for(; i< n.size(); i++){
                if(n[i]-'0'> x){
                    res = n.substr(1,i-1)+to_string(x)+n.substr(i);
                    break;
                }
            }
            if(i==n.size()){
                return n + to_string(x);
            }
             return "-"+res;
        }
    
    }
};



//yxc的做法：
/*
class Solution {
public:
    string maxValue(string n, int x) {
        if (n[0] != '-') {
            int k = 0;
            while (k < n.size() && n[k] - '0' >= x) k ++ ;
            return n.substr(0, k) + to_string(x) + n.substr(k);
        } else {
            int k = 1;
            while (k < n.size() && n[k] - '0' <= x) k ++ ;
            return n.substr(0, k) + to_string(x) + n.substr(k);
        }
    }
};

*/
