class DisjointSet {
    vector<int> parent, size;

    public:
        DisjointSet(int n){
            parent.resize(n+1, 0);
            size.resize(n+1, 1);

            for(int i = 0; i<n+1; i++){
                parent[i] = i;
            }
        }

        int findParent(int u){
            if(u==parent[u]){
                return u;
            }
            else{
                return parent[u] = findParent(parent[u]);
            }
        }

        bool UnioinBySize(int u, int v){
            int pu = findParent(u), pv = findParent(v);
            if(pu==pv){
                return false;
            }
            if(size[pu]>=size[pv]){
                parent[pv] = pu;
                size[pu] += size[pv];
            }
            else{
                parent[pu] = pv;
                size[pv] += size[pu];
            }

            return true;
        }


};


class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            if(!ds.UnioinBySize(u, v)){
                return edge;
            }
        }
    }
};
