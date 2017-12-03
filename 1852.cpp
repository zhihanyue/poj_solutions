#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;


int main()
{
    int n,l,cs,mx,mi,pos;
    cin>>cs;
    while(cs--)
    {
        mx=0,mi=0;
        cin>>l>>n;
        for(int i=0;i<n;i++)
        {
            cin>>pos;
            mx=max(mx,max(pos,l-pos));
            mi=max(mi,min(pos,l-pos));
        }
        cout<<mi<<" "<<mx<<endl;
    }
    return 0;
}
