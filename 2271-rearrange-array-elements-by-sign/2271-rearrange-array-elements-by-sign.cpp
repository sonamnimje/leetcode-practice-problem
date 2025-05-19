class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positives, negatives;
    for (int num : nums) {
        if (num > 0)
            positives.push_back(num);
        else
            negatives.push_back(num);
    }
    vector<int> result;
    int n = positives.size();
    for (int i = 0; i < n; i++) {
        result.push_back(positives[i]);
        result.push_back(negatives[i]);
    }
    return result;
    }
};