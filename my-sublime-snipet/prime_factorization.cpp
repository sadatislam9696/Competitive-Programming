vector<int>p;
void prime_factor(int n){
    int i = 2;
    while(i * i <= n){
        while(n % i == 0){
            p.push_back(i);
            n /= i;
        }
        i++;
    }

    if(n > 1) p.push_back(n);
}
