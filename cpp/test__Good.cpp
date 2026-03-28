/*
*    Author:Jx07
*    Created:Wednesday, 11.03.2026 09:08 PM (GMT+5:30)
*/
#include<bits/stdc++.h>

#ifdef JAI
#include "algo/debug.cpp"
#else
#define debug(...)
#endif
 
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define int long long 
#define all(v) v.begin(), v.end()

// #define peace
const int tt=1;
int MOD=1e9+7;//998244353;

void solve(int tc){
    cout<<"Yes"<<endl;
    











}


signed main() {
    #if defined(JAI) && defined(peace)
        freopen("input.txt", "r", stdin);  
        freopen("output.txt", "w", stdout); 
        clock_t T = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t=1;
    if(tt)cin>>t;
    
    for(int i=1;i<=t;i++){
        solve(i);
    }

    #if defined(JAI) && defined(peace)
        cout << "\nTime : " << ((float)(clock() - T)*1000) / CLOCKS_PER_SEC << " ms";
    #endif

    return 0;
}