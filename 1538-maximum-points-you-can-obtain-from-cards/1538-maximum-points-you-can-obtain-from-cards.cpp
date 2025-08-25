class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        // Take first k cards from the start
        for (int i = 0; i < k; i++) sum += cardPoints[i];
        int maxScore = sum;
        // Move cards from start to end one by one
        for (int i = 0; i < k; i++) {
            sum -= cardPoints[k - 1 - i];       // remove from start
            sum += cardPoints[n - 1 - i];       // add from end
            maxScore = max(maxScore, sum);
        }
        return maxScore;
    }
};