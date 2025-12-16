class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> stack;
         int res=0;
        for(int i=0;i<heights.size();i++){
            int s =i;
            while(stack.size() && heights[stack.top().second]>heights[i]){
                pair<int,int> top=stack.top();
                int area = heights[top.second]*(i-top.first);
                res=max(res,area);
                s=min(top.first,s);
                stack.pop();
            }
            stack.push({s,i});
        }
        int n=heights.size();
        while(stack.size()){
            int area=heights[stack.top().second]*(n-stack.top().first);
            res=max(res,area);
            stack.pop();
        }
        return res;
    }
};