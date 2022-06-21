class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> diff;
        for(int i=1;i<heights.size();i++)
        {
            if(heights[i]-heights[i-1]>0) diff.push(heights[i]-heights[i-1]);
            
            if(diff.size()>ladders)
            {
                bricks-=diff.top();
                diff.pop();
                
            }
            if(bricks<0) return i-1;
        }
        return heights.size()-1;
    }
};