class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l=0,n=cardPoints.size();
        int total=0,sum=0,res=INT_MAX;
        for(int i=0;i<n;i++)
        {
            total+=cardPoints[i];
            if(i-l+1<=n-k) sum+=cardPoints[i];
            else
            {
                sum-=cardPoints[l++];
                sum+=cardPoints[i];
            }
            if(i-l+1==n-k) res=min(res,sum);
        }
        return total-res;
    }
};