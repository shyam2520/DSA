/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<int> cnt(n,0); //idx -> no. of ppl who knw idx
        stack<int> stack;
        for(int i=0;i<n;i++){
            int celbcnt=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(knows(i,j)){
                    cnt[j]++;
                    celbcnt++;
                }
            }
            if(!celbcnt) stack.push(i);
        }
        while(stack.size()){
            if(cnt[stack.top()]==n-1) return stack.top();
            stack.pop();
        }
        return -1;
    }
};