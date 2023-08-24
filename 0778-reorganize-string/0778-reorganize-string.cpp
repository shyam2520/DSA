class Solution {
public:
    string reorganizeString(string s) {
        vector<int> dict(26);
        for(auto& i:s) dict[i-'a']++;
        int max_char=0,char_idx=0;
        // char val='';
        for(int i=0;i<26;i++){
            if(max_char<dict[i]){
                max_char=dict[i];
                char_idx=i;
                // val=(char)i+'a';
            }
        }
        if(max_char>(s.length()+1)/2) return "";
        string res;
        res.append(s.length(),' ');
        int idx=0;
        while(dict[char_idx]){
            res[idx]=(char)char_idx+'a';
            dict[char_idx]--;
            idx+=2;
        }
        for(int i=0;i<26;i++){
            while(dict[i]){
                if(idx>=s.length()) idx=1;
                res[idx]=(char)(i+'a');
                dict[i]--;
                idx+=2;
            }
        }

        return res;

    }
};