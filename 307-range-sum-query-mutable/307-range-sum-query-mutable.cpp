class SegmentTree {
    public : 
    int sum;
    int start,end;
    SegmentTree* left,*right;
    SegmentTree(int s,int e)
    {
        start=s;
        end=e;
        left=NULL;
        right=NULL;
        sum=0;
    }
};


class NumArray {
    int start=0;
    int size=0;
    SegmentTree* root;
public:
    SegmentTree* buildTree(vector<int>& nums,int left,int right)
    {
        if(left>right) return NULL;
        if(left==right)
        {
            SegmentTree* temp=new SegmentTree(left,right);
            temp->sum =nums[left];
            // cout<<left<<" "<<right<<" "<<temp->sum<<endl;
            return temp;
        }
        else{
            int mid =left+(right-left)/2;
            SegmentTree* node=new SegmentTree(left,right);
            node->left=buildTree(nums,left,mid);
            node->right=buildTree(nums,mid+1,right);
            
            node->sum=node->left->sum+node->right->sum;
            return node;
            
        }
    }
    NumArray(vector<int>& nums) {
        size=nums.size();
        root=buildTree(nums,0,size-1);
        // cout<<root->sum<<" "<<root->start<<" "<<root->end<<endl;
    }
    
    void SegmentSearch(int index,SegmentTree* node,int val,int start,int end)
    {
        if(node->start==index && node->end==index)
        {
            node->sum=val;
            return ;
        }
        else
        {
            int mid = start+(end-start)/2;
            if(index<=mid) SegmentSearch(index,node->left,val,start,mid);
            else SegmentSearch(index,node->right,val,mid+1,end);
            
            node->sum=node->left->sum+node->right->sum;
            
        }
    }
    void update(int index, int val) {
        SegmentTree* node=root;
        // cout<<" update : "<<node->start<<" "<<node->end<<endl;
        SegmentSearch(index,node,val,0,size-1);
    }
    
    int getSum(int left ,int right,SegmentTree* node)
    {

        if(left>right) return 0;
        // cout<<left<<" "<<right<<endl;
        if(node->start==left && node->end==right) return node->sum;
        else
        {
            int mid=node->start+(node->end-node->start)/2;
            if(left>mid) return getSum(left,right,node->right);
            else if(right<=mid) return  getSum(left,right,node->left);
            return getSum(left,mid,node->left)+getSum(mid+1,right,node->right);
        }
    }
    
    int sumRange(int left, int right) {
        // cout<<endl<<endl<<"get sum "<<root->start<<" "<<root->end<<endl;
        SegmentTree* node=root;
        return getSum(left,right,node);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */