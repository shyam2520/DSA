class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int anc=0;
        int n=fruits.size();
        unordered_map<int,int> umap;
        int res =0;
        for(int i=0;i<n;i++){
            umap[fruits[i]]++;
            while(anc<=i && umap.size()>2){
                umap[fruits[anc]]--;
                if(umap[fruits[anc]]==0) umap.erase(fruits[anc]);
                anc++;
            }
            res=max(res,i-anc+1);
        }
        return res;
    }
};