class Solution {
public:
    bool f_not(string& s,int& idx){
        idx+=2; 
        bool res=f(s,idx); 
        idx++;
        return !res;
    }

    bool f_and(string& s,int& idx){
        idx+=2;
        bool res = true&f(s,idx);
        while(s[idx]!=')'){
            idx++;
            res&=f(s,idx);
        }
        idx++;
        return res;
    }

    bool f_or(string& s,int& idx){
        idx+=2;
        bool res = false | f(s,idx);
        while(s[idx]!=')'){
            idx++;
            res|=f(s,idx);
        }
        idx++;
        return res;
    }

    bool f(string& s,int& idx){
        if(s[idx]=='t'){
            idx++;
            return true;
        }
        if(s[idx]=='f'){
            idx++;
            return false;
        }
        if(s[idx]=='!'){
            return f_not(s,idx);
        }
        if(s[idx]=='|') return f_or(s,idx);
        return f_and(s,idx);
    }

    bool parseBoolExpr(string exp) {
        int idx =0;
        return f(exp,idx);
    }
};