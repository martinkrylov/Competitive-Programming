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

#define maxN 100005

int N;
ll K[maxN];
ll total;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) cin>>K[i];
    for(int i=0;i<N;i++) total+=K[i];

    ll result = 0;

    ll csum = 0;
    for(int i=0;i<N;i++) csum+=K[i]*(i+1);

    result = csum;
    for(int i=N-2;i>=0;i--){
        csum = csum + (total) - K[i+1]*N;
        result = max(result,csum);
    }
    
    cout<<result<<endl;

    return 0;
}

/* IF STUCK LOOK HERE
    * int overflow, use long long
    * array bounds
    * edge cases (n=0,n=1)
    * values not distinct?
    * do smth instead of nothing and stay organized
*/