class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& points) {
         int n = points.size();
    int m = points[0].size();
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++) {
        vector<int> cur(m, 0);
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                cur[j] = (points[i][j] == 0) ? 1 : 0; // Initialize the starting point
            else {
                if (points[i][j] == 0) { // Check for open space
                    int up = 0, left = 0;
                    if (i > 0) up = prev[j];
                    if (j > 0) left = cur[j - 1];
                    cur[j] = up + left;
                }
            }
        }
        prev = cur;
    }
    return prev[m - 1];
}
  
};