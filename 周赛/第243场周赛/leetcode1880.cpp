class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
		int a = 0;
        int b = 0;
        int c = 0;
		for(int i = 0;i<firstWord.size();i++){
            a = 10*a + firstWord[i]-'a';
        }
        for(int i = 0;i<secondWord.size();i++){
            b = 10*b + secondWord[i]-'a';
        }
        for(int i = 0;i<targetWord.size();i++){
            c = 10*c + targetWord[i]-'a';
        }
        return ((a+b)==c);
    }
};


//yxc的解答：
/*
class Solution {
public:
    int get(string s) {
        int res = 0;
        for (auto c: s)
            res = res * 10 + c - 'a';
        return res;
    }

    bool isSumEqual(string a, string b, string c) {
        return get(a) + get(b) == get(c);
    }
};
*/