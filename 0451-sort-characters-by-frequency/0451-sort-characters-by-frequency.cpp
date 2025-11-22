class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> dict;
        for(auto& i:s) dict[i]++;
        vector<pair<char,int>> temp;
        for(auto& i:dict) temp.push_back({i.first,i.second});
        sort(begin(temp),end(temp),[](pair<char,int>& a,pair<char,int>& b){
            return a.second>b.second;
        });
        string res="";
        for(auto& i:temp) for(int j=0;j<i.second;j++) res.push_back(i.first);
        return res;
    }
};