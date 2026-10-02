class Solution {
public:
    vector<int> parent , sz ;
    int find(int x) {
        if(parent[x] == x) return x ;
        return parent[x] = find(parent[x]) ;
    }

    void unite(int u , int v) {
        u = find(u) ;
        v = find(v) ;

        if(u == v) return ;
        if(sz[u] < sz[v]) swap(u , v) ;

        parent[v] = u ;
        sz[u] += sz[v] ;

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size() ;
        sz.assign(n + 1, 1) ;
        parent.resize(n + 1) ;

        for(int i = 1 ; i < n ; i++) {
            parent[i] = i ;             
        }

        for(auto &e : edges) {
            int u = e[0] ;
            int v = e[1] ;

            if(find(u) == find(v)) {
                return e ;
            }

            unite(u , v) ;
        }
        
        return {} ;
    }

    
};