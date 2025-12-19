class Solution {
public:
    int getTypes(vector<int>& umap){
        int cnt=0;
        for(auto& i:umap) {
            if(i) cnt++;
        }
        return cnt;
    }
    int totalFruit(vector<int>& fruits) {
        int anc=0;
        int n=fruits.size();
        vector<int> umap(n,0);
        int res =0;
        for(int i=0;i<n;i++){
            umap[fruits[i]]++;
            while(anc<=i && getTypes(umap)>2){
                umap[fruits[anc]]--;
                anc++;
            }
            res=max(res,i-anc+1);
        }
        return res;
    }
};