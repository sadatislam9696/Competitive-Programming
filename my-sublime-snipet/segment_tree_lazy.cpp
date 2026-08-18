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

int a[N];
int tree[4 * N], la[4 * N];
struct segtree ///  sum 
{  
  inline void push(int n, int b, int e){
     if(la[n] == 0)return;
     tree[n] = tree[n] + la[n];

     if(b != e){
       la[2 * n] += la[n];
       la[2 * n + 1] += la[n];
     }
     la[n] =  0;
  }
  void build(int node, int b, int e){
     la[node] = 0;
     if(b == e){
        tree[node] = 0;
        return;
     }

     int mid = (b + e) >> 1, l = node << 1, r = l | 1;
     build(l, b, mid);
     build(r, mid + 1, e);
     tree[node] = tree[l] + tree[r];
  } 
  void update(int node, int b, int e, int i, int j){
    push(node, b, e);
    if(b > j or e < i){
        return;
    }
    if(b >= i and e <= j){
        la[node] = 1;
        push(node, b, e);
        return;
    }

    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    update(l, b, mid, i, j); 
    update(r, mid + 1, e, i, j);
    tree[node] = (tree[l] + tree[r]); 
  }

  ll query(int node, int b, int e, int i){
    push(node, b, e);
    if(b > i or e < i){
        return 0;
    }
    if(b == e and b == i){
        return tree[node];
    }

    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    return 1LL * (query(l, b, mid, i) + query(r, mid + 1, e, i));
  }

}st;   ///  like    st.update(1, 1, n, i, j);

void solution(){
   
}

int32_t main(){
   
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t = 1, c = 1;
    //cin >> t;
    //cin.ignore();
    while(t--){
        //cout << "Case " << c++ << ": " << nn;                       
        solution();
    }
    return 0;
}
