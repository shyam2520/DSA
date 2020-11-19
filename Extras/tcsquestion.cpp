#include<bits/stdc++.h> 
using namespace std;
int main(){
    // cout<<"enter the number of pages in first book \n";
    int fbpg,lfb,sbpg,lsb;
    cin>>fbpg;
    // cout<<"enter number of lines in first book \n";
    // int lfb;
    cin>>lfb;
    // cout<<"enter the number of pages in second book ";
    cin>>sbpg;
    // cout<<"enter number of lines in second book ";
    cin>>lsb;
    int r,w;
    cin>>r>>w;
    //reading
    int total_lines=fbpg*lfb;
    int total_line_rob=r*fbpg;
    int time=total_line_rob/r;
    int lines_left=total_lines-total_line_rob;
    int total_time=time+lines_left/r;
    int curr_time;
    cin>>curr_time;
    if(curr_time*r<total_lines)
    {
        float val=float((curr_time*r)/lfb);
        cout<<val<<"READ";
    }
    else{
        float writing=((curr_time*r)-total_lines);
        if(w>lsb)
        {
            int norm=(writing)/lsb;
            cout<<"WRITE"<<norm+writing/(w-lsb);
        }


    }

    return 0;
}   