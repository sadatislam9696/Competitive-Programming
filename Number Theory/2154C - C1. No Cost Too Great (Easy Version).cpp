// problem Link : https://codeforces.com/contest/2154/problem/C1         



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
#define     yes         cout << "YES" << nn
#define     no          cout << "NO" << nn

using ll =  long long;
using ld =  long double;
using ull = unsigned long long;
const ld pi = acos(-1.0);
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

int dx[6] = {0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 1, -1};

const int M = 1e9 + 7;
const int N = 2e5 + 9;

int spf[N];
void find_spf(){
    for(int i = 2; i < N; i++){
        spf[i] = i;
    }
    for(int i = 2; i < N; i++){
        for(int j = i; j < N; j += i){
            spf[j] = min(spf[j], i);
        }
    }
}
void solution(){
    int n; 
    cin >> n; 
    
    int a[n + 1];
    int cnt[N] = {0}, flag = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
       
        set<int>s;
        int m = a[i];
        while(m > 1){
            s.insert(spf[m]);
            m /= spf[m];
        } 
        for(auto it : s){
            cnt[it]++;
            if(cnt[it] >= 2){
                flag = 1;
            }
            //cout << it << ' ';
        }
    }

    for(int i = 1; i <= n; i++){
        int x; 
        cin >> x;
    }
    if(flag){
        cout << 0 << nn; 
        return;
    }
    
    flag = 0; 
    for(int i = 1; i <= n; i++){
        int m = a[i] + 1, flag = 0;
        while(m > 1){
            if(cnt[spf[m]] >= 1){
               flag = 1;
            }
            m /= spf[m];
        } 
        if(flag){
            cout << 1 << nn;
            return;
        }

    }
    cout << 2 << nn;
}
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    find_spf();

    int t = 1, c = 1;
    cin >> t;
    //cin.ignore();
    while(t--){
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
