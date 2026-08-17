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

bool find_ans(ll mid, const vector<int> &n, const vector<int> &p){
   int x = n.size(), y = p.size();
   int i = 0, j = 0;

   ll sum = 0;
   while(i < y or j < x){
     if(i < y and sum + p[i] <= mid){
        sum += p[i++];
     }
     else if(j < x){
        sum += n[j++];
        if(sum < 0) sum = 0;
     }
     else return false;
   }
   return true;
}
void solution(){
   int n; 
   cin >> n; 

   vector<int>neg, pos;
   for(int i = 1; i <= n; i++){
     int x; cin >> x; 
     if(x < 0)neg.push_back(x);
     else pos.push_back(x);
   }

   if(pos.empty()){
      cout << 0 << nn;
      return;
   }

   ll l = 0, r = 1e15, ans = 0;
   while(l <= r){
     ll mid = l + (r - l) / 2;
     if(find_ans(mid, neg, pos)){
       ans = mid;
       r = mid - 1;
     }
     else l = mid + 1;
   } 

   cout << ans << nn;
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

