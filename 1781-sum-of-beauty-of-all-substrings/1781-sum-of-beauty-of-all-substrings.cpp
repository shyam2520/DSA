class Solution {
public:
    int getdiff(vector<int>& dict){
        int minval=INT_MAX,maxval=INT_MIN;
        for(int i=0;i<26;i++){
            if(!dict[i]) continue;
            minval=min(minval,dict[i]);
            maxval=max(maxval,dict[i]);
        }
        // cout<<maxval-minval<<endl;
        return maxval-minval;
    }
    int beautySum(string s) {
        int n=s.length();
        int res =0;
        for(int i=0;i<n;i++){
            vector<int> dict(26,0);
            dict[s[i]-'a']++;
            for(int j=i+1;j<n;j++){
                dict[s[j]-'a']++;
                res+=getdiff(dict);
            }
        }
        return res;
    }
};