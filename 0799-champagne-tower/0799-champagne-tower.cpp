class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // vector<vector<double>> champ(101,vector<double>(101,0.0));
        vector<double> curr(101,0.0);
        vector<double> next(101,0.0);
        curr[0]=poured;
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<=i;j++){
                double glass =min(1.0,curr[j]);
                double rem = curr[j]-glass;
                curr[j]=glass;
                double split = rem/2;
                next[j]+=max(0.0,split);
                if((j+1)<next.size()) next[j+1]+=max(0.0,split);
            }
            if(i==query_row) return curr[query_glass];
            curr=next;
            next=vector<double>(101,0.0);
        }
        return curr[query_glass];

    }
};