class StockSpanner {
public:
    vector<int> pge;
    vector<int> prices;
    StockSpanner() {
    }
    
    int next(int price) {
        int idx=pge.size()-1;
        while(pge.size() && price>=prices[idx]){
            idx=pge[idx];
        }
        prices.push_back(price);
        pge.push_back(idx);
        return prices.size()-(pge.back()+1);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */