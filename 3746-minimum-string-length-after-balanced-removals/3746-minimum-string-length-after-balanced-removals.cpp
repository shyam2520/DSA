class Solution {
public:
    int minLengthAfterRemovals(string s) {
        // string res = "";
        int acnt=0,bcnt=0;
        for(auto& ch:s){
            if(ch=='a'){
                if(bcnt) bcnt--;
                else acnt++;
            }
            else{
                if(acnt) acnt--;
                else bcnt++;
            }
        }
        return acnt+bcnt;
    }
};