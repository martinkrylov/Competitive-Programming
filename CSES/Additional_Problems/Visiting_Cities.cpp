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
typedef pair<long long,long long> ii;

#define INF 100000000000000000

void run_dijkstra(long long source, vector< vector< pair<long long,long long> > > &adjl, vector<long long> &dist){
    fill(dist.begin(),dist.end(),INF);
    priority_queue< pair<long long,long long> , vector< pair<long long,long long> >, greater< pair<long long,long long> > > pq;
    pq.push(make_pair(0,source));
    dist[source] = 0;
    
    while(!pq.empty()){
        long long cd = pq.top().first;
        long long cn = pq.top().second;
        pq.pop();
        if(cd>dist[cn]) continue;
        for(auto np:adjl[cn]){
            long long nd = cd + np.first;
            long long nn = np.second;
            if(nd<dist[nn]){
                dist[nn] = nd;
                pq.push(make_pair(nd,nn));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // Take Input
    long long N,M;
    cin>>N>>M;
    
    vector< vector< pair<long long,long long> > > adjl(N);
    vector< vector< pair<long long,long long> > > radjl(N);

    long long a,b,c;
    for(long long i=0;i<M;i++){
        cin>>a>>b>>c;
        a--;
        b--;
        adjl[a].push_back(make_pair(c,b));
        radjl[b].push_back(make_pair(c,a));
    }

    vector<long long> distS(N);
    vector<long long> distL(N);

    run_dijkstra(0, adjl, distS);
    run_dijkstra(N-1, radjl, distL);

    vector<long long> result;
    long long minDist = distS[N-1];

    priority_queue< pair<long long,long long>, vector< pair<long long,long long> >, greater< pair<long long,long long> > > pq;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        long long cd = pq.top().first;
        long long cn = pq.top().second;
        pq.pop();
        //Pop Duplicates
        while(!pq.empty()&&pq.top().second == cn) pq.pop();
        //Check if Result
        if(pq.empty()) result.push_back(cn);
        //Add next
        for(auto np:adjl[cn]){
            long long nn = np.second;
            long long ed = np.first;
            if(distS[nn]+distL[nn] == minDist && cd+ed == distS[nn]){
                pq.push(make_pair(distS[nn],nn));
                //if(qc<5) cout<<nn<<" ";
            }
        }
    }

    sort(result.begin(),result.end());

    cout<<result.size()<<endl;
    for(auto rn:result){
        cout<<rn+1<<" ";
    }
    cout<<endl;
    return 0;
}

/* IF STUCK LOOK HERE
    * long long overflow, use long long
    * array bounds
    * edge cases (n=0,n=1)
    * values not distinct?
    * do smth instead of nothing and stay organized
*/