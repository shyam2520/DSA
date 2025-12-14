class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefixMax(n),suffixMax(n);
        prefixMax[0]=height[0];
        suffixMax[n-1]=height[n-1];
        int res=0;
        for(int i=1;i<n;i++){
            prefixMax[i]=max(height[i],prefixMax[i-1]);
            suffixMax[n-i-1]=max(height[n-i-1],suffixMax[n-i]);
        }
        for(int i=0;i<n;i++){
            res+=max(0,min(prefixMax[i],suffixMax[i])-height[i]);
        }
        return res;
    }
};