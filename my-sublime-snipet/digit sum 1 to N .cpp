// Sum of digits from 1 to n ; complexity o(log n) 
ll digitSum(ll n) {
    if (n < 10) return n * (n + 1) / 2;
    if (mp.count(n)) return mp[n];

    ll tmp = n, d = 0;
    while (tmp > 0) { tmp /= 10; d++; }

    ll p = 1;
    while (d > 1) { p *= 10; d--; }

    ll msd = n / p;   
    ll res = 1ll * msd * digitSum(p - 1);
    res += (1LL * msd * (msd - 1) / 2) * p;
    res +=1LL *  msd * (1 + n % p);
    res += digitSum(n % p);

    return mp[n] = res;
}
