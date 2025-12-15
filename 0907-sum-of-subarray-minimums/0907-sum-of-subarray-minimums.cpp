class Solution {
public:
    long long mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        // find NSE 
        stack<int> stack;
        vector<int> nse(arr.size(),-1);
        for(int i=0;i<arr.size();i++){
            while(stack.size() && arr[stack.top()]>arr[i]){
                nse[stack.top()]=i;
                stack.pop();
            }
            stack.push(i);
        }
        for(int i=arr.size()-1;i>=0;i--){
            int nseidx = nse[i];
            // the curr val would be the min subarray till  nse idx after that it would be that value; 
            if(nseidx!=-1){
                int sum = (arr[i]*(nseidx-i))%mod+(arr[nseidx])%mod;
                arr[i]=sum;
            }
            else {
                int sum = (arr[i]*(arr.size()-i))%mod;
                arr[i]=sum;
            }
        }

        int res =0;
        for(auto& i:arr){
            res=(res+ i)%mod;
        } 
        return res;
    }
};