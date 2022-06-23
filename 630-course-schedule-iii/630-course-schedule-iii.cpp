class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i=0;i<courses.size();i++)
        {
            if(courses[i][0]>courses[i][1]) continue;
            q.push({courses[i][1],courses[i][0]});
        }
        
        int s=1;
        int res=0;
        priority_queue<pair<int,int>> gq;
        while(q.size())
        {
            // cout<<q.top().first<<" "<<q.top().second<<endl;
            if(s+q.top().second-1<=q.top().first)
            {
                // res++;
                s+=q.top().second;
                gq.push({q.top().second,q.top().first});
                
                // s++;
            }
            else if(gq.size() && s-gq.top().first+q.top().second-1<=q.top().first && gq.top().first>q.top().second)
            {
                
                // cout<<q.top().first<<","<<q.top().second<<" "<<gq.top().first<<","<<gq.top().second<<endl;

                s-=gq.top().first;
                gq.pop();
                // res++;
                
                s+=q.top().second;
                gq.push({q.top().second,q.top().first});
            }
            // cout<<"printin\n"<<gq.top().first<<endl;
            q.pop();
        }
        return gq.size();
    }
};