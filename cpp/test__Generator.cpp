
#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int get(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}

char getChar(){
    return 'a' + get(0, 2); // small alphabet → more collisions
}

string randomString(int n){
    string s;
    for(int i = 0; i < n; i++){
        s += getChar();
    }
    return s;
}

string periodicString(int n){
    int len = get(1, min(5, n));
    string base;
    for(int i = 0; i < len; i++) base += getChar();

    string s;
    for(int i = 0; i < n; i++){
        s += base[i % len];
    }
    return s;
}

string allSame(int n){
    char c = getChar();
    return string(n, c);
}

string almostSame(int n){
    string s = string(n, 'a');
    for(int i = 0; i < n/5; i++){
        s[get(0, n-1)] = getChar();
    }
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; // number of tests
    cout << t << "\n";

    while(t--){
        int n = get(1, 50); // small for brute testing
        int k = get(1, n);

        int type = get(1, 4);
        string s;

        if(type == 1) s = randomString(n);
        else if(type == 2) s = periodicString(n);
        else if(type == 3) s = allSame(n);
        else s = almostSame(n);

        cout << n << " " << k << " " << k << "\n";
        cout << s << "\n";
    }
}

