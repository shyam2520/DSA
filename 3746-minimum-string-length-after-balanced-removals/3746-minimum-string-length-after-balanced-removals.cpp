class Solution {
public:
    int minLengthAfterRemovals(string s) {
        string res = "";
        for(auto& ch:s){
            if(ch=='a'){
                if(res.size() && res.back()=='b') res.pop_back();
                else res.push_back(ch);
            }
            else{
                if(res.size() && res.back()=='a') res.pop_back();
                else res.push_back(ch);
            }
        }
        return res.size();
    }
};