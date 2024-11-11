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

int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

const int M = 1e9 + 7;
const int N = 1e6 + 9;

int p1 = 137, p2 = 277, mod1 = 1e9 + 7, mod2 = 1e9 + 9;

int power(ll n, ll k, int mod){
  int ans = 1 % mod; 
  if(n < 0)n += mod;
  while(k){
    if(k & 1){
      ans = 1LL * ans * n % mod;
    }
    n = 1LL * n * n % mod;
    k >>= 1;
  }
  return ans;
}
int ip1, ip2;
pair<int, int>pw[N], ipw[N];
void pre(){
    pw[0] = {1, 1};
    for(int i = 1; i < N; i++){
        pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    }
    ipw[0] = {1, 1};
    ip1 = power(p1, mod1 - 2, mod1);
    ip2 = power(p2, mod2 - 2, mod2);
    for(int i = 1; i < N; i++){
      ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
      ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
    }
}

pair<int, int> string_has(string s){
  int hs1 = 0, hs2 = 0;
  for(int i = 0; i < s.size(); i++){
    hs1 += 1LL * s[i] * pw[i].first  % mod1;
    hs1 %= mod1;
    hs2 += 1LL * s[i] * pw[i].second  % mod2;
    hs2 %= mod2;
  }
  return {hs1, hs2};
}

pair<int, int>pref[N];
void build(string s){
  for(int i = 0; i < s.size(); i++){
    pref[i].first = 1LL * s[i] * pw[i].first % mod1;
    if(i)pref[i].first = (1LL * pref[i].first + pref[i - 1].first) % mod1;
    pref[i].second = 1LL * s[i] * pw[i].second % mod2;
    if(i)pref[i].second = (1LL * pref[i].second + pref[i - 1].second) % mod2;
  }
}

pair<int, int> geting_has(int i, int j){
  pair<int, int>hs({0, 0});
  hs.first = pref[j].first;
  if(i)hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
  hs.first = (1LL * hs.first * ipw[i].first) % mod1;
  hs.second = pref[j].second;
  if(i)hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
  hs.second = (1LL * hs.second * ipw[i].second) % mod2;
  return hs;
}

void solution(){
   string s; 
   cin >> s;
   build(s); 
   int n = s.size();

   ll ans = 0;
   for(int len = 1; len <= (n / 2); len++){
     bool ok = true;
     for(int i = 0; i + len - 1 < n; i += len){
       ok &= geting_has(i, i + len - 1) == geting_has(0, len - 1);
     }
     ans += ok; 
   }
   cout << ans << nn;
 }
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    pre();

    int t = 1, c = 1;
    //cin >> t;
    //cin.ignore();
    while(t--){
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
