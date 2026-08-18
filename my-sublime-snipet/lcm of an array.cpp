int lcm(int a, int b){
    int x = __gcd(a, b);
    return (a * b) / x;
}
void solution(){
   int n; 
   cin >> n; 
   int a[n + 1];
   for(int i = 1; i <= n; i++){
     cin >> a[i];
   }

   int ans = a[1];
   for(int i = 2; i <= n; i++){
     ans = lcm(ans, a[i]);
   }
   cout << ans << nn;
}
in
