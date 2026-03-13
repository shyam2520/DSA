class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> champ(101,vector<double>(101,0.0));
        champ[0][0]=poured;
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<=i;j++){
                double glass =min((double)1,champ[i][j]);
                double rem = champ[i][j]-glass;
                champ[i][j]=glass;
                double split = rem/2;
                champ[i+1][j]+=max((double)0,split);
                if((j+1)<champ[0].size()) champ[i+1][j+1]+=max(0.0,split);
            }
        }
        return champ[query_row][query_glass];

    }
};