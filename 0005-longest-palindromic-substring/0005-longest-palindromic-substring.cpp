class Solution {
public:
    bool valid_palindrome(string& s,int i,int j){
        while(i<j && s[i]==s[j]){
            i++;
            j--;
        }
        return i>=j;
    }
    string longestPalindrome(string s) {
        if(s.length()==1) return s;
        int res=0;
        int st=-1,end=-1;
        for(int i=0;i<s.length();i++){
            for(int j=i+1;j<s.length();j++){
                if(valid_palindrome(s,i,j)) {
                    if(j-i+1>res){
                        st=i;
                        end=j;
                        res=j-i+1;
                    }
                }
            }
        }
        // cout<<res<<endl;
        return res==0?string(1,s[0]):s.substr(st,end-st+1);
    }
};