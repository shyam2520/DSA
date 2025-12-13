class Solution {
public:
    int trap(vector<int>& heights) {
        // stack to push heights
        // pop only when curr height >= stack.top()
        // update inbetween to ensure  you subtract heights
        stack<int> stack;
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            if(!heights[i]) continue;
            if(stack.empty()) stack.push(i);
            else{
                int ih=0;
                while(stack.size() && heights[stack.top()]<=heights[i])
                {
                    int idx = stack.top();
                    int h = min(heights[stack.top()],heights[i]);
                    int area = max(0,(h-ih)*(i-idx-1));
                    res+=area;
                    stack.pop();
                    ih=max(ih,h);
                }
                if(stack.size()){
                    int idx = stack.top();
                    int h = min(heights[stack.top()],heights[i]);
                    int area = max(0,(h-ih)*(i-idx-1));
                    res+=area;
                    ih=max(ih,h);
                }
                stack.push(i);
            }
        }

        return res;
    }
};