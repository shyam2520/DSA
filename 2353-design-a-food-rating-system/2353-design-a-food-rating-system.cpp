class FoodRatings {
    unordered_map<string,map<int,set<string>>> dict;
    unordered_map<string,pair<string,int>> food_cuisine;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<cuisines.size();i++)
        {
            dict[cuisines[i]][ratings[i]].insert(foods[i]);
            food_cuisine[foods[i]]={cuisines[i],ratings[i]};
        }
        
        for(auto& i:dict)
        {
            // cout<<" "<<i.first<<endl;
            for(auto& j:i.second)
            {
                cout<<j.first<<endl;
                for(auto& k:j.second) cout<<k<<endl;
            }
            cout<<endl<<endl;
        }
    }
    
    void changeRating(string food, int newRating) {
        string cus=food_cuisine[food].first;
        int r=food_cuisine[food].second;
        // cout<<"rating : "<<r<<" "<<food<<endl;
        dict[cus][r].erase(food);
        if(!(dict[cus][r].size())) dict[cus].erase(r);
        food_cuisine[food]={cus,newRating};
        dict[cus][newRating].insert(food);

    }
    
    string highestRated(string cuisine) {
        return *(dict[cuisine].rbegin()->second.begin());
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */