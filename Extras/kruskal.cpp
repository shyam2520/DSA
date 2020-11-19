#include<bits/stdc++.h>
#define I INT_MAX
using namespace std;
int seta[8]={-1,-1,-1,-1,-1,-1,-1,-1};
void myunion(int u,int v){
    if(u<v){
        seta[v]+=seta[u];
        seta[u]=v;
        
    }
    else{
        seta[u]+=seta[v];
        seta[v]=u;
        
    }
}
int  find(int u){
    int x=u;
    while(seta[x]>0)
    {
        x=seta[x];
    }
    while(u!=x){
        int v=seta[u];
        seta[u]=x;
        u=v;
    }
    return x;
}
int main()
{
    int edgematrix[3][9]={
        {1,1,2,2,3,4,4,5,5},
        {2,6,7,3,4,7,5,7,6},
        {23,5,10,12,8,14,16,18,20}
    };
    int t[2][7];
    int included[9]={ 0};
    int i=0,u,v,k,n=7,e=9;
    while(i<n-1){
        int min=I;
        for (int i = 0; i <e ; i++)
        {
            if(included[i]!=1 && edgematrix[2][i]<min){
                min=edgematrix[2][i];
                u=edgematrix[0][i];
                v=edgematrix[1][i];
                k=i;
            }
            
        }
        if(find(u)!=find(v))
        {
            t[0][i]=u;
            t[1][i]=v;
            included[k]=1;
            myunion(find(u),find(v));
            i++;
        }
        else{
            included[k]=1;
        }
    }
    for (int i = 0; i < n-1; i++)
    {
        cout<<t[0][i]<<"-"<<t[1][i]<<endl;
    }
}