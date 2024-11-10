
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

