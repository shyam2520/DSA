class Solution {
public:
    using pi = pair<int,int>;
    int largestRectangleArea(vector<int>& heights) {
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
};