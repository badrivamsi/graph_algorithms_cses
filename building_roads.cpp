/*
Question link: "https://cses.fi/problemset/task/1666";
*/

#include<bits/stdc++.h>
using namespace std;

int n,m;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;


void dfs(int si, vvi &adj, vb &used){
    used[si]=true;
    for (auto v: adj[si]){
        if (!used[v]) dfs(v, adj, used);
    }
}

int main(){
    cin>>n>>m;
    vvi adj(n);
    for (int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vb used(n, false);
    vi comp;
    for (int i=0; i<n; i++){
        if (!used[i]){
            comp.push_back(i);
            dfs(i, adj, used);
        }
    }
    cout<<comp.size()-1<<endl;
    for (int i=1; i<comp.size(); i++){
        cout<<comp[i-1]+1<<" "<<comp[i]+1<<endl;
    }


}