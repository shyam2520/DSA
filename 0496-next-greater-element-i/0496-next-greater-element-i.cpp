class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> umap;
        for(int i=0;i<nums1.size();i++){
            umap[nums1[i]]=i;
        }

        stack<int> stack;
        vector<int> ans(nums1.size(),-1);
        for(int i=0;i<nums2.size();i++){
            while(stack.size() && stack.top()<nums2[i]){
                if(umap.count(stack.top()))
                {
                    int n1idx=umap[stack.top()];
                    ans[n1idx]=nums2[i];
                }
                stack.pop();
            }
            stack.push(nums2[i]);
        }
        return ans;
    }
};