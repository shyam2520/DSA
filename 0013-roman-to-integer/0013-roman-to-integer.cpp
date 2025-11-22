class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> dict = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int res = 0,curr=0,prev=-1;
        for(int i=0;i<s.length();i++){
            curr=dict[s[i]];
            if(i>0 && curr>prev){
                curr-=prev;
                res-=prev;
            }
            res+=curr;
            prev=curr;
        }
        return res;
    }
};