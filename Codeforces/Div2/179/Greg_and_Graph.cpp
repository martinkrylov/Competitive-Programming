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
typedef pair<ll,ll> ii;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //Take Input
    ll N;
    cin>>N;

    vector< vector<ll> > adjm(N, vector<ll>(N,0));
    for(ll i=0;i<N;i++){
        for(ll j=0;j<N;j++){
            cin>>adjm[i][j];
        }
    }

    vector<ll> del_nodes(N);
    for(ll i=0;i<N;i++){
        cin>>del_nodes[i];
    }

    //Solve the problem by reversing the process
    vector<ll> result;

    reverse(del_nodes.begin(),del_nodes.end());
    for(ll k=0;k<N;k++){
        ll kn = del_nodes[k]-1;
        for(ll i=0;i<N;i++){
            for(ll j=0;j<N;j++){
                adjm[i][j] = min(adjm[i][j],adjm[i][kn]+adjm[kn][j]);
            }
        }
        ll csum = 0;
        for(ll i=0;i<=k;i++){
            for(ll j=0;j<=k;j++){
                if(i==j) continue;
                csum += adjm[del_nodes[i]-1][del_nodes[j]-1];
            }
        }
        result.push_back(csum);
    }

    reverse(result.begin(),result.end());
    for(auto val:result){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}

/* IF STUCK LOOK HERE
    * ll overflow, use long long
    * array bounds
    * edge cases (n=0,n=1)
    * values not distinct?
    * do smth instead of nothing and stay organized
*/
