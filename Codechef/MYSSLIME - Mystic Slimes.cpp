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

using ll =  long long;
using ld =  long double;
using ull = unsigned long long;
const ld pi = acos(-1.0);
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

int dx[6] = {0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 1, -1};

const int M = 1e9 + 7;
const int N = 1e3 + 9;

void solution(){
   int n; 
   cin >> n; 

   int a[n + 1];
   int mx = -1 ;
   for(int i = 1; i <= n; i++){
      cin >> a[i];
      mx = max(a[i], mx);
   }

   if(n == 2){
      cout << abs(a[1] - a[2]) << nn;
   }
   else if(n == 3){
      if(mx == a[1] or mx == a[3]){
         cout << mx << nn;
      }
      else{
         int x = abs(abs(a[2] - a[3]) - a[1]);
         int y = abs(abs(a[2] - a[1]) - a[3]);
         cout << max({x, y, a[1], a[3]}) << nn;
      }
   }
   else{
      for(int i = 1; i <= n; i++){
         if(a[i] == mx and i != 2 and i != n - 1){
            cout << mx << nn;
            return;
         }
      }
      int ans = 0;
      for(int i = 3; i <= (n - 2); i++){
         ans = max(ans, a[i]);
      }
      int x = abs(a[2] - a[1]);
      int y = abs(a[n] - a[n - 1]);

      cout << max({ans, x, y, a[1], a[n]}) << nn;
   }

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
