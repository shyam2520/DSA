class Solution {
public:
    int countSubstrings(string s) {
        string temp,temprev;
        int count=0;
           for(int i=0;i<s.length();i++)
           {
               for(int j=i+1;j<=s.length();j++)
               {
                   // temp=s.substr(i,j-i);
                   if(validpal(s,i,j-1)) count++;
               }
           }
        return count;
    }
    
    bool validpal(string& temp,int i,int j)
    {
        // int i=0,j=temp.length()-1;
        while(i<j)
        {
            if(temp[i]!=temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};