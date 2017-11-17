#include <iostream>
#include <algorithm>
using namespace std;

struct eage{int from,to,d;} E[50008];
int p[20008];

int find(int x)
{
    return p[x]==x?x:(p[x]=find(p[x]));
}

bool cmp(const eage &a,const eage &b)
{
    return a.d<b.d;
}

int main()
{
    int datacnt;
    cin >> datacnt;
    while(datacnt--)
    {
        int N,M,R;
        cin >> N >> M >> R;
        for(int i=0;i<=N+M;++i)
            p[i]=i;
        for(int i=1;i<=R;++i)
        {
            int x,y,d;
            cin >> x >> y >> d;
            E[i]=(eage){x,y+N,-d};
        }
        sort(E+1,E+R+1,cmp);
        int ans=0;
        for(int i=1;i<=R;++i)
        {
            int T_f=find(E[i].from),T_t=find(E[i].to);
            if(T_f!=T_t)
            {
                p[T_f]=p[T_t];
                ans+=E[i].d;
            }
        }
        cout << (N+M)*10000+ans << endl;
    }
    return 0;
}
