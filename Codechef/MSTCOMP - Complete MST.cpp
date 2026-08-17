/***   Bismillahir Rahmanir Rahim   ***/

#include<bits/stdc++.h>
using namespace std;

#define     nn          '\n'
#define     ss          second
#define     ff          first
#define     sp(d, n)    fixed << setprecision(d) << n
#define     srt(v)      sort(v.begin(),v.end());
#define     rsrt(v)     sort(v.rbegin(),v.rend());
#define     rev(v)      reverse(v.begin(),v.end());
#define     mem(a, x)   memset(a, x, sizeof a)
#define     yes         cout << "YES" << nn
#define     no          cout << "NO" << nn

using ll =  long long;
using ld =  long double;
using ull = unsigned long long;
const ld pi = acos(-1.0);
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

int dx[6] = {0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 1, -1};

const int M = 1e9 + 7;
const int N = 2e9 + 9;

void solution(){
   ll n, m; 
   cin >> n >> m; 

   ll zero = abs(((1ll * n * (n - 1)) / 2) - m);
   ll one = m; 

   if(zero == 0){
      cout << n - 1 << nn;
      return;
   }

   ll need = n - 1; 
   ll mn = 0;
   if(zero >= need)mn = 0;
   else mn = need - zero;

   ll l = 1, r = N, ans = 0;
   while(l <= r){
      ll mid = (1LL * l + r) / 2; 

      ll x = (1ll * mid * (mid - 1)) / 2;
      ll y = (x - (mid - 1)) + 1;
      if(zero >= y and zero <= x){
         ans = mid;
         break;
      }
      else if(zero > x){
         l = mid + 1;
      }
      else r = mid - 1;
   }
   
   ll mx = (need - ans) + 1;

   ll sum = ((1ll * mx * (mx + 1)) / 2); 
   if(mn != 0) sum -= (1ll * (mn) * (mn - 1)) / 2;
   cout << sum << nn;
}
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t = 1, c = 1;
    cin >> t;
    //cin.ignore();
    while(t--){
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
