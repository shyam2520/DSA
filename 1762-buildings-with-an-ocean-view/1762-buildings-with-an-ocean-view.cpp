class Solution {
public:
    vector<int> findBuildings(vector<int>& height) {
        int n = height.size();
        vector<int> ans={n-1};
        int maxh = height.back();
        for(int i=n-2;i>=0;i--){
            if(height[i]>maxh){
                ans.push_back(i);
                maxh=height[i];
            }
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};