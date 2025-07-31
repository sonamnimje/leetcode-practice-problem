class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;        // to store all unique OR results
        unordered_set<int> prev;       // ORs of subarrays ending at previous index
        for (int num : arr) {
            unordered_set<int> cur;
            cur.insert(num);
            for (int x : prev) {
                cur.insert(x | num);
            }
            for (int x : cur) {
                res.insert(x);
            }
            prev = cur; // move to next index
        }
        return res.size();
    }
};
