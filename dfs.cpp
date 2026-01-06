
#include <bits/stdc++.h>
using namespace std;
// time complexity O(V+E)
vector<int>adj_list[100];
int cost[100];
int visited[100];
int parent[100];
vector<int>dfs;
void DFS(int s){
    cost[s]=0;
    visited[s]=1;
    parent[s]=s;

    stack<int>st;
    st.push(s);
    while(!st.empty()){
        int u=st.top();
        st.pop();
        dfs.push_back(u);

        for(int i=0;i<adj_list[u].size();i++){
            int v=adj_list[u][i];

            if(visited[v]!=1){
                visited[v]=1;
                cost[v]=cost[u]+1;
                parent[v]=u;
                st.push(v);
            }
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    for(int i=1;i<=e;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int source,dest;
    cin>>source>>dest;
    DFS(source);
    cout<<"Cost is: "<<cost[dest]<<"\n";

    vector<int>path;
    int now=dest;
    path.push_back(now);
    while(parent[now]!=now){
        now=parent[now];
        path.push_back(now);
    }
    reverse(path.begin(),path.end());
    cout<<"PATH IS: ";
    for(int x:path){
        cout<<x<<" ";
    }
    cout<<"\n";

    cout<<"DFS traversal IS: ";
    for(int x:dfs){
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}
