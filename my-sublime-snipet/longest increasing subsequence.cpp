#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int a[N], dp[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }

  for(int i = 1; i <= n; i++){
    dp[i] = 1;
    for(int j = 1; j < i; j++){
      if(a[j] < a[i]){
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';

  
  return 0;
}
