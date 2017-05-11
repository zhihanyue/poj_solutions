#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int L[20008];
int main()
{
    int N;
    cin >> N;
    for(int i=1;i<=N;++i)
        cin >> L[i];
    unsigned long long ans=0;
    for(;N>1;--N)
    {
        int min=INT_MAX,min_k=-1,smin=INT_MAX,smin_k=-1;
        for(int i=1;i<=N;++i)
            if(min>L[i])
            {
                smin=min;
                smin_k=min_k;
                min=L[i];
                min_k=i;
            }
            else if(smin>L[i])
            {
                smin=L[i];
                smin_k=i;
            }
        if(min_k>smin_k)
            swap(min_k,smin_k);
        L[min_k]=min+smin;
        L[smin_k]=L[N];
        ans+=min+smin;
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}
