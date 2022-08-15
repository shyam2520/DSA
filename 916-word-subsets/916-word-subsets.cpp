class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> bset(26);
        for(int i=0;i<B.size();i++)
        {
            // cout<<B[i];
            vector<int> subset(26,0);
            for(auto& j:B[i])
                subset[j-'a']++;
            // for(int i=0;i<26;i++)
            //     if(subset[i]) cout<<i<<" "<<subset[i]<<endl;
            for(int j=0;j<26;j++)
            {
                if(subset[j])
                    bset[j]=max(bset[j],subset[j]);
            }
        }
        // for(int i=0;i<26;i++)
        // {
        //     if(bset[i]) 
        //         cout<<char(i+'a')<<" "<<bset[i]<<endl;
        // }
        
        vector<string> ans;
        for(int i=0;i<A.size();i++)
        {
            vector<int> word;
            word=createvect(A[i]);
            for(int j=0;j<26;j++)
            {
                if(bset[j] && bset[j]>word[j])
                {
                    A[i]="";
                    break;
                }
                    
            }
        }
        for(int i=0;i<A.size();i++) 
            if(A[i].size()) ans.push_back(A[i]);
        return ans;
    }
    vector<int> createvect(string& word)
    {
        vector<int> stringtoint(26,0);
        for(auto& i:word)
            stringtoint[i-'a']++;
        return stringtoint;
    }
};