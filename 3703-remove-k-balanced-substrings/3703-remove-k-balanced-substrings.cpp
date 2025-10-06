class Solution {
public:
    string removeSubstring(string s, int k) {
        string ans = "" ;
        for(auto& i:s){
            ans.push_back(i);
            int n = ans.size();
            if(n>=2*k){
                bool valid = true;
                for(int i=0;i<k;i++){
                    if(ans[n-2*k+i]!='(' || ans[n-k+i]!=')') {
                        valid=false; 
                        break;
                    }
                }
                if(valid) ans.resize(n-2*k);
            }
        }
        return ans;
    }
};