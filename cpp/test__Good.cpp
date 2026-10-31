/*
*    Author: Jx07
*    Created:Tuesday, 08.09.2026 08:25 PM (GMT+5:30)
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

// #define PEACE
#define MULTI_TEST
int MOD=1e9+7;//998244353;

void solve(int tc){
    int x,y;cin>>x>>y;
    cout<<(x+y)<<" ";
    //this is max value 
    //how to count min number of operations 

    auto op1=[&](int x,int j){
        //xor 
        int v=0;
        for(int k=j;k>=0;k--){
            if(x>>k&1)continue;
            v+=(1<<k);
        }
        return v;
    };  
    auto op2=[&](int x,int j){
        //and 
        int v=0;
        for(int k=j;k>=0;k--){
            if(x>>k&1){
                v+=(1<<k);
            }
        }
        return v;
    };
    //can this give tle pta nai
    int op=0;
    int ans=x;
    for(int j=30;j>=0;j--){
        if((x>>j&1)&&(y>>j&1)){
            int a=op1(y,j-1)+1;
            int b=op2(x,j-1)+1;
            int m=min(a,b);
            y+=m;
            x-=m;
            op+=m;
            j=31;
        }
    }

    cout<<min(op,ans)<<endl;












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