class Solution {
public:
    int total_bouquets(vector<int>& days,int wait_days,int k){
        int total=0;
        for(int i=0;i<days.size();i++){
            if(days[i]>wait_days) continue;
            else{
                int anc=i;
                bool flag=false;
                for(;i<days.size();i++){
                    if(days[i]>wait_days) break;
                    if(i-anc+1==k){
                        total++;
                        break;
                    }
                }
                // for(;i<days.size() && (i-anc+1)<k;i++){
                //     if(days[i]>wait_days){
                //         flag=true;
                //         cout<<i<<endl;
                //         break;
                //     }
                // }
                // if(!flag && days[i]<=wait_days && (i-anc+1)==k){
                //     cout<<anc<<"-"<<i<<endl;
                //     total++;
                // } 
            }
        }
        // cout<<wait_days<<" "<<total<<endl;
        return total;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // if(k>bloomDay.size()) return -1;
        int l=1,r=*max_element(begin(bloomDay),end(bloomDay)),ans=-1; 
        while(l<=r){
            int mid = l+(r-l)/3;
            if(total_bouquets(bloomDay,mid,k)>=m){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};