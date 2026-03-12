class SmallestInfiniteSet {
public:
    // set to keep track smallest values from add Back 
    // pointer for deletion 
    // if set is empty then use the pointer value for deletion 
    set<int> values;
    int pointer;
    SmallestInfiniteSet() {
        pointer=1;
    }
    
    int popSmallest() {
        // O(1) -> O(logN)
        if(!values.size()){
            int res = pointer;
            ++pointer;
            return res;
        }
        auto res = *values.begin();
        values.erase(res);
        return res;
    }
    
    void addBack(int num) {
        // O(1) -> O(logN)
        if(num>=pointer) return;
        values.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */