class Solution {
public:
    bool checkValidString(string s) {
        int min_bracs = 0, max_bracs = 0;
        int n = s.length(); 
        for(int i=0;i<n;i++){
            if(s[i]=='(') {
                min_bracs++;
                max_bracs++;
            }
            else if(s[i]==')'){
                min_bracs--;
                max_bracs--;
            }
            else{
                min_bracs--;
                max_bracs++;
            }
            if(min_bracs<0) min_bracs=0;
            if(max_bracs<0) return false;
        }
        return min_bracs==0;
    }
};