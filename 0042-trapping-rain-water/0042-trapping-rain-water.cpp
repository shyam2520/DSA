class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>  stack;
        int min_height,res=0,n=height.size();
        for(int i=0;i<n;i++){
            if(!height[i]) continue;
            if(stack.empty()) stack.push(i);// idx;
            else{
                min_height=0;// max the min height of rods in between 
                while(stack.size() && height[stack.top()]<=height[i]){
                    int left = stack.top();
                    stack.pop();
                    int area = (height[left]-min_height)*(i-left-1);
                    res+=area;
                    min_height = max(min_height,height[left]);
                }
                if(stack.size()){
                    res+=(height[i]-min_height)*(i-stack.top()-1);
                }
                stack.push(i);
            }
        }
        return res;
    }
};