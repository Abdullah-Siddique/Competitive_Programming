/*
ax + by = gcd(a, b) = 1
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll eea(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = eea(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

ll modin(ll a, ll m){
    ll x, y;
    ll gcd = eea(a, m, x, y);
    if(gcd != 1) return -1;
    return (x % m + m) % m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll a, m;
    cin >> a >> m;
    
    ll ans = modin(a, m);
    if(ans == -1){
        cout << "Modular inverse doesn't exist\n";
    } else {
        cout << "MMI of a modulo m is : " << ans << '\n';
    }
    
    return 0;
}
