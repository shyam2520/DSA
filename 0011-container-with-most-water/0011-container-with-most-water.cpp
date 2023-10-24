class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int area=0;
        while(l<r){
            area=max(area,(r-l)*min(height[r],height[l]));
            if(height[r]<height[l]) r--;
            else l++;
        }
        return area;
    }
};