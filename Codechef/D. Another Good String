#include <bits/stdc++.h>
using   namespace   std;
#define    nn     '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;
    cin >> test;
    while(test--)
    {
        int n, m;
        string s;
        cin >> n >> m >> s;

        int cnt = 1, mx = 1;
        for(int i = 1; i < n; i++){
            if(s[i - 1] == s[i]){
                cnt++;
                mx = max(mx, cnt);
            }
            else{
                cnt = 1;
            }
        }
        cout << mx << ' ';
        for(int i = n; i < (n + m); i++){
            char c; cin >> c;
            s += c;
            if(s[i - 1] == s[i]){
                cnt++;
                mx = max(cnt, mx);
            }
            else{
                cnt = 1;
            }
            cout << mx << " ";
        }
        cout << nn;
    }

    return 0;
}



/***  input 

2
6 4
annncc
c
c
c
d
9 3
ananymous
r
r
r


//// output 

3 3 4 5 5 
1 1 2 3 

***/
