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
const int N = 1e3 + 9;

void solution(){
   int n; 
   cin >> n; 

   string s, r; 
   cin >> s >> r; 

   int i = 0;
   for(i = 0; i < n; i++){
      if(s[i] == '1')break;
   }

   int flag = 0;
   for(int j = 0; j <= i; j++){
      if(s[j] != r[j])flag = 1;
   }

   if(flag){
      cout << -1 << nn;
      return;
   }

   vector<int>ans;
   for(int j = i; j < n; j++){
      if(s[j] == '0'){
         s[j] = '1';
         ans.push_back(j);
      }
   }
   for(int j = n - 1; j >= 0; j--){
      if(s[j] != r[j]){
         ans.push_back(j);
      }
   }

   if(ans.empty()){
      cout << 0 << nn;
      return;
   }

   cout << ans.size() << nn;
   for(auto it : ans){
      cout << it << ' ';
   }cout << nn;
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
