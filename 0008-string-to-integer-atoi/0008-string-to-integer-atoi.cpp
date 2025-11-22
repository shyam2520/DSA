class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.length();
        long long res=0;
        bool neg=false,digit=false,sign=false;
        while(i<n && isspace(s[i])) i++;
        for(;i<n;i++){
            if(isspace(s[i])) break;
            if(s[i]=='+' || s[i]=='-') {
                if(sign || digit || res!=0) break;
                neg=s[i]=='-';
                sign=true;
            }
            else if(isdigit(s[i])){
                res=res*10+(s[i]-'0');
                res = neg?-abs(res)<INT_MIN?INT_MIN:res:res>INT_MAX?INT_MAX:res;
                digit=true;
            } 
            else break;
        }
        return neg?-res<INT_MIN?INT_MIN:-res:res>INT_MAX?INT_MAX:res;
    }
};