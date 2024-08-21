

// https://www.codechef.com/START148C?order=desc&sortBy=successful_submissions


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

void solution(){
   int n, x, y; 
   cin >> n >> x >> y; 

   string s; cin >> s; 
   vector<pair<int, int>>v;
   int a = 0, b = 0;
   v.push_back({a, b});
   for(int i = 0; i < s.size(); i++){
      if(s[i] == 'R'){
         a++;
      }
      else if(s[i] == 'L'){
         a--;
      }
      else if(s[i] == 'U'){
         b++;
      }
      else{
         b--;
      }
      v.push_back({a, b});  
   }
   int i = 0;
   int flag = 0;
   for(auto it : v){
       int r = abs(x - it.ff);
       int c = abs(y - it.ss);
       int x = r + c; 
       if(x == i){
         flag = 1;
       }
       i++;
   }

   if(flag){
      cout << "Yes" << nn;
   }
   else cout << "No" << nn;
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
