class Solution {
public: 
    int climbStairs(int n) {
        if(n<2) return 1;
        int second_prev=-1,prev=1;
        int curr=0;
        for(int i=1;i<=n;i++){
            curr=prev;
            if(i>1) curr+=second_prev;
            second_prev=prev;
            prev=curr;
        }
        return curr;
    }
};