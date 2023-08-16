class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int s=0,temp;
        vector<int> res;
        map<int,int> dict;
        for(int i=0;i<nums.size();i++){
            if(i-s+1>k){
                temp=nums[s++];
                dict[temp]--;
                // cout<<temp<<" "<<dict[temp]<<endl;
                if(!dict[temp]) dict.erase(temp);
                // cout<<dict.end()->first<<endl;
            }
            dict[nums[i]]++;
            if(i-s+1==k) res.push_back((--dict.end())->first);
        }

        return res;
    }
};