, c/***   Bismillahir Rahmanir Rahim   ***/

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

  string s1, s2, s3; 
  cin >> s1 >> s2 >> s3;

  int cnt1 = 0, cnts3 = 0;
  int cnts1 = 0, cnts2 = 0;
  for(auto it : s1){
    if(it == '1'){
        cnt1++;
        cnts1++;
    }
  }
  for(auto it : s2){
    if(it == '1'){
        cnt1++;
        cnts2++;
    }
  }
  for(auto it : s3){
    if(it == '1'){
        cnt1++;
        cnts3++;
    }
  }

  int cnt0 = (3 * n) - cnt1;
  if(cnt1 % n != 0 or cnt0 % n != 0){
    cout << -1 << nn;
    return;
  }

  int mx = max({cnts1, cnts2, cnts3});
  int mn = min({cnts1, cnts2, cnts3});

  if(cnt1 == n){
     cout << n - mx << nn;
  }
  else if(cnt1 == (2 * n)){
     int x = n - mx;
     if(mx == cnts1){
        cout << x + (n - max(cnts2, cnts3)) << nn;
     }
     else if(mx == cnts2){
        cout << x + (n - max(cnts1, cnts3)) << nn;
     }
     else cout << x + (n - max(cnts1, cnts2)) << nn;
  }
  else cout << 0 << nn;
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
