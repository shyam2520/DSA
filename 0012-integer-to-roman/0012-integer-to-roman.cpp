class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,char> dict = {
            {1,'I'},
            {5,'V'},
            {10,'X'},
            {50,'L'},
            {100,'C'},
            {500,'D'},
            {1000,'M'}
        };
        string n=to_string(num);
        string res="";
        for(int i=0;i<n.length();i++){
            int val = n[i]-'0';
            int units = pow(10,n.length()-i-1);
            if(val<4){
                res+=string(val,dict[units]);
            }
            else if(val>=5 && val<9){
                int mod = val%5;
                res+=string(1,dict[5*units])+string(mod,dict[units]);
            }
            else if(val==4){
                res+=string(1,dict[units]) + string(1,dict[5*units]);
            }
            else if(val==9){
                res+=string(1,dict[units]) + string(1,dict[10*units]);
            }
        }
        return res;
    }
};