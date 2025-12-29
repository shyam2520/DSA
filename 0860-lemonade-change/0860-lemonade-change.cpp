class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0,twenty=0,n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5) five++;
            else if(bills[i]==10){
                ten++;// you add 10s 
                five--;
            }
            else{
                if(ten>0) {
                    ten--;
                    five--;
                }
                else five-=3;
            }
            if(five<0) return false;
        }
        return true;
    }
};