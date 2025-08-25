class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
    int n = mat[0].size();
    vector<int> result;
    for (int d = 0; d <= m + n - 2; ++d) {
        vector<int> intermediate;
        // Collect all elements in this diagonal
        for (int i = 0; i < m; ++i) {
            int j = d - i;
            if (j >= 0 && j < n) {
                intermediate.push_back(mat[i][j]);
            }
        }
        // Reverse for even diagonals
        if (d % 2 == 0) {
            reverse(intermediate.begin(), intermediate.end());
        }
        result.insert(result.end(), intermediate.begin(), intermediate.end());
    }
    return result;
    }
};