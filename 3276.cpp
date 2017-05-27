#include <iostream>
#include <algorithm>
using namespace std;

int a[5008],f[5008];

int main()
{
    int N;
    cin >> N;
    for(int i=1;i<=N;++i)
    {
        char tmpch;
        cin >> tmpch;
        a[i]=(tmpch=='F');
    }
    int ans=INT_MAX,ans_K=-1;
    for(int k=1;k<=N;++k)
    {
        int cs=0;
        for(int i=1,sum=0;i<=N;++i)
        {
            if((sum+a[i])%2==0)
            {
//                  cout << "! " << i << ' ' << k << endl;
                if(i+k-1>N)
                {
                    cs=INT_MAX;
                    break;
                }
                ++cs;
                f[i]=1;
            }
            else f[i]=0;
            if(i<=k-1)
                sum+=f[i];
            else sum=sum-f[i-k+1]+f[i];
        }
//      cout << k << ' ' << cs << endl;
        if(ans>cs)
        {
            ans=cs;
            ans_K=k;
        }
    }
    cout << ans_K << ' ' << ans << endl;
//  system("pause");
    return 0;
}
