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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    
    vector<int> c(n);
    vector< vector<int> > adjm(n, vector<int>(n,INF));

    for(int i=0;i<n;i++){
        cin>>c[i];
        adjm[i][i] = 0;
    }
    int ix,iy,iw;
    for(int i=0;i<n-1;i++){
        cin>>ix>>iy>>iw;
        ix--;
        iy--;
        adjm[ix][iy] = iw;
        adjm[iy][ix] = iw;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                adjm[i][j] = min(adjm[i][j],adjm[i][k]+adjm[k][j]);
            }
        }
    }

    int bbase = -1;
    long double bengagement = 0;

    for(int i=0;i<n;i++){
        long double cengagement = 0;
        for(int j=0;j<n;j++){
            cengagement += (double)c[j]/(double)(1+adjm[i][j]);
        }
        if(cengagement>bengagement){
            bengagement = cengagement;
            bbase = i;
        }
    }
    
    cout<<bbase+1<<endl;
    cout<<fixed;
    cout<<setprecision(6)<<bengagement<<endl;
    return 0;
}

/* IF STUCK LOOK HERE
    * int overflow, use long long
    * array bounds
    * edge cases (n=0,n=1)
    * values not distinct?
    * do smth instead of nothing and stay organized
*/