class Solution {
public:
    vector<string> res;
    void combinations(string& digits,int idx, string comb,vector<string>& dict){
        if(idx==digits.size()) {
            res.push_back(comb);
            return ;
        }

        for(auto& ch:dict[digits[idx]-'0']){
            comb.push_back(ch);
            combinations(digits,idx+1,comb,dict);
            comb.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> dict = {"","","abc","def","ghi","jkl","mno","pqrs",
                          "tuv","wxyz"};
        combinations(digits,0,"",dict);
        return res;
    }
};