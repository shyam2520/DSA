class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string temp="";
        stringstream ss(s);
        while(ss>>temp){
            int n=temp.length();
            res= temp + " " + res;
        }
        res.pop_back();
        return res;
    }
};