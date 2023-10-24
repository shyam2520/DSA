class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stack;
        int res=0,prev_height=0;
        for(int i=0;i<height.size();i++){
            if(!height[i]) continue;
            if(stack.empty()) stack.push(i);
            else if(height[stack.top()]>height[i]){
                res+=(height[i])*(i-stack.top()-1);
                stack.push(i);
            }
            else{
                prev_height=0;
                while(stack.size() && height[stack.top()]<=height[i]){
                    int h=height[stack.top()];
                    res+=(h-prev_height)*(i-stack.top()-1);
                    prev_height=max(prev_height,h);
                    stack.pop();

                }

                if(stack.size()){
                    res+=(height[i]-prev_height)*(i-stack.top()-1);
                }
                stack.push(i);
            }
        }
        return res;
    }
};