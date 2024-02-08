/**   Bismillahir Rahmanir Rahim  **/

#include<bits/stdc++.h>
using   namespace  std;
#define   nn       '\n'
#define   ll  long long

ll find_value(vector<int>&a, int mid, ll c){
    ll sum = 0;
    for(auto x : a){
        if(sum > c) return sum;
        sum += 1LL * ((2 * mid) + x) * ((2 * mid) + x);
    }
    return sum;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int t = 1;
   cin >> t;
   while(t--){
     int n;
     ll c;
     cin >> n >> c;
     vector<int>a(n);
     for(auto &i : a){
        cin >> i;
     }

     int l = 1, r = 2e9, ans = 0;
     while(l <= r){
        int mid = (1LL * l + r) / 2;

        if(find_value(a, mid, c) >= c){
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
     }
     cout << ans << nn;
    }
   return 0;
}
