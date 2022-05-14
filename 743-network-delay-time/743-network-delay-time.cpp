class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n+1,INT_MAX);
        int u,v,w;
        time[k]=0;
        for(int i=0;i<n;i++)
        {
            for(auto& vec:times)
            {
                u=vec[0];
                v=vec[1];
                w=vec[2];
                if(time[u]!=INT_MAX &&  time[v]>time[u]+w)
               {
                    time[v]=time[u]+w;
                    // cout<<time[v]<<endl;
                }
            }
        }
        int res=INT_MIN;
        time[0]=INT_MIN;
        for(auto& i:time)
        {
            res=max(res,i);}
        return res==INT_MAX?-1:res;
    }
};