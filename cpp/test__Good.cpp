/*
*    Author: Jx07
*    Created:Tuesday, 10.11.2026 12:18 PM (GMT+5:30)
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

void solve(int tc){

    // int n=MOD;
    // while(n!=0){
    //     cin>>n;
    //     if(n==0)break;
    //     vector<int> a(n);
    //     for(int i=0;i<n;i++){
    //         cin>>a[i];
    //     }
        
    //     if(a[0]!=a[n-1]){
    //         cout<<"No"<<endl;
    //         continue;
    //     }
    //     vector<vector<int>> ans(n,vector<int>(n));
    //     cout<<"Yes"<<endl;
    //     for(int i=0;i<n;i++){
    //         ans[i][0]=a[i];
    //         ans[n-1][i]=a[i];
    //     }
    //     for(int i=0;i<n;i++){
    //         ans[n-1-i][n-1]=a[i];
    //         ans[0][n-1-i]=a[i];
    //     }
    //     for(auto i:ans){
    //         for(auto j:i){
    //             cout<<j<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }

    int n;
    while(true){
        cin >> n;
        if(n == 0) break;
 
        vector<vector<int>> pre(2, vector<int>(n + 1));
 
        int cnt = 0;
 
        for(int j = 0;j < 2;j += 1){
            for(int i = 1;i <= n;i += 1){   
                cin >> pre[j][i];
                pre[j][i] += pre[j][i - 1];
            }
        }
        int ans=0;
        int idx=-1;
        for(int i=1;i<=n;i++){
            if(pre[0][i]>pre[1][i]){
                if(idx==-1){
                    idx=i;
                }else{
                    if(pre[0][idx]<pre[1][idx]){
                        idx=i;
                        ans++;
                    }
                }
            }else if(pre[0][i]<pre[1][i]){
                if(idx==-1){
                    idx=i;
                }else{
                    if(pre[0][idx]>pre[1][idx]){
                        idx=i;
                        ans++;
                    }
                }
            }
        }    
        cout<<ans<<endl;

    }

















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