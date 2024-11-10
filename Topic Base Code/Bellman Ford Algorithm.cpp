

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
