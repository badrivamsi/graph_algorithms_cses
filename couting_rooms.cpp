
/*
Question link :  "https://cses.fi/problemset/task/1192";
*/

#include<bits/stdc++.h>
using namespace std;


int n, m;

typedef vector<bool> vb;
typedef vector<vb> vvb;

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

bool valid(int i, int j){
    return (i<n && j<m && i>=0 && j>=0);
}

void dfs(vvb &used, int si, int sj){
    used[si][sj] = true;
    for (int k=0; k<4; k++){
        int ni=si+di[k];
        int nj=sj+dj[k];
        if (valid(ni, nj) && !used[ni][nj]) dfs(used, ni, nj);
    }
}

int main(){
    cin>>n>>m;
    vvb used(n, vb(m, false));
    string s;
    for (int i=0; i<n; i++){
        cin>>s;
        for (int j=0; j<m; j++){
            if(s[j]=='#') used[i][j]=true;
        }
    }
    int cc = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (!used[i][j]){
                dfs(used, i, j);
                cc++;
            }
        }
    }
    cout<<cc<<endl;

}