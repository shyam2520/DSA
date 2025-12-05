class Solution {
public:
    vector<string> ans;
    string num;
    int target;
    vector<string> addOperators(string num, int target) {
        this->num=num;
        this->target=target;
        combinations("",0,0,0);
        return ans;
    }

    void combinations(string path,int idx,long long res,long long prev_val){
        if(idx==num.length()) {
            if(res==target) ans.push_back(path);
            return;
        }

        for(int i=idx;i<num.length();i++){
            if(i>idx && num[idx]=='0') break;
            string curr=num.substr(idx,i-idx+1);
            long long curr_val = stol(curr);
            if(idx==0){
                combinations(path+curr,i+1,curr_val,curr_val);
            }
            else{
                combinations(path+"+"+curr,i+1,res+curr_val,curr_val);
                combinations(path+"-"+curr,i+1,res-curr_val,-curr_val);
                combinations(path+"*"+curr,i+1,res-prev_val+(prev_val*curr_val),prev_val*curr_val);
            }
        }

        return;
    }
};