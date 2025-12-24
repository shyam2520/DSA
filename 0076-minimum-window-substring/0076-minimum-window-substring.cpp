class Solution {
public:
    int getValid(vector<int>& dicts,vector<int>& dictt){
        for(int i=0;i<52;i++){
            if(dicts[i]<dictt[i]) {
                return -1;
            }
        }
        return 1;
    }
    string minWindow(string s, string t) {
        if(t.length()>s.length()) return "";
        vector<int> dicts(52),dictt(52); 
        for(auto& i:t){
            if(isupper(i)){
                 dictt[i-'A'+26]++;
            }
            else{
                 dictt[i-'a']++;
            }        
        }

        int anc=0,len=INT_MAX,l=-1,r=-1;
        string res="";
        for(int i=0;i<s.length();i++){
            if(isupper(s[i])){
                dicts[s[i]-'A'+26]++;
            } 
            else{ 
                dicts[s[i]-'a']++;
            }
            while(anc<=i && getValid(dicts,dictt)>0){
                if((i-anc+1)<len){
                    len=i-anc+1;
                    l=anc;
                    r=i;
                }
                if(isupper(s[anc])) dicts[s[anc]-'A'+26]--;
                else dicts[s[anc]-'a']--;
                anc++;    
            }  
        }
        return len!=INT_MAX?s.substr(l,len):"";
    }
};