#include <cstdio>
#include <climits>
#include <set>
#include <map>
using namespace std;
int a[1000008];
set<int> myset;
map<int,int> mymap;
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;++i)
    {
        scanf("%d",&a[i]);
        myset.insert(a[i]);
    }
    int size=myset.size(),ans=INT_MAX;
    mymap[a[1]]=1;
    for(int L=1,R=1;L<=N;++L)
    {
        while(mymap.size()<size && R<N)
        {
            ++R;
            if(mymap.find(a[R])!=mymap.end())
                ++mymap[a[R]];
            else mymap[a[R]]=1;
        }
        if(mymap.size()<size)
            break;
        ans=min(ans,R-L+1);
        if(mymap[a[L]]>1)
            --mymap[a[L]];
        else mymap.erase(a[L]);
    }
    printf("%d\n",ans);
    return 0;
}
