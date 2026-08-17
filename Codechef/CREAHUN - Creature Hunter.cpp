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
const int N = 1e3 + 9;

void solution(){
    int n, h; 
    cin >> n >> h; 

    int one = 0, two = 0;
    for(int i = 1; i <= n; i++){
        int s, d; 
        cin >> s >> d; 
        if(s == 1)one = max(one, d);
        else two = max(two, d);
    }

    if(one == 0){
        cout << 1ll * ((h + two - 1) / two) * 2 << nn;
    }
    else if(two == 0){
        cout << ((h + one - 1) / one) << nn; 
    }
    else{
        int for_one = 0, for_two = 0, mix = 0;

        for_one += ((h + one - 1) / one);
        for_two += ((h + two - 1) / two) * 2;

        if(one >= two){
           mix = ((h + one - 1) / one); 
        }
        else{
            mix = (h / two) * 2;
            int rem =  h % two;
            if(rem <= one)mix += 1; 
            else mix += 2;
        }
        cout << min({for_one, for_two, mix}) << nn;
    }
}
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int tt = 1, c = 1;
    cin >> tt;
    //cin.ignore();
    while(tt--){
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
