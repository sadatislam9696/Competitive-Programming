#include <bits/stdc++.h>
using   namespace   std;
#define    ll  long long
#define    nn        '\n'

int power(int a, int n, int mod){
    int ans = 1;
    while(n > 0){
        if(n & 1){
            ans = 1LL * ans * a % mod;
        }
        a = 1LL * a * a % mod;
        n >>= 1;
    }
    return ans;

}
int inverse(int a, int mod){
    return power(a, mod - 2, mod);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
                  /** when mod is prime then the code will work;
                      (a * i % mod ==  1) then [i] is 1 / a = i;
                      
    we know           ((a ^ mod -1 ) % mod) == 1) ===>>> Fermat's Little Theorem
    faster way =>     (((a ^ mod - 1) / a) % mod == (1 / a) % mod);
    
                       ((a ^ mod - 2) % mod == (1 / a) % mod);  here 1 / a = a inverse 1;
                       
                  **/
       int a = 2, mod = 5;
       cout << inverse(a, mod) << nn; /// 3
    }
    return 0;
}
