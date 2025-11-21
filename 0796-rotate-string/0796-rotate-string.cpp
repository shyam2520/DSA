class Solution {
public:
    bool rotateString(string s, string g) {
        
        int m=s.length(),n=g.length();
        if(m!=n) return false;
        for(int i=0;i<m;i++){
            if(s[i]==g[0]){
                string starts = s.substr(i,m-i);
                string startg = g.substr(0,m-i);
                if(starts==startg) {
                    string lasts = s.substr(0,i);
                    string lastg = g.substr(m-i);
                    if( lasts==lastg) return true;
                }
            }
        }
        return false;
    }
};