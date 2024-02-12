#include <bits/stdc++.h>
using   namespace   std;
#define      nn     '\n'
#define  ll    long long

const int N = 1e5 + 9;
const int M = 1e9 + 9;
int a[N];
pair<int, int> tree[1LL * 4 * N];

void build(ll node, ll l, ll r){
    if(l == r){
        tree[node].first = a[l];
        tree[node].second = 1;
        return;
    }
    build(2 * node, l, ((l + r) / 2));
    build(2 * node + 1, ((l + r) / 2) + 1, r);

    if(tree[2 * node].first < tree[2 * node + 1].first){
        tree[node].first = tree[2 * node].first;
        tree[node].second = tree[2 * node].second;
    }
    else if(tree[2 * node + 1].first < tree[2 * node].first){
        tree[node].first = tree[2 * node + 1].first;
        tree[node].second = tree[2 * node + 1].second;
    }
    else{
        tree[node].first = tree[2 * node].first;
        tree[node].second = tree[2 * node].second + tree[2 * node + 1].second;
    }
}
void update(ll node, ll l, ll r, int i, int value){
    if(i < l or r < i){
        return;
    }
    if(l == r and i == l and i == r){
        tree[node].first = value;
        return;
    }
    update(2 * node, l, ((l + r) / 2), i, value);
    update(2 * node + 1, ((l + r) / 2) + 1, r, i, value);

    if(tree[2 * node].first < tree[2 * node + 1].first){
        tree[node].first = tree[2 * node].first;
        tree[node].second = tree[2 * node].second;
    }
    else if(tree[2 * node + 1].first < tree[2 * node].first){
        tree[node].first = tree[2 * node + 1].first;
        tree[node].second = tree[2 * node + 1].second;
    }
    else{
        tree[node].first = tree[2 * node].first;
        tree[node].second = tree[2 * node].second + tree[2 * node + 1].second;
    }

}
pair<int, int> query(ll node, ll l, ll r, int i, int j){
    if(i <= l and r <= j){
        return tree[node];
    }
    if(r < i or j < l){
        pair<int, int>u;
        u.first = M;
        u.second = -1;
        return u;
    }
    pair<int, int>left = query(2 * node, l, ((l + r) / 2), i, j);
    pair<int, int>right = query(2 * node + 1, ((l + r) / 2) + 1, r, i, j);

    pair<int, int>ans;
    if(left.first < right.first){
        ans = left;
    }
    else if(right.first < left.first){
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
        int op; cin >> op;
        if(op == 1){
           int index, value;
           cin >> index >> value;
           update(1, 0, n - 1, index, value);
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
