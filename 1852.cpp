#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int M;
    cin >> M;
    for(int k=1;k<=M;++k)
    {
        int len,N;
        cin >> len >> N;
        int ans1=0,ans2=0;
        for(int i=1;i<=N;++i)
        {
            int a;
            cin >> a;
            if(a<=len/2)
            {
                ans1=max(ans1,a);
                ans2=max(ans2,len-a);
            }
            else
            {
                ans1=max(ans1,len-a);
                ans2=max(ans2,a);
            }
        }
        cout << ans1 << ' ' << ans2 << endl;
    }
    //system("pause");
    return 0;
}
