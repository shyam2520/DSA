class ExamTracker {
public:
    long long  total;
    map<int,pair<int,long long>> mp;
    ExamTracker() {
        total=0;
        mp.clear();
    }
    
    void record(int time, int score) {
        cout<<time<<" "<<score<<endl;
        cout<<"---"<<endl;
        total+=score; 
        mp[time]={score,total};
    }
    
    long long totalScore(int startTime, int endTime) {
        // if(!mp.count(startTime) && !mp.count(endTime)) return 0;
        long long start=0,end=0;
        if(mp.find(startTime)!=mp.end()) start=(mp[startTime].second-mp[startTime].first);
        else {
            auto it=mp.lower_bound(startTime);
            if(it==mp.begin()) start=0;
            else{
                --it; 
                start=it->second.second;
            }
        }
        
        if(startTime==endTime) return mp.count(startTime)?(long long)mp[startTime].first:0;
        // if(mp.cnt(start)) start
        
        if(mp.find(endTime)!=mp.end()) end=mp[endTime].second;
        else{
            auto it=mp.lower_bound(endTime);
            if(it==mp.end()) end=0;
            while(it!=mp.begin() && it->first>endTime){
                --it; 
                end=it->second.second;
            }
            // if(it==mp.begin() && it->val!=) return 0;
        }

        cout<<startTime<<" "<<start<<endl;
        cout<<endTime<<" "<<end<<endl;
        cout<<endl;
        return end-start;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */