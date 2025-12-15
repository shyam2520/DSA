class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int first_word=-1;
        for(int i=0;i<n;i++)
        {
            int anc=i;
            int vowel_cnt=0;
            while(i<n && s[i]!=' '){
                if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u') {
                    vowel_cnt++;
                }
                i++;
            }
            if(first_word==-1){
                first_word=vowel_cnt;
            }
            else if(first_word==vowel_cnt){
                reverse(begin(s)+anc,begin(s)+i);
            }
        }
        return s;
    }
};