
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main(){
    vector<string> match;
    int n;
    cout<<"Enter the number of teams";
    cin>>n;
    n=(n*(n-1))/2;
    string s,temp;
    unordered_map<string,int> points;
    for(int i=0;i<n;i++){
         std::getline(std::cin>>std::ws,s);
        match.push_back(s);
    }
    for(int i=0;i<match.size();i++){
        istringstream iss(match[i]);
        vector<string> temp;
        do{
            string val;
            iss>>val;
            temp.push_back(val);
        }while(iss);
        // points[temp[0]]+=int(temp[2][0])-int('0');
        // points[temp[1]]+=int(temp[2][2])-int('0');
        int team1=int(temp[2][0])-int('0');
        int team2=int(temp[2][2])-int('0');
        if(team1>team2){
            points[temp[0]]+=3;
            points[temp[1]]+=0;
        }
        else if(team1==team2)
        {
            points[temp[0]]+=1;
            points[temp[1]]+=1;
        }
        else{
            points[temp[0]]+=0;
            points[temp[1]]+=3;
        }

    }
    int max=0;
    string leader="";
    for(auto &l:points)
    {    if(l.second>max)
        {
            max=l.second;
            leader=l.first;
        }}
    cout<<leader<<" wins having "<<max;
    return 0;
}