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

ll t[4 * N], a[N];
struct segtree
{
  void build(int n, int b, int e){
    if(b == e){
       t[n] = a[b];
       return;
    }

    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = t[l] + t[r];
  }

  void update(int n, int b, int e, int i){
     if(i < b or e < i){
      return;
     }
     if(b == e and b == i){
       t[n] = 0;
       return;
     }
     int mid = (b + e) >> 1, l = n << 1, r = l + 1;
     update(l, b, mid, i);
     update(r, mid + 1, e, i);
     t[n] = t[l] + t[r];
  }

  int query(int n, int b, int e, int i, int j){
    if(e < i or b > j){
      return 0;
    }
    if(b >= i and e <= j){
      return t[n];
    }

    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    return (query(l, b, mid, i, j) + query(r, mid + 1, e, i, j));
  }
}st;  /// like   s.build(1, 1, n);

void solution(){

}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t = 1, c = 1;
    cin >> t;
    //cin.ignore();
    while(t--){
        //cout << "Case " << c++ << ": " << nn;
        solution();
    }
    return 0;
}
