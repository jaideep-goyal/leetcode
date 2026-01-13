#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        int n, m;
    void dfs(int i, int j, vector<vector < int>> &image, int oldcolor,
        int color)
    {
        if (i < 0 || j < 0 || i >= n || j >= m)
        {
            return;
        }
        if (image[i][j] != oldcolor)
        {
            return;
        }
        image[i][j] = color;
        dfs(i + 1, j, image, oldcolor, color);
        dfs(i - 1, j, image, oldcolor, color);
        dfs(i, j + 1, image, oldcolor, color);
        dfs(i, j - 1, image, oldcolor, color);
    }
    vector<vector < int>> floodFill(vector<vector < int>> &image, int sr, int sc,
        int color)
    {
        n = image.size();
        m = image[0].size();
        int oldcolor = image[sr][sc];
        if (oldcolor == color)
            return image;
        dfs(sr, sc, image, oldcolor, color);
        return image;
    }
};