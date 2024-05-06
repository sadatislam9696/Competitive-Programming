/***    Bismillahir Rahmanir Rahim    ***/

#include<bits/stdc++.h>
using namespace std;

#define     nn          '\n'
#define     ll          long long
#define     ld          long double
#define     ss          second
#define     ff          first
#define     yes         cout << "Yes" << nn
#define     no          cout << "No" << nn
#define     A           cout << "Alice" << nn
#define     B           cout << "Bob" << nn
#define     pi          3.1415926536
#define     sp(n,d)     fixed << setprecision(d) << n
#define     srt(v)      sort(v.begin(),v.end());
#define     rsrt(v)     sort(v.rbegin(),v.rend());
#define     rev(v)      reverse(v.begin(),v.end());
#define     mem(a, x)   memset(a , x ,sizeof a)

int dx[6] = {0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 1, -1};

const int M = 1e9 +  7;
const int N = 2e5 + 9;

ll tree[4 * N], lazy[4 * N];
int a[N];

struct stree{

    void push(int node, int l, int r){
        if(lazy[node] == 0){
            return;
        }
        tree[node] = lazy[node] * (r - l + 1);
        if(l != r){
            lazy[2 * node] = lazy[node];
            lazy[2 * node + 1] = lazy[node];
        }
        lazy[node] = 0;
    }

    void build(int node, int l, int r){
        lazy[node] = 0;
        if(l == r){
             tree[node] = a[l];
             return;
        }

        int mid = (l + r) >> 1;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    void update(int node, int l, int r, int i, int j, int v){
        push(node, l, r);
        if(r < i or j < l){
            return;
        }
        if(i <= l and r <= j){
            lazy[node] = v;
            push(node, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update(2 * node, l, mid, i, j, v);
        update(2 * node + 1, mid + 1, r, i, j, v);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    ll query(int node, int l, int r, int i, int j){
        push(node, l, r);
        if(r < i or j < l){
            return 0;
        }
        if(i <= l and r <= j){
            return tree[node];
        }
        int mid = (l + r) >> 1;
        ll x = query(2 * node, l, mid, i, j);
        ll y = query(2 * node + 1, mid + 1, r, i, j);
        return x + y;
    }
};
stree st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        st.build(1, 1, n);

        while(q--){
            int x;
            cin >> x;

            if(x == 1){
                int i, v;
                cin >> i >> v;
                st.update(1, 1, n, i, i, v);
            }
            else{
                int v;
                cin >> v;
                st.update(1, 1, n, 1, n, v);
            }
            cout << st.query(1, 1, n, 1, n) << nn;
        }
    }
    return 0;
}
