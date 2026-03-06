class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res="";
        for(auto& word:words){
            int sum = 0;
            for(auto& ch:word) sum+=weights[(ch-'a')];
            sum=sum%26;
            res.push_back('z'-sum);
        }
        return res;
    }
};