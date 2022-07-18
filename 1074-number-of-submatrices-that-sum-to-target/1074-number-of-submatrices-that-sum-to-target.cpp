class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[0].size();j++)
                matrix[i][j]+=matrix[i][j-1];
        }
        int count=0;
        for(int c1 =0;c1<matrix[0].size();c1++)
        {
            for(int c2=c1;c2<matrix[0].size();c2++)
            {
                unordered_map<int,int> dict;
                dict[0]++;
                int sum=0;
                for(int row=0;row<matrix.size();row++)
                {
                    sum+=matrix[row][c2]-(c1>0?matrix[row][c1-1]:0);
                    count+=dict.find(sum-target)!=dict.end()?dict[sum-target]:0;
                    dict[sum]++;
                }
            }
        }
        return count;
    }
};