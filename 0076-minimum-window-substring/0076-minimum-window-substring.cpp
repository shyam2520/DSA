class Solution {
public:

    bool isValid(vector<int>& dicts,vector<int>& dictt){
        int cnt=0;
        for(int i=0;i<52;i++){
            // if(dictt[i]==0) continue;
            // if(dicts[i]>dictt[i]) cnt++;
            if(dicts[i]<dictt[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int m=s.length(),n=t.length(),res_len = INT_MAX;
        if(n>m) return "";
        string res = "";
        vector<int> sdict(52),tdict(52);
        char ch;

        // dict for t
        for(int i=0;i<n;i++){
            ch=t[i];
            if(isupper(ch)) tdict[(ch-'A')+26]++;
            else tdict[ch-'a']++;
        }  

        // dict for s +window
        int anc=0;
        for(int i=0;i<m;i++){
            ch=s[i];
            if(isupper(ch)){
                sdict[(ch-'A')+26]++;
            } 
            else{
                sdict[ch-'a']++;
            } 
            int prev_anc=-1;
            while(isValid(sdict,tdict)){
                prev_anc=anc;
                if(isupper(s[anc])) sdict[(s[anc]-'A')+26]--;
                else sdict[s[anc]-'a']--;
                anc++;
            }
            if(prev_anc!=-1){
                anc=prev_anc;
                if(isupper(s[anc])) sdict[(s[anc]-'A')+26]++;
                else sdict[s[anc]-'a']++;
            } 
            if(prev_anc!=-1 && (i-anc+1)<res_len){
                res=s.substr(anc,i-anc+1);
                res_len=res.size();
            }
        }

        return res;
    }
};