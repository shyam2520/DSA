class Solution {
public:
    int minDeletions(string s) {
        vector<int> dict(26,0);
        for(auto& i:s) dict[i-'a']++;
        int temp,count=0;
        unordered_map<int,int> counter;
        for(int i=0;i<26;i++)
        {
            temp=dict[i];
            while(temp>0 && counter.find(temp)!=counter.end()) temp--;
            if(temp) counter[temp]++;
            count+=dict[i]-temp;
        }
        return count;
    }
};