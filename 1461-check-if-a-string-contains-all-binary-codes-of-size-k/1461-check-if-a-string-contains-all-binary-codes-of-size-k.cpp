// SC: O(2^k)
// TC: O(N)
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // int n=s.length();
        vector<bool> pvalues(pow(2,k),false);
        int pop_lbit=0;
        for(int i=0;i<k-1;i++) 
        {
            pop_lbit<<=1;
            pop_lbit|=1;
        }
        int l=0,r=0,temp=0;
        while(r<s.length())
        {
            if((r-l)+1<=k)
            {
                temp<<=1;
                temp|=(s[r]-'0');
            }
            if((r-l)+1 ==k)
            {
                pvalues[temp]=true;
                temp&=pop_lbit;
                l++;
                
            }
            r++;
        }
        for(int i=0;i<pvalues.size();i++) if(!pvalues[i]) return false;
        
        return true;
    }
};