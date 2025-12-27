class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        // ""
        // open , close
        // ) open<close 
        
        generateCombinations("",n,n);
        return res;
    }

    void generateCombinations(string path,int open,int closed){
        if(open==0 && closed==0){
            res.push_back(path);
            return;
        }
        // open>=closed , use only open 
        // else either open or closed 
        if(open>=closed){ // (,1,2
            generateCombinations(path+"(",open-1,closed);
        }
        else{// ((,0,2-> (()), (),1,1
            // open 
            if(open){
                generateCombinations(path+"(",open-1,closed);
            } 
            // closed
            generateCombinations(path+")",open,closed-1);
        }
    }

};