class Solution {
public:
    string alienOrder(vector<string>& words) {
        // 1.Take each word compare the characters , if character don't match that becomes directed graph from A->B 
        // 2.Then do topo sort , if the res != unique words then its invalid else you would have the correct order 
        vector<vector<int>> adjMat(26);
        vector<int> indegree(26,-1);
        for(auto& wrd:words){
            for(auto& ch:wrd){
                indegree[ch-'a']=0;
            } 
        }
        string ans = "";
        for(int i=1;i<words.size();i++){
            string curr = words[i]; 
            string prev = words[i-1]; 
            int j=0,k=0; 
            if(prev.size()>curr.size() && prev.compare(0,curr.size(),curr)==0){
                return "";
            }
            while(j<curr.size() && k<prev.size() && curr[j]==prev[k]){
                j++;k++; 
            }
            if(j==curr.size() || k==prev.size()) {
                // for(auto& ch:curr) ans.push_back(ch); 
                continue;
            } 
            adjMat[prev[k]-'a'].push_back(curr[j]-'a');
            // if(indegree[curr[j]-'a']==-1) indegree[curr[j]-'a']=0;
            // if(indegree[prev[k]-'a']==-1) indegree[prev[k]-'a']=0;
            indegree[curr[j]-'a']++;
        }

        queue<int> q; 
        int unique_cnt=0;
        for(int i=0;i<26;i++) {
            if(indegree[i]!=-1) unique_cnt++; 
            if(indegree[i]==0) q.push(i);
        } 

        // string ans = "";
        while(q.size())
        {
            int front = q.front(); 
            q.pop(); 
            ans.push_back((char)(front+'a'));
            for(auto& n:adjMat[front]){
                indegree[n]--; 
                if(!indegree[n]) q.push(n);
            }
        }
        return ans.size()==unique_cnt?ans:"";
    }
};