class Solution {
public:
    int cntNonRepeatChar(vector<int>& dict){
        int cnt=0,max_cnt=0;
        for(auto& i:dict){
            max_cnt=max(i,max_cnt);
            cnt+=i;
        }
        return cnt-max_cnt;
    }
    int characterReplacement(string s, int k) {
        vector<int> dict(26,0);
        int res=0,anc=0;
        for(int i=0;i<s.length();i++){
            dict[s[i]-'A']++;
            while(cntNonRepeatChar(dict)>k){
                dict[s[anc]-'A']--;
                anc++;
            }
            res=max(res,i-anc+1);
        }
        return res;

    }
};