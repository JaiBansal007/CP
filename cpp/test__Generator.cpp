/*
*    Author: Jx07
*    Created:Sunday, 11.10.2026 08:07 PM (GMT+5:30)
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
#define MULTI_TEST
int MOD=1e9+7;//998244353;

void solve(int tc){

    while(true){
        int n,m;cin>>n>>m;
        if(n==0)break;
        vector<string> a(n);
        debug(n,m);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        //for A
        vector<vector<int>> dp1(n,vector<int>(m));// 0 ,0 to i,j
        vector<vector<int>> dp2(n,vector<int>(m)); // i, j -> n-1 , m-1

        //for B
        vector<vector<int>> dp3(n,vector<int>(m)); //n-1 , 0 -> i, j
        vector<vector<int>> dp4(n,vector<int>(m));  //i,j -> 0 , m-1
        
        auto valid=[&](int i,int j){
            return i>=0&&j>=0&&i<n&&j<m&&a[i][j]=='.';
        };

        {
            dp1[0][0]=1;

        //OK
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!valid(i,j)||(i==0&&j==0))continue;
                if(valid(i-1,j)){
                    dp1[i][j]+=dp1[i-1][j];
                }
                if(valid(i,j-1)){
                    dp1[i][j]+=dp1[i][j-1];
                }
            }
        }


        dp2[n-1][m-1]=1;
        //OK
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(!valid(i,j)||(i==n-1&&j==m-1))continue;
                if(valid(i+1,j)){
                    dp2[i][j]+=dp2[i+1][j];
                }
                if(valid(i,j+1)){
                    dp2[i][j]+=dp2[i][j+1];
                }
            }
        }

        //OK
        dp3[n-1][0]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(!valid(i,j)||(i==n-1&&j==0))continue;
                if(valid(i+1,j)){
                    dp3[i][j]+=dp3[i+1][j];
                }
                if(valid(i,j-1)){
                    dp3[i][j]+=dp3[i][j-1];
                }
            }
        }

        //OK
        dp4[0][m-1]=1;
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                if(!valid(i,j)||(i==0&&j==m-1))continue;
                if(valid(i,j+1)){
                    dp4[i][j]+=dp4[i][j+1];
                }
                if(valid(i-1,j)){
                    dp4[i][j]+=dp4[i-1][j];
                }
            }
        }
        }

        int ans=dp1[n-1][m-1]*dp3[0][m-1];
        // i,j -> (i+j)
        //->(n-1-i + m-1-j)
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(2*(i+j)==(n+m-2)){
                    //then only sub
                    int v=dp2[i][j]*dp4[i][j]; 
                    if(valid(i-1,j)){
                        int v2=((valid(i,j-1)?dp3[i][j-1]:0LL)+(valid(i+1,j)?dp3[i+1][j]:0LL))*dp1[i-1][j];
                        ans-=v2*v;
                    }
                    if(valid(i,j-1)&&valid(i+1,j)){
                        ans-=dp1[i][j-1]*dp3[i+1][j]*v;
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