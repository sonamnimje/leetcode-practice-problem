class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) 
    {
        int n = fruits.size();
        int maxFruits = 0;
        int left = 0, sum = 0;
        for (int right = 0; right < n; ++right) 
        {
            sum += fruits[right][1];
            while (left <= right && !canReach(fruits[left][0], fruits[right][0], startPos, k)) 
            {
                sum -= fruits[left][1];
                left++;
            }
            maxFruits = max(maxFruits, sum);
        }
        return maxFruits;
    }
    bool canReach(int leftPos, int rightPos, int startPos, int k) 
    {
        int case1 = abs(startPos - leftPos) + (rightPos - leftPos);
        int case2 = abs(startPos - rightPos) + (rightPos - leftPos);
        return min(case1, case2) <= k;
    }
};