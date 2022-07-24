class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto& m: matrix)
        {
            int l=0,r=m.size()-1;
            if(!(m[0]<=target || m.back()>=target)) continue;
            while(l<=r)
            {
                int mid=l+(r-l)/2;
                if(m[mid]==target) return true;
                if(m[mid]>target) r=mid-1;
                else l=mid+1;
            }
        }
        return false;
    }
};