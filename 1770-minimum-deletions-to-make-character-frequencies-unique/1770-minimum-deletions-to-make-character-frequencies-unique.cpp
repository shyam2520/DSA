class Solution {
public:
    int minDeletions(string s) {
        vector<int> dict(26,0);
        int n=s.length();
        vector<int> filled(n+1,0);
        for(auto& i:s) dict[i-'a']++;
        for(auto& i:dict) if(i) filled[i]++;
        vector<int> spaces;
        int res=0;
        for(int i=0;i<n+1;i++){
            if(!filled[i]) spaces.push_back(i);
            // cout<<spaces.size()<<endl;
            while(filled[i]>1){
                if(!spaces.size()){
                    res+=i*(filled[i]-1);
                    filled[i]=1;
                }
                else{
                int top=spaces.back();
                spaces.pop_back();
                res+=i-top;
                filled[i]--;

                }
            }
        }

        return res;
    }
};