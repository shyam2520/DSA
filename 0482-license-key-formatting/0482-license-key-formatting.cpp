class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        // k=1 
        // n-1 to 0 & insert charge till cound of the string =k 
        string res = "";
        int cnt = 0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='-') continue;
            else{
                char ch = s[i];
                if(!isdigit(ch)) ch=toupper(s[i]);
                res.push_back(ch);
                cnt++;
            }
            if(cnt==k){
                cnt=0;
                res.push_back('-');
            }
        }
        if(res.back()=='-') res.pop_back();
        reverse(begin(res),end(res));
        return res;
    }
};