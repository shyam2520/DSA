class Solution {
public:
    bool isPossible(vector<int>& target) {
       unsigned int sum=0;
        priority_queue<int> q;
        for(auto& i:target)
        {
            sum+=i;
            q.push(i);
        }
        
        int num,missing;
        while(q.top()!=1)
        {
            num=q.top();
            sum-=num;
            q.pop();
            // cout<<sum<<endl;
            if(sum>=num || sum<=0) return false;
            missing=num%sum;
            sum+=missing;
            q.push(missing?missing:sum);
            // cout<<missing<<endl;
        }
        
        return true;
    }
};