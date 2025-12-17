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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> mat(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0) {
                    mat[i][j]=matrix[i][j]-'0';
                }
                else{
                    int val=matrix[i][j]-'0';
                    if(val){
                        mat[i][j]=val+mat[i-1][j];
                    }
                    else mat[i][j]=val;
                }
            }
        }
        int res=0;
        for(int i=0;i<m;i++){
            res=max(res,largestRectangleArea(mat[i]));
        }

        return res;
    }
};