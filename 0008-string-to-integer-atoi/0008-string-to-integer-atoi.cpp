class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.length();
        bool sign=false,neg=false;
        long long res=0;
        while(i<n && s[i]==' ') i++;
        if(s[i]=='-' || s[i]=='+'){
            sign=true;
            neg=s[i]=='-'?true:false;
            i++;
        }
        for(;i<n && res<INT_MAX;i++){
            if(s[i]=='-' || s[i]=='+'){
                break; 
            }
            else if(isdigit(s[i])) res=res*10+(s[i]-'0');
            else break;
        }

        return neg?-res<INT_MIN?INT_MIN:-res:res>INT_MAX?INT_MAX:res;
    }
};