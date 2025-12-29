class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // o-> 0  1 
        // l -> 0<=i 
        // r -> i+1> n-1 ()
        vector<int> cpy_heights = heights;
        heights.push_back(0);
        int n = heights.size(),max_area=0;
        stack<pair<int,int>> stack;
        for(int i=0;i<n;i++){
            if(stack.empty()) {
                stack.push({heights[i],i});// heights,left 
            }
            else{
                int left_pointer = i;
                while(stack.size() && stack.top().first>heights[i]){
                    int top_height = stack.top().first;
                    int top_left = stack.top().second;
                    left_pointer = min(left_pointer,top_left);
                    stack.pop();
                    int area = top_height*(i-top_left);
                    max_area=max(max_area,area);
                }
                stack.push({heights[i],left_pointer});
            }
        }

        return max_area;
    }
};