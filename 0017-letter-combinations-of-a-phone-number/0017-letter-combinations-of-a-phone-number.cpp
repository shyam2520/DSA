class Solution {
public:
    vector<string> res;
    unordered_map<int,string> dict = {
        {2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},
        {7,"pqrs"},{8,"tuv"},{9,"wxyz"}
    };
    void generateCombs(string& digits,int idx,string temp){
        if(idx==digits.size()) {
            res.push_back(temp);
            // return res;
        }
        for(auto& ch:dict[digits[idx]-'0']){
            generateCombs(digits,idx+1,temp+string(1,ch));
        }
    }
    vector<string> letterCombinations(string digits) {
        generateCombs(digits,0,"");
        return res;
    }
};