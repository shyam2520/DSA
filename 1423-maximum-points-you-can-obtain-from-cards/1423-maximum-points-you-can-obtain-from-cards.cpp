class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total=0;
        for(auto& i:cardPoints) {
            total+=i;
        }
        int removal_size=0,n=cardPoints.size();
        int anc=0,res=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=cardPoints[i];
            if((i-anc+1)>(n-k)){
                sum-=cardPoints[anc++];
            }
            if((i-anc+1)==(n-k)) res=max(res,total-sum);
        }
        return res;
        
    }
};