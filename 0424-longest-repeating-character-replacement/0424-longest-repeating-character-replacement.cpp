class Solution {
public:
    int getMaxCnt(vector<int>& dict){
        int max_val=0;
        for(auto& i:dict) max_val=max(max_val,i);
        return max_val;
    }
    int characterReplacement(string s, int k) {
        // 1. l ,r for keep track of window 
        // 2. at each iteration update dict , get the max cnt 
        // 3. window - maxcnt = replacint chars (rc)
        // 4. if rc>k update l++, else ignore 
        // 5. keep track of max window 
        int l=0;
        vector<int> dict(26,0);
        int res=0;
        for(int i=0;i<s.size();i++){
            dict[s[i]-'A']++;
            while(true){
                int maxcnt=getMaxCnt(dict);
                int diff_chrs=(i-l)+1 - maxcnt;
                if(diff_chrs>k){
                    dict[s[l]-'A']--;
                    l++;
                } 
                else break;
            }
            res=max(res,i-l+1);
        }
        return res;
    }
};