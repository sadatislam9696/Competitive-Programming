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
const int N = 1e5 + 9;

 int dp[N], path[N];
void solution(){
    int n; 
    cin >> n; 
    int a[n + 1];
    for(int i = 1; i <= n; i++){
       cin >> a[i];
    } 

    for(int i = 1; i <= n; i++){
       dp[i] = 1;
       for(int j = 1; j < i; j++){
         if(a[j] < a[i]){
           if(dp[i] < (dp[j] + 1)){
             dp[i] = dp[j] + 1;
             path[i] = j;
           }
         }
       }
    }

    int mx = -1, ind = -1;
    for(int i = 1; i <= n; i++){
       if(mx < dp[i]){
         mx = dp[i];
         ind = i;
       }
    }

    cout << mx << nn;
    
    vector<int>v;
    //v.push_back(a[ind]);
    while(ind > 0){
       v.push_back(a[ind]);
       ind = path[ind];
    }
     
    rev(v);
    for(auto it : v){
       cout << it << ' ';
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
