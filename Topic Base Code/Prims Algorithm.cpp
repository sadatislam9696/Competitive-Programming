#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int main(){

    int v, e;
    cin >> v >> e;

    vector<pair<int, int>>adj[e + 1];
    for(int i = 1; i <= e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push({0, 1});
    int vis[v + 1] = {0};
    //vis[1] = 1;

    int ans = 0;

    while(!q.empty()){
        int u = q.top().second;
        int w = q.top().first;
        q.pop();

        if(vis[u])continue;
        vis[u] = 1;
        //cout << w << endl;

        ans += w;



        for(auto it : adj[u]){
            if(!vis[it.second]){
                //ans += it.first;
                //vis[it.second] = 1;
                q.push(it);
            }
        }
    }
    cout << ans << endl;

    return 0;
}


/*

7
9
1 2 28
1 6 10
2 3 16
2 7 14
3 4 12
4 5 22
4 7 18
5 6 25
5 7 24

*/

