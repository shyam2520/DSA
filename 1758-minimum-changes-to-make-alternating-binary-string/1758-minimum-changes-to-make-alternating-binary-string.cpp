class Solution {
public:
    int operations(string& s,char ch){
        int cnt=0;
        for(int i=0;i<s.length();i++){
            cnt+=s[i]==ch?0:1;
            ch=ch=='1'?'0':'1';
        }
        return cnt;
    }

    int minOperations(string s) {
        return min(
            operations(s,'0'),
            operations(s,'1')
        );
    }
};