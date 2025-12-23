class Solution {
public:
    string simplifyPath(string path) {
        // . - curr
        // .. - parent
        //  //// - / 

        // //// word ////

        // / name 

        // stack for storing directory 
        // traverse the loop for find dir/ op name 
        // push to stack 
        // if . do nthing 
        // if .. pop dir from stck 
        // ////// home /abc/
        // / home/
        stack<string> stack;
        stack.push("/");
        int n = path.length();
        for(int i=0;i<n;i++){
            // start
            while(i<n && path[i]=='/') i++; 
            if(i==n) break;
            string op = "" ;// h
            // end of op
            while(i<n && path[i]!='/'){
                op.push_back(path[i]);
                i++;
            }
            // all operations 
            if(op=="."){
                i--;
                continue;
            }
            else if(op==".." && stack.size()){
                if(stack.top()!="/") stack.pop();
            }
            else{
                stack.push(op);
            }
            i--;
        }

        string res="";
        while(stack.size()&& stack.top()!="/"){
            res = "/"+stack.top()+res;
            stack.pop();
        }
        return res==""?"/":res;

    }
};