class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        map<int,int> dict;
        for(auto& i: lights) {
            int l= i[0]-i[1];
            int r= i[0]+i[1];
            dict[l]++;
            dict[r+1]--;
            // cout<<l<<" "<<dict[l]<<endl;
            // cout<<r+1<<" "<<dict[r+1]<<endl;

        }
        int sum=0,res=0,pos=-1;
        for(auto& i:dict){
            // cout<<i.first<<" "<<i.second<<endl;
            sum+=i.second;
            // res=max(res,sum);
            if(sum>res){
                res=sum;
                pos=i.first;
            }
        }
        return pos;
    }
};