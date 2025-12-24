class Solution {
public:
    int getCnt(vector<int>& dict){
        int cnt=0;
        for(auto& i:dict) if(i) cnt++;
        return cnt;
    }
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> dict(256,0);
        int anc=0,res=0,n=s.length();
        for(int i=0;i<n;i++){
            dict[s[i]]++;
            while(getCnt(dict)>k && anc<=i){
                dict[s[anc]]--;
                anc++;
            }
            res=max(res,i-anc+1);
        }
        return res;
    }
};