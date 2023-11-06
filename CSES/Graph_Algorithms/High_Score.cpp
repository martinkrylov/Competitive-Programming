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

#define INF 1000000000000000
#define maxN 2505

ll N,M;
vector< pair<ll,ll> > adjm[maxN];
vector<ll> radjm[maxN];

ll dist[maxN];

bool useful[maxN];
void find_useful(int p){
    if(useful[p]) return;
    useful[p] = true;
    for(auto c:radjm[p]) find_useful(c);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    fill(dist,dist+maxN,INF);

    cin>>N>>M;

    ll a,b,x;
    for(ll i=0;i<M;i++){
        cin>>a>>b>>x;
        a--;b--;
        x=-x;
        adjm[a].push_back(make_pair(b,x));
        radjm[b].push_back(a);
    }

    // Find all useful nodes
    fill(useful,useful+maxN,false);
    find_useful(N-1);
    
    // Run Bellman for only on useful nodes
    dist[0] = 0;
    for(int l = 0;l<N-1;l++){
        bool modified = false;
        for(int a = 0;a<N;a++){
            if(!useful[a]) continue;
            if(dist[a] == INF) continue;
            for(auto bp:adjm[a]){
                int b = bp.first;
                int d = bp.second;
                if(!useful[b]) continue;
                if(dist[b]<=dist[a]+d) continue;
                dist[b] = dist[a]+d;
                modified = true;
            }
        }
        if(!modified) break;
    }
    
    bool hasUsefulLoop = false;
    for(int a = 0;a<N;a++){
        if(!useful[a]) continue;
        if(dist[a] == INF) continue; //skips over unreachable useful nodes
        for(auto bp:adjm[a]){
            int b = bp.first;
            int d = bp.second;
            if(!useful[b]) continue;
            if(dist[b] > dist[a]+d) hasUsefulLoop = true;
        }
    }

    if(hasUsefulLoop){
        cout<<-1<<endl;
    }else{
        cout<<-1*dist[N-1]<<endl;
    }

    return 0;
}

/* IF STUCK LOOK HERE
    * ll overflow, use long long
    * array bounds
    * edge cases (n=0,n=1)
    * values not distinct?
    * do smth instead of nothing and stay organized
*/