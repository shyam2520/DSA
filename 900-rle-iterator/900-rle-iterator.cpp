class RLEIterator {
    int ptr;
    vector<int> arr;
    
public:
    RLEIterator(vector<int>& encoding) {
        ptr=0;
        arr=encoding;
    }
    
    int next(int n) {
        if(ptr>=arr.size()) return -1;
        if(arr[ptr]-n>0)
        {
            arr[ptr]-=n;
            return arr[ptr+1];
        }
        int val=-1;
        while(n && ptr<arr.size()-1)
        {
            if(arr[ptr]<n)
            {
                n-=arr[ptr];
                arr[ptr]=0;
                val=-1;
                ptr+=2;

            }
            else if(arr[ptr]>=n)
            {
                arr[ptr]-=n;
                n=0;
                val=arr[ptr+1];
            }
            
        }
        return val;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */