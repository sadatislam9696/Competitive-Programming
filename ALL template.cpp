/*********************************** template   ***/

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



/*********************************************  order set     ***/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/**

oset<int>se;                    [declear a set]
se.insert(val);                 [insert a value]             [ O(log(n)) ]
cout << se.order_of_key(val);   [Number of elements < val]   [ O(log(n)) ]
cout << *(se.find_by_order(i)); [value in index [i] ]        [ O(log(n)) ]

**/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
      oset<int>s;
    }

    return 0;
}



/*** *********************************     segment tree      **/


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


///********************************   segment tree lazy     ************//


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


///********************************* smallest prime factor ***************/

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

int dx[]= {-1, 1, 0, 0, -1,-1, 1, 1};
int dy[]= { 0, 0,-1, 1, -1, 1,-1, 1};

const int mod = 1e9 + 7;
const int N = 1e6 + 9;
int spf[N];

void solution(){
    int n;
    cin >> n;
    for(int i = 2; i <= N; i++){
        spf[i] = i;
    }
    for(int i = 2; i <= N; i++){
        for(int j = i; j < N; j += i){
            spf[j] = min(spf[j], i);
        }
    }

    cout << spf[n] << nn;
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


///****************************   prime factorization using spf  *******************//


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

int dx[]= {-1, 1, 0, 0, -1,-1, 1, 1};
int dy[]= { 0, 0,-1, 1, -1, 1,-1, 1};

const int mod = 1e9 + 7;
const int N = 1e6 + 9;
int spf[N];

void solution(){
    for(int i = 2; i < N; i++){
        spf[i] = i;
    }
    for(int i = 2; i < N; i++){
        for(int j = i; j < N; j += i){
            spf[j] = min(spf[j], i);
        }
    }

    int n;
    cin >> n;
    vector<int> ans;
    while(n > 1){
        ans.push_back(spf[n]);
        n /= spf[n];
    }
    for(auto x: ans) cout << x << ' ';
    cout << nn;
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


///************************    prime factorizatioon   **************************/

vector<int>p;
void prime_factor(int n){
    int i = 2;
    while(i * i <= n){
        while(n % i == 0){
            p.push_back(i);
            n /= i;
        }
        i++;
    }

    if(n > 1) p.push_back(n);
}


///***************************  legendree   ***************************/


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

int dx[]= {-1, 1, 0, 0, -1,-1, 1, 1};
int dy[]= { 0, 0,-1, 1, -1, 1,-1, 1};

const int mod = 1e9 + 7;
const int N = 1e6 + 9;
int spf[N];

int legendre(long long n, long long p) {
  int ans = 0;
  while (n) {
    ans += n / p;
    n /= p;
  }
  return ans;
}

void solution()
{
   cout << legendre(4, 3) << nn;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1, c = 1;
    //cin >> t;
    //cin.ignore();
    while(t--)
    {
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}

///**************************   hasing   **************************/


#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 9;
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;

int power(long long n, long long k, int mod){
    int ans = 1 % mod;
    n %= mod;
    if (n < 0) n += mod;
    while (k){
        if (k & 1) ans = (long long) ans * n % mod;
        n = (long long) n * n % mod;
        k >>= 1;
    }
    return ans;
}

int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec(){  // O(n)
    pw[0] =  {1, 1};
    for (int i = 1; i < N; i++){
        pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    }

    ip1 = power(p1, mod1 - 2, mod1);
    ip2 = power(p2, mod2 - 2, mod2);
    ipw[0] =  {1, 1};

    for (int i = 1; i < N; i++){
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
    }
}

pair<int, int> string_hash(string s){  // O(n)
    int n = s.size();
    pair<int, int> hs({0, 0});
    for (int i = 0; i < n; i++){
        hs.first += 1LL * s[i] * pw[i].first % mod1;
        hs.first %= mod1;
        hs.second += 1LL * s[i] * pw[i].second % mod2;
        hs.second %= mod2;
    }
    return hs;
}

pair<int, int> pref[N];
void build(string s){  // O(n)
    int n = s.size();
    for (int i = 0; i < n; i++){
        pref[i].first = 1LL * s[i] * pw[i].first % mod1;
        if (i) pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
        pref[i].second = 1LL * s[i] * pw[i].second % mod2;
        if (i) pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
    }
}

pair<int, int> get_hash(int i, int j){   // O(1)
    // assert(i <= j);
    pair<int, int> hs({0, 0});
    hs.first = pref[j].first;
    if (i) hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
    hs.first = 1LL * hs.first * ipw[i].first % mod1;
    hs.second = pref[j].second;
    if (i) hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
    hs.second = 1LL * hs.second * ipw[i].second % mod2;
    return hs;
}

// longest commong prefix between s[i...j] and s[x...y]
int get_lcp(int i, int j, int x, int y){   // O(log n)
    int len = min(j - i + 1, y - x + 1);
    int l = 1, r = len, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (get_hash(i, i + mid - 1) == get_hash(x, x + mid - 1))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    prec();

    build();

    return 0;
}


///********************    digibility  of a large number  *****************************/



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

int dx[]= {-1, 1, 0, 0, -1,-1, 1, 1};
int dy[]= { 0, 0,-1, 1, -1, 1,-1, 1};

const int mod = 1e9 + 7;
const int N = 1e6 + 9;
int spf[N];

void solution()
{
    string a;int b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        ans = (ans * 10LL % b + (a[i] - '0')) % b;
    }
    // ans = a % b;
    if (ans == 0){
        cout << "a is divisible by b\n";
    }
    else{
        cout << "sad\n";
    }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1, c = 1;
    //cin >> t;
    //cin.ignore();
    while(t--)
    {
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}


///*******************  Check Cycle exist or not in directed graph *************/


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

vector<int>adj[N];
bool vis[N];
int cycle;
int col[N];

void dfs(int u){
   col[u] = 1;
   for(auto v : adj[u]){
      if(col[v] == 0){
         dfs(v);
      }
      else if(col[v] == 1){
         cycle = 1;
      }
   }
   col[u] = 2;
}

void solution(){
    int n, m;
    cin >> n >> m;

    while(m--){
       int u, v;
       cin >> u >> v;
       adj[u].push_back(v);
    }

    cycle = 0;
    for(int i = 1; i <= n; i++){
       if(col[i] == 0){
          dfs(i);
       }
    }

    if(cycle == 1){
       cout << "cycle exist" << nn;
    }
    else cout << "cycle is not exist" << nn;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t = 1, c = 1;
    //cin >> t;
    //cin.ignore();
    while(t--){
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}



///******************* Check cycle exist or not in undirected graph  ***************//

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

vector<int>adj[N];
bool vis[N];
int cycle;

void dfs(int u){
   vis[u] = 1;
   for(auto v : adj[u]){
      if(!vis[v]){
         dfs(v);
      }
      else{
         cycle = 0;
      }
   }
}

void solution(){
    int n, m;
    cin >> n >> m;

    while(m--){
       int u, v;
       cin >> u >> v;
       adj[u].push_back(v);
    }

    cycle = 1;
    for(int i = 1; i <= n; i++){
       if(!vis[i]){
          dfs(i);
       }
    }

    if(cycle == 1){
       cout << "cycle is not exist" << nn;
    }
    else cout << "cycle exist" << nn;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t = 1, c = 1;
    //cin >> t;
    //cin.ignore();
    while(t--){
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}

///*****************************    Coordinate Compression  ******/


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
const int N = 1e8;

void solution(){
   int n;
   cin >> n;

   vector<int>v;
   for(int i = 1; i <= n; i++){
     int x;
     cin >> x;
     v.push_back(x);
   }
   set<int>s;
   for(auto it : v){
     s.insert(it);
   }

   int id = 0;
   map<int, int>m;
   for(auto it : s){
     m[it] = ++id;
   }

   for(int i = 0; i < n; i++){
     v[i] = m[v[i]];
     cout << v[i] << ' ';
   }

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


///****************************  Dijkstra algorithm.cpp   ******/
#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int main(){
   int v, e;
   cin >> v >> e;

   vector<pair<int, int> >adj[v + 1];
   for(int i = 1; i <= e; i++){
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
      //adj[v].push_back({u, w});
   }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
   q.push({0, 1});

   int dis[v + 1];
   dis[1] = 0;
   for(int i = 2; i <= v; i++){
      dis[i] = inf;
   }


   while(!q.empty()){
      int u = q.top().second;
      q.pop();

      for(auto it : adj[u]){
         int v = it.first;
         int w = it.second;
         if(dis[u] + w < dis[v]){
            dis[v] = dis[u] + w;
            q.push({ w, v});
         }
      }
   }

   for(int i = 1; i <= v; i++){
      if(dis[i] == inf) cout << "Infinite" << ' ';
      else cout << dis[i] << ' ';
   }
}


/*

6
8
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
5 4 2
5 6 5
4 6 1

Output:
0 2 3 8 6 9

*/


///**************************** Modular Multiplicative Inverse Faster way.cpp   *********//

#include <bits/stdc++.h>
using   namespace   std;
#define    ll  long long
#define    nn        '\n'

int power(int a, int n, int mod){
    int ans = 1;
    while(n > 0){
        if(n & 1){
            ans = 1LL * ans * a % mod;
        }
        a = 1LL * a * a % mod;
        n >>= 1;
    }
    return ans;

}
int inverse(int a, int mod){
    return power(a, mod - 2, mod);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
                  /** when mod is prime then the code will work;
                      (a * i % mod ==  1) then [i] is 1 / a = i;

    we know           ((a ^ mod -1 ) % mod) == 1) ===>>> Fermat's Little Theorem
    faster way =>     (((a ^ mod - 1) / a) % mod == (1 / a) % mod);

                       ((a ^ mod - 2) % mod == (1 / a) % mod);  here 1 / a = a inverse 1;

                  **/
       int a = 2, mod = 5;
       cout << inverse(a, mod) << nn; /// 3
    }
    return 0;
}


///**********************    Number of Maximums on a Segment  ******************************/

#include <bits/stdc++.h>
using   namespace   std;
#define      nn     '\n'
#define  ll    long long

const int N = 1e5 + 9;
const int M = 1e9 + 9;
int a[N];
pair<int, int> tree[1LL * 4 * N];

void build(int node, int l, int r){
  if(l == r){
    tree[node].first = a[l];
    tree[node].second = 1;
    return;
  }

  build(2 * node, l, ((l + r) / 2));
  build(2 * node + 1, ((l + r) / 2) + 1, r);

  if(tree[2 * node].first > tree[2 * node + 1].first){
    tree[node].first = tree[2 * node].first;
    tree[node].second = tree[2 * node].second;
  }
  else if(tree[2 * node + 1].first > tree[2 * node].first){
    tree[node].first = tree[2 * node + 1].first;
    tree[node].second = tree[2 * node + 1].second;
  }
  else {
    tree[node].first = tree[2 * node].first;
    tree[node].second = tree[2 * node].second + tree[2 * node + 1].second;
  }
}

void update(int node, int l, int r, int i, int v){
    if(i < l or r < i){
        return;
    }
    if(l == r and i == l){
        tree[node].first = v;
        return;
    }

    update(2 * node, l, ((l + r) / 2), i, v);
    update(2 * node + 1, ((l + r) / 2) + 1, r, i, v);

    if(tree[2 * node].first > tree[2 * node + 1].first){
    tree[node].first = tree[2 * node].first;
    tree[node].second = tree[2 * node].second;
     }
    else if(tree[2 * node + 1].first > tree[2 * node].first){
     tree[node].first = tree[2 * node + 1].first;
     tree[node].second = tree[2 * node + 1].second;
     }
    else {
      tree[node].first = tree[2 * node].first;
      tree[node].second = tree[2 * node].second + tree[2 * node + 1].second;
     }
}

pair<int, int> query(int node, int l, int r, int i, int j){
    if(r < i or j < l){
        pair<int, int>p;
        p.first = -1;
        p.second = -1;
        return p;
    }
    if(i <= l and r <= j){
        return tree[node];
    }

    pair<int, int>left = query(2 * node, l, ((l + r) / 2), i, j);
    pair<int, int>right = query(2 * node + 1, ((l + r) / 2) + 1, r, i, j);

    pair<int, int>ans;
    if(left.first > right.first){
        ans = left;
    }
    else if(right.first > left.first){
        ans = right;
    }
    else{
        ans.first = left.first;
        ans.second = left.second + right.second;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--)
    {
      int n, m;
      cin >> n >> m;
      for(int i = 0; i < n; i++){
        cin >> a[i];
      }
      build(1, 0, n - 1);
      while(m--){
        int type; cin >> type;
        if(type == 1){
            int i, v;
            cin >> i >> v;
            update(1, 0, n - 1, i, v);
        }
        else{
            int l, r;
            cin >> l >> r;
            auto [x, y] = query(1, 0, n - 1, l, r - 1);
            cout << x << ' ' << y << nn;
        }
      }

    }
    return 0;
}


///************************************ topological sort ****/

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

vector<int>adj[N];
bool vis[N];
int indeg[N];

void solution(){
    int n, m;
    cin >> n >> m;

    while(m--){
       int u, v;
       cin >> u >> v;

       indeg[v]++;
       adj[u].push_back(v);
    }

    vector<int>zero;
    for(int i = 1; i <= n; i++){
       if(indeg[i] == 0){
          zero.push_back(i);
          vis[i] = 1;
       }
    }

    vector<int>ans;
    while(ans.size() < n){
        if(zero.empty()){
          cout << "Impossible" << nn;
          return;
        }

        int z = zero.back();
        zero.pop_back();
        ans.push_back(z);

        vis[z] = 1;
        for(auto v : adj[z]){
          indeg[v]--;
          if(!vis[v] and indeg[v] == 0){
             zero.push_back(v);
             vis[v] = 1;
          }

        }
    }

    for(auto it : ans){
      cout << it << " ";
    }
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t = 1, c = 1;
    //cin >> t;
    //cin.ignore();
    while(t--){
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}


///**************************** dfs - number of subtree.cpp  ***************************/


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
const int N = 4009;

string s;
vector<int>adj[N];
int ans, white[N], black[N];
void dfs(int u, int p){
    if(s[u - 1] == 'W')white[u]++;
    else black[u]++;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            white[u] += white[v];
            black[u] += black[v];
        }
    }

    if(white[u] == black[u])ans++;
}
void solution(){
    int n;
    cin >> n;
    int a[n + 1];
    a[1] = -1;
    for(int i = 2; i <= n; i++){
        cin >> a[i];
    }

    cin >> s;
    for(int i = 1; i <= n; i++){
        //cout << a[i] << ' ' << i << nn;
        adj[a[i]].push_back(i);
        adj[i].push_back(a[i]);
    }
    // for(int i = 1; i <= n; i++){
    //     cout << i << ':';
    //     for(auto it : adj[i]){
    //         cout << it << ' ';
    //     }
    //     cout << nn;
    // }

    dfs(1, -1);
    cout << ans << nn;
    for(int i = 1; i <= n; i++){
        adj[i].clear();
        white[i] = black[i] = 0;
    }
    ans = 0;
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


///*************************************** Bellman Ford Algorithm.cpp ******/



#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int main(){
    int v, e;
    cin >> v >> e;
    vector<int>weight;
    vector<pair<int, int> >edge;
    for(int i = 1; i <= e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        weight.push_back(w);
        edge.push_back({u, v});
    }

    for(int i = 0; i < edge.size(); i++){
        cout << edge[i].first <<  " " << edge[i].second  << endl;
    }

    int dis[v + 1];
    dis[1] = 0;
    for(int i = 2; i <= v ; i++){
        dis[i] =  inf;
    }
    for(int i = 0; i <= (v - 1); i++){
        for(int j = 0; j < edge.size(); j++){
            pair<int, int>p = edge[j];
            int u  = p.first;
            int  v = p.second;
            int w = weight[j];
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
            }
        }
    }

    for(int i = 1; i <= v; i++){
       cout << dis[i] << ' ';
    }
}


/*

vertex 
edge
u to v and weight

7
10
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
3 5 1
4 3 -2
4 6 -1
5 7 3
6 7 3

output
0 1 3 5 0 4 3
*/


///*************************** Follyd Warshall Algorithm.cpp******************/

#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int N = 2e5;

int a[N][N];
int main(){

    int v, e;
    cin >> v >> e;

    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            if(i != j)a[i][j] = inf;
        }
    }
    while(e--){
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
    }

//    for(int i = 1; i <= v; i++){
//        for(int j = 1; j <= v; j++){
//            cout << a[i][j] << ' ';
//        }
//        cout << endl;
//    }

     for(int p = 1; p <= v; p++){
        for(int i = 1; i <= v; i++){
            for(int j = 1; j <= v; j++){
                if(a[i][p] != inf and a[p][j] != inf){
                    a[i][j] = min(a[i][j], a[i][p] + a[p][j]);
                }
            }
        }
     }

     for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}


/*

4
7
1 2 3
1 4 7
2 1 8
2 3 2
3 1 5
3 4 1
4 1 2


*/

///**********************  ncr and npr under modulo  ********************//

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, mod = 1e9 + 7;

int fact[N], ifact[N];

int power(int x, int n) {
  int ans = 1;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

int inverse(int a) { // O(log mod)
  return power(a, mod - 2);
}

void prec() { // O(n)
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL * fact[i - 1] * i % mod;
  }
  ifact[N - 1] = inverse(fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod;
  }
}

int nPr(int n, int r) { // O(1)
  if (n < r) return 0;
  return 1LL * fact[n] * ifact[n - r] % mod;
}

int nCr(int n, int r) { // O(1)
  if (n < r) return 0;
  return 1LL * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();
  int q; cin >> q;
  while (q--) {
    int n, r; cin >> n >> r;
    cout << nPr(n, r) << ' ' << nCr(n, r) << '\n';
  }
  return 0;
}
// O(n + q)


///**************************  prime factorization using seive  *********************/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
int spf[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 2; i < N; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < N; i++) {
    for (int j = i; j < N; j += i) {
      spf[j] = min(spf[j], i);
    }
  }
  int q; cin >> q; // queries q <= 1e6
  while (q--) {
    int n; cin >> n; // find prime factorization of n <= 1e6
    vector<int> ans;
    while (n > 1) {
      ans.push_back(spf[n]);
      n /= spf[n];
    }
    for (auto x: ans) cout << x << ' '; cout << '\n';
  }
  return 0;
}

///*****************************  lcm  of an array   *************************/

int lcm(int a, int b){
    int x = __gcd(a, b);
    return (a * b) / x;
}
void solution(){
   int n; 
   cin >> n; 
   int a[n + 1];
   for(int i = 1; i <= n; i++){
     cin >> a[i];
   }

   int ans = a[1];
   for(int i = 2; i <= n; i++){
     ans = lcm(ans, a[i]);
   }
   cout << ans << nn;
}


///**************************  traling zeros in factorial ************************/

int find_ans(int n){
    if(n < 0)return -1;
    int count = 0;
    for(int i = 5; n / i >= 1; i *= 5){
        count += n / i;
    }
    return count;
}
void solution(){
   int n; 
   cin >> n; 
   cout << find_ans(n) << nn;
}

///************************  divisor of factorial ************************/

using ll = long long;
const int N = 100;

bool p[N];
vector<int>v;
void seive_of_prime(){
    for(int i = 1; i <= N; i++){
        p[i] = true;
    }
    p[1] = false;
    for(int i = 2; 1LL * i * i <= N; i++){
       if(p[i]){
         for(int j = i + i; j <= N; j += i){
             p[j] = false;
         }
       }
    }

    for(int i = 1; i <= N; i++){
        if(p[i]){
            v.push_back(i);
        }
    }
}
ll legendre(int n, int p){
    ll ans = 0;
    while(n){
        ans += n / p;
        n /= p;
    }
    return ans;
}
void solution(){
    int n;
    cin >> n;

    map<int, int>cnt;
    for(auto it : v){
        if(it <= n){
            ll x = legendre(n, it);
            cnt[it] = x;
        }
    }

    ll ans = 1;
    for(auto it : cnt){
        //cout << it.second << nn;
        ans *= (it.second + 1);
    }

    cout << ans << nn;
}
///*************************  x = i + j here i, j = prime ****************************/


#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

int spf[N];
void sieve() {
  for(int i = 2; i < N; i++) {
    spf[i] = i;
  }
  for(int i = 2; i < N; i++) {
    if (spf[i] == i) {
      for (int j = i; j < N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}
bool ok(int n) { // checking if possible
  for (int i = 2; i < n; i++) {
    if (spf[i] == i and spf[n - i] == n - i) {
      return true;
    }
  }
  return false;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  for (int n = 4; n <= 100000; n += 2) {
    if (!ok(n)) cout << n << '\n';
  }
  return 0;
}


///**************************************   0/1 knapsac ********************//

#include<bits/stdc++.h>
using namespace std;

const int N = 105;
#define int long long
int n, W, w[N], v[N], dp[N][100005];
int rec(int i, int weight) {
  if (i == n + 1) return 0;
  if (dp[i][weight] != -1) return dp[i][weight];
  int ans = rec(i + 1, weight);
  if (weight + w[i] <= W) ans = max(ans, rec(i + 1, weight + w[i]) + v[i]);
  return dp[i][weight] = ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> W;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
  }
  memset(dp, -1, sizeof dp);
  cout << rec(1, 0) << '\n';
  return 0;
}


///******************************** longest  common subsequence  ****************/

#include<bits/stdc++.h>
using namespace std;

const int N = 3030;
string a, b;
int dp[N][N];

int lcs(int i, int j){
  if(i >= a.size() or j >= b.size()) return 0;
  if(dp[i][j] != -1) return dp[i][j];

  int ans = lcs(i + 1, j);

  ans = max(ans, lcs(i, j + 1));
  if(a[i] == b[j]){
    ans = max(ans, lcs(i + 1, j + 1) + 1);
  }
  return dp[i][j] = ans;
}

void print(int i, int j){
  if(i >= a.size() or j >= b.size()) return;
  if(a[i] == b[j]) {
    cout << a[i];
    print(i + 1, j + 1);
    return;
  }

  int x = lcs(i + 1, j);
  int y = lcs(i, j + 1);
  if(x >= y) {
    print(i + 1, j);
  }
  else {
    print(i, j + 1);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b;
  memset(dp, -1, sizeof dp);
  cout << lcs(0, 0) << '\n';

  print(0, 0);
  return 0;
}


///**********************************  longest increasing subsequence ************************/

#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int a[N], dp[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }

  for(int i = 1; i <= n; i++){
    dp[i] = 1;
    for(int j = 1; j < i; j++){
      if(a[j] < a[i]){
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';

  
  return 0;
}
