/*
Code by Martin Krylov
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <iterator>
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

#define INF 1000000000

#define maxN 200005

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n; 
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];

        int dp[n];
        fill(dp,dp+n+1,INF);
        dp[n] = 0;
        for(int i = n-1;i>=0;i--){
            int nb = i + a[i] + 1;
            if(nb<=n) dp[i] = dp[nb];
            dp[i] = min(dp[i],dp[i+1]+1);
        }
        cout<<dp[0]<<endl;
    }
    return 0;
}

/* IF STUCK LOOK HERE
    * int overflow, use long long
    * array bounds
    * edge cases (n=0,n=1)
    * values not distinct?
    * do smth instead of nothing and stay organized
*/