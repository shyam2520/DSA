class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int maxLeft=0,maxRight=0;
        int area = 0;
        while(l<r){
            if(height[l]<=height[r]){
                area+=max(0,maxLeft-height[l]);
                maxLeft=max(maxLeft,height[l]);
                l++;
            }
            else{
                area+=max(0,maxRight-height[r]);
                maxRight=max(maxRight,height[r]);
                r--;
            }
        }
        return area;
    }
};