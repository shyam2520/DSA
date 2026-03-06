class Solution {
public:
    bool checkOnesSegment(string s) {
        bool noones = false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                if(noones) return false;
                noones=true;
                while(i<s.size() && s[i]=='1') i++;
            }
        }
        return true;
    }
};