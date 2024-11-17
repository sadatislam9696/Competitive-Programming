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

