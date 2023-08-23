class Solution {
public:
    string reorganizeString(string s) {
        vector<int> dict(26,0);
        priority_queue<pair<int,char>> pq;
        for(auto& i:s) dict[i-'a']++;
        for(int i=0;i<26;i++) if(dict[i]) pq.push({dict[i],(char)(i+'a')});
        string res="A";
        pair<int,char> temp,curr;
        while(pq.size()){
            temp={-1,'A'};
            // cout<<temp.first<<" "<<temp.second<<endl;
            if(pq.top().second==res.back()){
                temp=pq.top();
                pq.pop();
            }
            if(pq.empty()) return "";
            curr=pq.top();
            pq.pop();
            res+=curr.second;
            curr.first--;
            if(curr.first) pq.push(curr);
            if(temp!=make_pair(-1,'A')) pq.push(temp);
        }
        return res.substr(1);
    }
};