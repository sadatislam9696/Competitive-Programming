
problem link : https://www.geeksforgeeks.org/rearrange-characters-form-palindrome-possible/


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

const ll inf = 1e11 + 9;
const int M = 1e9 + 7;
const int N = 105;

void solution(){
    string s; 
    cin >> s; 

    map<char, int>cnt; 
    for(int i = 0; i < s.size(); i++){
        cnt[s[i]]++;
    }

    int ans = 0;
    char ch;
    string s1, s2;
    for(auto it : cnt){
        if(it.ss % 2 == 0){
            s1 += it.ff;
            s2 += it.ff;
        }
        if(it.ss % 2 != 0){
            ans ++;
            ch = it.ff;
        }
    }

    rev(s2);

    if(ans > 1){
        cout << "No Palindrome" << nn;
    }
    else{   
        cout << s1 << ch << s2 << nn;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t = 1, c = 1;
    //cin >> t;
    while(t--){
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
