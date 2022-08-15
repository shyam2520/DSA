class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> dict={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int res=0;
        for(int i =0;i<s.length();i++)
        {
            if(i>0 && dict[s[i]]>dict[s[i-1]])
            {
                res-=dict[s[i-1]];
                res+=dict[s[i]]-dict[s[i-1]];
            }
            else res+=dict[s[i]];
        }
        
        return res;
    }
};