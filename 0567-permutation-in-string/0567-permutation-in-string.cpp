class Solution {
public:
    bool isPermutation(vector<int>& a,vector<int>& b){
        for(int i=0;i<26;i++){
            if(a[i]>b[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> dict_s1(26),dict_s2(26);
        for(auto& i:s1) dict_s1[i-'a']++;
        int anc=0;
        // window>len(s1) move anc 
        // if not check if its valid if return true 
        for(int i=0;i<s2.size();i++){
            dict_s2[s2[i]-'a']++;
            while((i-anc)+1>s1.size()){
                dict_s2[s2[anc]-'a']--;
                anc++;
            }
            if(isPermutation(dict_s1,dict_s2)) return true;
        }

        return false;
    }
};