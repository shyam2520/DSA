class Solution {
public:
    int minimumLines(vector<vector<int>>& stock) {
        if(stock.size()==1) return 0;
        sort(begin(stock),end(stock));
        char dir='k',curr='t';
        int res=0;
        long double slope=-1,newslope=-1,x,y;
        for(int i=1;i<stock.size();i++)
        {
            // cout<<stock[i][0]<<" "<<stock[i][1]<<endl;
            x=stock[i][0]-stock[i-1][0];
            y=stock[i][1]-stock[i-1][1];
            // cout<<"points \t"<<x<<" "<<y<<endl;
            newslope=y/x;
            // cout<<slope<<" "<<newslope<<endl;
            if(x==0 && y!=0) curr='v';
            if(x!=0 && y==0) curr='h';
            if(x>=1 && y>=1) curr='f';
            if(x>=1 && y<0)  curr='b';
            
            if(dir!=curr) 
            {
                res++;
                dir=curr;
                slope=newslope;
            }
            else if(slope!=newslope)
            {
                res++;
                slope=newslope;
            }
            
        }
        return res;
    }
};