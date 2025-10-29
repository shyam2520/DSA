class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        map<int,int> dict;
        sort(nums.begin(),nums.end());
        for(auto& i:queries) dict[i]=INT_MIN;
        int sum=0;
        int cnt=0;
        for(auto& i:nums){
            sum+=i;
            // cout<<sum<<endl;
            ++cnt;
            auto it = dict.lower_bound(sum);
            while(it!=dict.end()) {
                dict[it->first]=cnt;
                it++;
            }
        }
        vector<int> res(queries.size(),0);
        cnt=0;
        for(int i=0;i<queries.size();i++){
            if(dict[queries[i]]!=INT_MIN) {
                cnt++;
                res[i]=dict[queries[i]];
            }
            else continue;
        }

        if(!cnt) return {0};
        return res;
    }
};