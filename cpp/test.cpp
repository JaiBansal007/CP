/*
*    Author: Jx07
*    Created:Thursday, 29.10.2026 02:35 PM (GMT+5:30)
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

#define PEACE
// #define MULTI_TEST
int MOD=1e9+7;//998244353;
const int N=(1<<23)+10;
int dp[N];
void solve(int tc){
    int n;cin>>n;
    vector<int> a(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>a[i];
        dp[a[i]]=i;
    }
    // fill it 
    // cout<<(1<<22)/()<<endl;
    for(int i=0;i<N;i++){
        if(dp[i]==-1)continue;  
        for(int j=0;j<23;j++){
            if(i>>j&1){
                //unset
                continue;
            }
            int mask=(i)|(1<<j);
            if(mask>=N)continue;
            dp[mask]=dp[i];
        }
    }
    // debug(dp);
    for(int i=0;i<n;i++){
        int mask=0;
        for(int j=0;j<23;j++){
            if(a[i]>>j&1)continue;
            mask|=(1<<j);
        }
        if(mask>N||dp[mask]==-1){
            cout<<-1<<" ";
            continue;
        }
        cout<<a[dp[mask]]<<" ";
    }   
    cout<<endl;

















}


signed main() {
    #if defined(JAI) && defined(PEACE)
        freopen("input.txt", "r", stdin);  
        freopen("output.txt", "w", stdout); 
        clock_t T = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t=1;
    #ifdef MULTI_TEST
        cin >> t;
    #endif
    
    for(int i=1;i<=t;i++){
        solve(i);
    }

    #if defined(JAI) && defined(PEACE)
        cout << "\nTime : " << ((float)(clock() - T)*1000) / CLOCKS_PER_SEC << " ms";
    #endif

    return 0;
}