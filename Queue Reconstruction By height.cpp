class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end());
        vector<vector<int>> ans(people.size(),vector<int> (2,-1));
        for(int i=0;i<people.size();i++)
        {
            int count = people[i][1];
            for(int j=0;j<ans.size();j++)
            {
                if(ans[j][0]==-1 && count ==0)
                {
                    ans[j][0]=people[i][0];
                    ans[j][1]=people[i][1];
                    break;
                }
                else if(ans[j][0]==-1 || ans[j][0]>=people[i][0])
                    count-=1;
            }
                
        }
        return ans;
    }
};