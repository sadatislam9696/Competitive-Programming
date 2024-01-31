#include<bits/stdc++.h>
using  namespace  std;

#define   ll long long
#define   nn      '\n'

void solve()
{
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];

    ll sum = 0;
    vector<ll>v;
    for(int i = 1; i <= n; i++)
    {
        if(i & 1) sum += a[i];
        else sum -= a[i];
        v.push_back(sum);
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < v.size() - 1; i++)
    {
        if(v[i] == v[i + 1] or v[i] == 0)
        {
            cout << "YES" << nn;
            return;
        }
    }
    cout << "NO" << nn;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
