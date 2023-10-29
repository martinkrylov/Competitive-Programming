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

#define MOD 1000000007

ll power(ll base,ll exp){
    if(base == 0&&exp == 0) return 1;
    if(exp == 0) return 1;
    if(exp == 1) return base;
    ll save = power(base,exp/2)%MOD;
    save = (save*save)%MOD;
    if(exp%2==1) save = (save*base)%MOD;
    return save%MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        ll a,b;
        cin>>a>>b;
        a%=MOD;b%=MOD;
        cout<<power(a,b)<<endl;
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