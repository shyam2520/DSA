class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // take a sliding window from  size - k 
        // total - sliding window = points take from end 
        int l=0,wndw=cardPoints.size()-k;
        int points = 0,wpoints=INT_MAX;
        for(int i=0;i<cardPoints.size();i++){
            if((i-l+1)<=wndw) points+=cardPoints[i];
            else{
                points-=cardPoints[l++];
                points+=cardPoints[i];
            }
            if(i-l+1==wndw) wpoints=min(points,wpoints);
        }
        int total=0;
        for(auto& i:cardPoints) total+=i;
        return total-wpoints;
    }
};