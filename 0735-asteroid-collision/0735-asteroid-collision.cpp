class Solution {
public:
    bool checkCollision(int a,int b){
        return a>=0 && b<0;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stack;
        for(auto& ast:asteroids){
            if(stack.empty() || !checkCollision(stack.top(),ast)) stack.push(ast);
            else
            {
                int top=-1000;
                while(stack.size() && checkCollision(stack.top(),ast) && stack.top()<abs(ast)) {
                    top=stack.top();
                    stack.pop();
                }
                if(stack.empty() || !checkCollision(stack.top(),ast)){
                    stack.push(ast);
                }
                if(checkCollision(stack.top(),ast) && stack.top()==abs(ast)) stack.pop();
            }
        }

        vector<int> res;
        while(!stack.empty()) {
            res.push_back(stack.top());
            stack.pop();
        }
        reverse(begin(res),end(res));
        return res;
    }
};