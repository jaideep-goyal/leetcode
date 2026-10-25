class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n , vector<bool>(m,false));
        int r = 0;
        int c = 0;
        for(int i = 0 ; i < n*m ; i++) {
            vis[r][c] = true;

            int nr = r;
            int nc = c;
            if(grid[r][c] == 'L') nc--;
            else if(grid[r][c] == 'R') nc++;
            else if(grid[r][c] == 'U') nr--;
            else nr++;

            if(nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc]) return {r,c};

            r = nr;
            c = nc;
        }
        return {r,c};

        
    }
};