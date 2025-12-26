class Solution {
public:
    vector<string> ans;
    vector<string> addOperators(string num, int target) {
        dfs(num,0,0,0,"",target);
        return ans;
    }

    void dfs(string& num,int curr_idx,long resSoFar,long prevVal,string path,int target){
        if(curr_idx==num.size()){
            if(target==resSoFar){
                ans.push_back(path);
            }
            return;
        }

        for(int i=curr_idx;i<num.size();i++){
            string curr_val = num.substr(curr_idx,i-curr_idx+1);
            long curr_num = stol(curr_val);
            if(num[curr_idx]=='0' && i>curr_idx) break;
            if(curr_idx==0){
                dfs(num,i+1,curr_num,curr_num,curr_val,target);
            }
            else{
                // +
                dfs(num,i+1,resSoFar+curr_num,curr_num,path+"+"+curr_val,target);
                // - 
                dfs(num,i+1,resSoFar-curr_num,-curr_num,path+"-"+curr_val,target);
                // *
                dfs(num,i+1,resSoFar-prevVal+prevVal*curr_num,prevVal*curr_num,path+"*"+curr_val,target);
            }
        }


    }
};