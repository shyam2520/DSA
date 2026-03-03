class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=1;i<n;i++){
            string cpy = s;
            for(int i=0;i<cpy.size();i++) cpy[i] = cpy[i]=='0'?'1':'0';
            reverse(begin(cpy),end(cpy));
            s = s + "1" +cpy;
        }
        if(k>s.length()) k%=s.length();
        // cout<<s<<endl;
        return s[k-1];
    }
};