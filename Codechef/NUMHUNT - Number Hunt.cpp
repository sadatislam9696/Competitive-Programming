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
const int N = 1e5 + 9;

bool is_prime(ll n){
    for(int i = 2; 1LL * i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
void solution(){
   int n; 
   cin >> n;

   if(n == 1)n++;

   ll a = -1, b = -1, ope = n;
   int flag = 0;
   while(ope <= (n + 1000)){
        if(a == -1 and flag == 0){
           if(is_prime(ope)){
              a = ope; 
              flag = 1;
           }
        }
        else if(b == -1 and flag == 1){
            if(is_prime(ope)){
                b = ope;
            }
        }
        else{
            break;
        }
        ope++;
   }

   cout << 1LL * a * b << nn;

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
