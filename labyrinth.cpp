/*
Question link: "https://cses.fi/problemset/task/1193";
*/

#include<bits/stdc++.h>
using namespace std;


int n, m;
int si,sj,ei,ej;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vi;
typedef vector<vi> vvi;

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
char path[4] = {'R', 'L', 'D', 'U'};


bool valid(int i, int j){
    return (i<n && j<m && i>=0 && j>=0);
}

int main(){
    cin>>n>>m;
    vvb used(n, vb(m, false));
    string s;
    for (int i=0; i<n; i++){
        cin>>s;
        for (int j=0; j<m; j++){
            if (s[j]=='#') used[i][j]=true;
            if (s[j]=='A') si=i, sj=j;
            if (s[j]=='B') ei=i, ej=j;
        }
    }
    queue<pair<int, int> > q;
    vvi parent(n, vi(m, -1));
    q.push({si, sj});
    used[si][sj]=true;
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        int ci = cur.first;
        int cj = cur.second;
        for (int k=0; k<4; k++){
            int ni = ci + di[k];
            int nj = cj + dj[k];
            if (valid(ni, nj) && !used[ni][nj]){
                q.push({ni, nj});
                used[ni][nj] = true;
                parent[ni][nj] = k;
                if (ni==ei && nj == ej) break;
            }
        }
    }
    if (!used[ei][ej]) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        string res = "";
        int ci = ei;
        int cj = ej;
        while(ci!=si || cj !=sj){
            int k = parent[ci][cj];
            res+=path[k];
            ci -= di[k];
            cj -= dj[k]; 
        }
        reverse(res.begin(), res.end());
        cout<<res.size()<<endl;
        cout<<res<<endl;
    }

}