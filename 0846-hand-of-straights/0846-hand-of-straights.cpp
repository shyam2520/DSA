class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupsize) {
        map<int,int> dict;
        for(auto& i:hand) dict[i]++;
        while(dict.size()){
            auto it = dict.begin();
            int key = it->first;
            int val = it->second;
            dict[key]-=val;
            int cnt = 1;

            while(cnt<groupsize && dict.find(key+1)!=dict.end()){
                if(dict[key+1]<val) return false;
                cnt++;
                dict[key+1]-=val;
                key=key+1;
            }
            if(cnt<groupsize) return false;
            while(dict.size() && dict.begin()->second==0){
                dict.erase(dict.begin()->first);
            }
        }
        return true;
    }
};