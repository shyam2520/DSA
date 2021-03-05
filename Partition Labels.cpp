class Solution {
public:
    vector<int> partitionLabels(string S) 
    {
        vector<int> charidx(26,0);
        for(int i=0;i<S.length();i++) charidx[S[i]-'a']=i;
        int start=0,end=-1;
        vector<int> res;
        for(int i=0;i<S.length();i++)
        {
            end=max(end,charidx[S[i]-'a']);
            if(i==end)
            {
                res.push_back(end-start+1);
                start=end+1;
            }
        }
        return res;
        
    }
};