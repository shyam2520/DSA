class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1,j=b.size()-1;
        int sum=0,carry=0;
        string res ="";
        while(i>=0 && j>=0){
            sum=(a[i]-'0')+(b[j]-'0')+carry;
            res.push_back((char)((sum%2)+'0'));
            carry = sum/2;
            i--;j--;
        }
        while(i>=0){
            sum=(a[i]-'0')+carry;
            res.push_back((char)((sum%2)+'0'));
            carry = sum/2;
            i--;
        }
        while(j>=0){
            sum=(b[j]-'0')+carry;
            res.push_back((char)((sum%2)+'0'));
            carry = sum/2;
            j--;
        }
        if(carry) res.push_back('1');

        reverse(begin(res),end(res));
        return res;
    }
};