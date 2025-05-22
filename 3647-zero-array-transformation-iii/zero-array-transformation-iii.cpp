class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
         int n = nums.size();
        int q = queries.size();
        int queryIndex = 0;
        std::sort(queries.begin(), queries.end());
        std::priority_queue<int> available;
        std::priority_queue<int, std::vector<int>, std::greater<int>> running;

        for (int i = 0; i < n; ++i) {
            while (queryIndex < q && queries[queryIndex][0] <= i) {
                available.push(queries[queryIndex][1]);
                ++queryIndex;
            }
            while (!running.empty() && running.top() < i) {
                running.pop();
            }
            while (nums[i] > running.size()) {
                if (available.empty() || available.top() < i) {
                    return -1;
                }
                running.push(available.top());
                available.pop();
            }
        }
        return available.size();
    }
};