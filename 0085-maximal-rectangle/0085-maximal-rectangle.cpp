class Solution {
public:
    using pi = pair<int,int>;
    int largestRectangleArea(vector<int> heights) {
        stack<pi> st;
        heights.push_back(0);
        int n = heights.size(); 
        int res = 0;
        for(int i=0;i<n;i++){
            int idx=i;
            while(st.size() && heights[i]<st.top().first){
                auto [h,hidx] = st.top();
                st.pop();
                int area = h*(i-hidx);
                idx=hidx;
                res=max(res,area);
            }
            st.push({heights[i],idx});
        }
        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=(matrix[i][j]-'0');
                if(dp[i][j]==0) continue;
                if(i-1>=0) dp[i][j]+=dp[i-1][j];
            }
            ans = max(ans,largestRectangleArea(dp[i]));
        }
        return ans;
    }
};