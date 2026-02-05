class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> gstack,sstack;   
        // subarray ranges = sum_of(subarray_max) - sum_of(subarr_min);
        // get nextGreater & nextSmaller elment subtract those sums; 
        int n = nums.size();
        vector<int> nge(n,-1),nse(n,-1);
        vector<long long> smax(n,-1),smin(n,-1);
        for(int i=0;i<n;i++){
            while(gstack.size() && nums[gstack.top()]<nums[i]){
                nge[gstack.top()]=i;
                gstack.pop();
            }
            gstack.push(i);
            while(sstack.size() && nums[sstack.top()]>nums[i]){
                nse[sstack.top()]=i;
                sstack.pop();
            }
            sstack.push(i);
        }
        
        for(int i=n-1;i>=0;i--){
            int ngeidx = nge[i];
            int nseidx = nse[i];
            if(ngeidx!=-1){
                long long a = (long long)nums[i]*(long long)(ngeidx-i);
                // int b = nums[ngeidx]*(n-i);
                smax[i]=a+smax[ngeidx];
            }
            else{
                smax[i]=(long long)nums[i]*(long long)(n-i);
            }

            if(nseidx!=-1){
                long long a=(long long)nums[i]*(long long)(nseidx-i);
                smin[i]=a+smin[nseidx];
            }
            else{
                smin[i]=(long long)nums[i]*(long long)(n-i);
            }
        }

        long long sum_max=0,sum_min=0;

        for(int i=0;i<n;i++){
            sum_max+=smax[i];
            sum_min+=smin[i];
        }

        return sum_max-sum_min;

    }
};