#include<bits/stdc++.h>
using namespace std;
#define I INT_MAX
int main(){
    int am[8][8]=
    {
        {I,I,I,I,I,I,I,I},
        {I,I,25,I,I,I,5,I},
        {I,25,I,12,I,I,I,10},
        {I,I,12,I,8,I,I,I},
        {I,I,I,8,I,15,I,14},
        {I,I,I,I,16,I,20,18},
        {I,5,I,I,I,20,I,I},
        {I,I,10,I,14,18,I,I}
    };
    int min =I;
    int u,v;
    int near[8]={I,I,I,I,I,I,I,I};
    int t[2][6];
    for (int i = 1; i < 8; i++)
    {
        for (int j = i; j < 8; j++)
        {
            if(am[i][j]<min)
            {
                min=am[i][j];
                u=i;
                v=j;
            }
        }
    }
    near[u]=0;
    near[v]=0;
    t[0][0]=u;
    t[1][0]=v;
    cout<<min<<endl;
    int k;
    for(int i=1;i<8;i++){
        if(near[i] !=0 && am[i][u]<am[i][v])
        {
            near[i]=u;
        }
        else if(near[i] !=0 )
        {
            near[i]=v;

        }
    }
    for (int i = 1; i < 7-1; i++)
    {
        min=I;
        for (int j = 1; j < 8; j++)
        {
            if(am[j][near[j]]<min)
            {
                min=am[j][near[j]];
                k=j;

            }
        }
        t[0][i]=k;
        t[1][i]=near[k];
        near[k]=0;
        for (int i = 1; i < 8; i++)
        {
            if(near[i]!=0 && am[i][near[i]]>am[i][k])
            {
                near[i]=k;
            }
            /* code */
        }
        
        
    }
    for (int i = 0; i < 6; i++)
    {
        cout<<t[0][i]<<'-'<<t[1][i]<<endl;
    }
    
    
    
    return 0;
}