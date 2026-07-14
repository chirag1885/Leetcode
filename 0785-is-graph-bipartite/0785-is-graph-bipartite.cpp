class Solution {
public:

    bool check(vector<vector<int>>& graph , queue<int> q ,  vector<int> &vis ,  vector<int> &color , int start){
        vis[start]=1;
        color[start]=1;
        q.push(start);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it :graph[node]){
                if(!vis[it]){
                    vis[it]=1;
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        queue<int> q;
        vector<int> vis(n,0);
        vector<int> color(n,-1);
        for(int i=0 ; i<n ; i++){
            if(color[i]==-1){
                if(!check(graph , q , vis , color , i)){
                    return false;
                }
            }
        }
        return true;
    }
};