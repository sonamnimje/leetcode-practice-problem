class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> diags;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diags[i - j].push_back(grid[i][j]);
            }
        }
        for (auto &p : diags) {
            if (p.first >= 0) 
                sort(p.second.begin(), p.second.end(), greater<int>()); // descending
            else 
                sort(p.second.begin(), p.second.end()); // ascending
        }
        unordered_map<int, int> idx;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int key = i - j;
                grid[i][j] = diags[key][idx[key]++];
            }
        }
        return grid;
    }
};