class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int> prefix;
        int ssum=0;
        int res=INT_MAX;
        for(int i =0;i<nums.size();i++)
        {
            ssum+=nums[i];
            prefix[ssum]=i;
            if(x-ssum==0) res=min(res,(int)(i+1));
            
        }
        int pssum=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            pssum+=nums[i];
            // cout<<x-pssum<<endl;
            if(prefix.find(x-pssum)!=prefix.end() && prefix[x-pssum]<i)
                res=min((int)(prefix[x-pssum]+1 + nums.size()-i),res);
            if(x-pssum==0) res=min(res,(int)(nums.size()-i));
        }
        return res==INT_MAX?-1:res;
        
    }
};