class Solution {
public:
    vector<string> res;
    
    bool leadingzeores(string& temp){
        int i=0,cnt=0;
        while(i<temp.size() && temp[i]=='0' && cnt<2) {
            cnt++;
            i++;
        } 
        return cnt>1||(cnt&& temp.back()!='0');
    }
    void recursion(
    string& nums,int target,int idx,string ans,long long resSoFar,long long prev
    )
    {
        // if(resSoFar>)
        if(idx==nums.size()){
            if(resSoFar==target) res.push_back(ans);
        }
        // slice integer till end
        int n = nums.size();
        for(int i=idx;i<n;i++){
            string curr=nums.substr(idx,i-idx+1);
            long long curr_val = stoll(curr);
            if(curr.size() && leadingzeores(curr)) {
                return;
            } 
            if(!ans.size() ) {
                recursion(nums,target,i+1,curr,curr_val,curr_val);
            }
            else{
                recursion(nums,target,i+1,ans+"+"+curr,resSoFar+curr_val,curr_val);
                recursion(nums,target,i+1,ans+"-"+curr,resSoFar-curr_val,-curr_val);
                recursion(nums,target,i+1,ans+"*"+curr,
                resSoFar-prev+(prev*curr_val),prev*curr_val);

            }

        }

    }

    vector<string> addOperators(string num, int target) {
        // 2*3*4 -> prev = has to be 6 
        // 123 -> write loop to create substring 
        // 1. how to recogonise that leading 0s 
        recursion(num,target,0,"",0,0);
                //num,tar,ans,idx,res,prev
        return res;
    }
};