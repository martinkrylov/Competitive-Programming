/*
Code by Martin Krylov
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
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

#define MDEPTH 20

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin>>n>>q;

    vector<vector<int>> adj(n,vector<int>());
    vector<vector<int>> bl(n,vector<int>(MDEPTH+1));
    
    int cboss;
    bl[0][0] = 0;
    for(int i=1;i<n;i++){
        cin>>cboss;
        cboss--;
        bl[i][0] = cboss;
        adj[cboss].push_back(i);
    }

    //define depths
    vector<int> depth(n);
    queue<int> layer;
    layer.push(0);
    int current_depth = 0;
    while(!layer.empty()){
        int tn = layer.size();
        while(tn--){
            int cn = layer.front(); layer.pop();
            depth[cn] = current_depth;
            for(int child:adj[cn]){
                layer.push(child);
            }
        }
        current_depth++;
    }

    //Run BL
    for(int j=1;j<=MDEPTH;j++){
        for(int i=0;i<n;i++){
            bl[i][j] = bl[bl[i][j-1]][j-1];
        }
    }

    //LCA
    int a,b;
    for(int z=0;z<q;z++){
        cin>>a>>b;
        a--;b--;
        //Level depths
        if(depth[a]<depth[b]) swap(a,b);
        int diff = depth[a]-depth[b];
        for(int j=MDEPTH;j>=0;j--){
            while(diff&(1<<j)){
                a = bl[a][j];
                diff -= (1<<j);
            }
        }
        //Check if already equal
        if(a==b){
            cout<<a+1<<endl;
            continue;
        }
        //Else, move right under lowest common boss
        for(int j=MDEPTH;j>=0;j--){
            while(bl[a][j]!=bl[b][j]){
                a = bl[a][j];
                b = bl[b][j];
            }
        }
        cout<<bl[a][0]+1<<endl;
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