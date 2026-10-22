class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;
        vector<int> dict(26);
        for(auto& i:s) dict[i-'a']++;
        for(int i=0;i<26;i++){
            if(dict[i]<=0) continue;
            pq.push({dict[i],(char)(i+'a')});
        }
        string res = "";
        char prev=' ';int pcnt=0;
        while(pq.size()){
            auto [cnt,ch] = pq.top();
            // if(res.size() && res.back()==ch) return "";
            res+=ch;
            pq.pop();
            if(pcnt) pq.push({pcnt,prev});
            cnt--; 
            if(cnt>0){
                prev=ch;pcnt=cnt;
            }else{
                prev=' ';pcnt=0;
            }
            // pq.push({cnt-1,ch});
        }
        if(pcnt==1 && prev!=res.back()) res+=prev;

        return res.size()!=s.size()?"":res;
    }
};