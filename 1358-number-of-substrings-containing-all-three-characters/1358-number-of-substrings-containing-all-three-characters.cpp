class Solution {
public:
    int numberOfSubstrings(string s) {
        // 1. find the smallest valid window - n - i
        // 2. make window invalid if still valid keep adding extra 
        int anc=0,res=0;
        int a=0,b=0,c=0,n=s.size(); 
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            a+=ch=='a'?1:0; 
            b+=ch=='b'?1:0; 
            c+=ch=='c'?1:0;
            if(a && b && c){
                int subcnt = n-i; 
                res+=subcnt;
                char ancch = s[anc++];
                if(ancch=='a') a--;
                if(ancch=='b') b--; 
                if(ancch=='c') c--;
            }
            while(a && b && c && anc<=i ){
                res++;
                char ancch = s[anc++];
                if(ancch=='a') a--;
                if(ancch=='b') b--; 
                if(ancch=='c') c--;
            }
        }

        return res;
        
    }
};