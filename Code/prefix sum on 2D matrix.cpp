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
    int n, m;
    cin >> n >> m;

    int a[n + 1][m + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] == 1){
            }
        }
    }
 
    int pre[n + 1][m + 1] = {0};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int now = a[i][j];
            if(i > 1) now += pre[i - 1][j];
            if(j > 1) now += pre[i][j - 1];
            if(i > 1 && j > 1) now -= pre[i - 1][j - 1];
            pre[i][j] = now;
        }
    }

     for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << pre[i][j] << ' ';
        }
        cout << nn;
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
