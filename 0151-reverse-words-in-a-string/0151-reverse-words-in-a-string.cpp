class Solution {
public:
    string reverseWords(string s) {
        int anc=0,n=s.length(),i=0;
        while(i<n && !isalnum(s[i])) i++;
        for(;i<n;i++){
            if(isalnum(s[i])) s[anc++]=s[i];
            else{
                s[anc++]=' ';
                while(i<n && isspace(s[i])) i++;
                i--;
            }
        }
        s.resize(anc);
        while(s.size() && isspace(s.back())) s.pop_back();
        // cout<<s<<endl;
        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
                int anc=i;
                while(i<n && isalnum(s[i])) i++;
                reverse(begin(s)+anc,begin(s)+i);
            }
        }
        reverse(begin(s),end(s));
        return s;
    }
};