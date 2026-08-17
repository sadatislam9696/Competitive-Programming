#include <bits/stdc++.h>
using   namespace   std;
#define    nn     '\n'

void solve()
{
    int n, k;
    cin >> n >> k;

    int a[n + 1];
    int c = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] >= k)
        {
            c++;
        }
    }
    if(c == 0)
    {
        cout << -1 << nn;
        return;
    }
    vector<int>v;
    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n; i++){
        if(a[i] >= k){
            v.push_back((a[i] % k));
        }
    }
    sort(v.begin(), v.end());
    cout << v[0] << nn;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;
    cin >> test;
    while(test--)
    {
        solve();
    }

    return 0;
}


/***    Input   ***
-------------------
4
4 3
7 8 2 1
4 4
1 2 3 1
4 1
1 1 1 1
4 1000
999 1500 2024 2100


***   output    ***
-------------------

1
-1
0
24
