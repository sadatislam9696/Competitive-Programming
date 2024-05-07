/***    Bismillahir Rahmanir Rahim    ***/
 
#include<bits/stdc++.h>
using namespace std;
 
#define     nn          '\n'
#define     ll          long long
#define     ld          long double
#define     ss          second
#define     ff          first
#define     yes         cout << "Yes" << nn
#define     no          cout << "No" << nn
#define     A           cout << "Alice" << nn
#define     B           cout << "Bob" << nn
#define     pi          3.1415926536
#define     sp(n,d)     fixed << setprecision(d) << n
#define     srt(v)      sort(v.begin(),v.end());
#define     rsrt(v)     sort(v.rbegin(),v.rend());
#define     rev(v)      reverse(v.begin(),v.end());
#define     mem(a, x)   memset(a , x ,sizeof a)
 
int dx[6] = {0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 1, -1};
 
const int M = 1e9 +  7;
const int N = 2e5 + 9;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    cin >> test;
    while(test--){
      int n;
      cin >> n;

      int a[n + 1], vis[n + 1], cnt = 0;
      vector<pair<int, int>>v, ans, v1;
      for(int i = 1; i <= n; i++){
        cin >> a[i];
        vis[i] = 0;
        v.push_back({a[i], i});
      }

      sort(v.begin(), v.end());

      for(int i = 0; i < v.size(); i++){
        for(int j = i + 1; j < v.size(); j++){
            if(v[i].ff != v[j].ff){
                ans.push_back({v[i].ss, v[j].ss});
            }
        }
      }

      if(ans.size() == 0){
        cout << "NO" << nn;
      }
      else{
        cout << "YES" << nn;
        for(auto it : ans){
        if(!vis[it.ff] or !vis[it.ss]){
            cout << it.ff << ' ' << it.ss << nn;
            vis[it.ff]++;
            vis[it.ss]++;
         }
        }
      }
    }
    return 0;
}
