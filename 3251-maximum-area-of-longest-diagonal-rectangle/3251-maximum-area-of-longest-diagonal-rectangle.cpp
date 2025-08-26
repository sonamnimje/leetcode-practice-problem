class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = 0, ans = 0;
        for (auto &d : dimensions) {
            int l = d[0], w = d[1];
            int diag = l*l + w*w;  // diagonal squared
            int area = l*w;
            if (diag > maxDiag || (diag == maxDiag && area > ans)) {
                maxDiag = diag;
                ans = area;
            }
        }
        return ans;
    }
};