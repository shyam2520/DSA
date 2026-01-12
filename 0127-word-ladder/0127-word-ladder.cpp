class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // beginWord iterate each ch 26 to to get all the matching workds & put that in a queue 
        // repeat the everytime till you reach endword 
        unordered_set<string> dict(wordList.begin(),wordList.end()); 
        if(dict.find(endWord)==dict.end()) return 0; 
        int cnt = 1; 
        queue<string> q; 
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        while(q.size()){
            int n = q.size(); 
            for(int i=0;i<n;i++){
                string word=q.front();
                q.pop();
                for(int i=0;i<word.size();i++){
                    for(int j=1;j<=26;j++){

                    string newWord=word; 
                    int ch = newWord[i]; 
                    // char c=((ch+j)%26)+(newWord[i]-'a')+'a';
                    newWord[i]=(newWord[i]+j)%26 + 'a';                   
                    if(dict.find(newWord)!=dict.end() && 
                        visited.find(newWord)==visited.end())
                    {
                        if(newWord==endWord) return cnt+1;
                        visited.insert(newWord);
                        q.push(newWord);
                    }

                    }
                } 

            }
            cnt++;
        }
        return 0;
    }

   
};