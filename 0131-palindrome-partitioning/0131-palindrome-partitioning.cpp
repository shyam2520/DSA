class Solution {
public:
    vector<vector<string>> res;
    bool isPalindrome(string &s,int st,int end){
        while(st<end && s[st]==s[end]){
            st++;
            end--;
        }
        return st>=end;
    }
    void part(string& s,int start,int end,vector<string> temp){
        if(end==s.size()){
            if(start==end) res.push_back(temp);
            return;
        } 
        // 1- s to e is palindrome consider or expand window
        if(isPalindrome(s,start,end)){
            //consider string
            temp.push_back(s.substr(start,end-start+1));
            part(s,end+1,end+1,temp);
            temp.pop_back();
            part(s,start,end+1,temp);
            return;
        }

        // s to e not palindrome expand window
        part(s,start,end+1,temp);
    }
    vector<vector<string>> partition(string s) {
        part(s,0,0,{});
        return res;
    }
};