class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> res(numRows);
        int idx=0,inc=1;
        if(numRows==1) return s;
        for(auto& i:s){
            // cout<<idx<<endl;
            res[idx].push_back(i);
            if(idx+1==numRows) inc=-1;
            if(idx==0) inc=1;
            idx+=inc;
        }
        string ans = "";
        for(auto& str:res) ans+=str;
        return ans;

    }
};