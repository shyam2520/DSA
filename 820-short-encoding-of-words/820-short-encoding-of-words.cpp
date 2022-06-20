class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        string res="";
        sort(begin(words),end(words),[](string& a,string& b)
             {
                 return a.length()>b.length();
             });
        for(auto& i:words)
        {
            
            // cout<<i<<endl;
            int s=res.find(i);
            if(s==string::npos) 
                res+=i+"#";
            else
            {
                int j=s;
                while(res[j]!='#') j++;
                while(s!=string::npos)
                {
                    // cout<<s<<endl;
                    if(j-s==i.length()) break;
                    s=res.find(i,s+1);
                }
                if(s==string::npos) res+=i+"#";
            }
                
        }
        return res.length();
    }
};