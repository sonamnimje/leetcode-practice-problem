class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long> lengths = {1}; 
        for (int op : operations) {
            long long prevLen = lengths.back();
            long long newLen = min((long long)1e15, op == 0 ? prevLen * 2 : prevLen * 2);
            lengths.push_back(newLen);
        }
        int shift = 0;
        for (int i = operations.size(); i > 0; --i) {
            long long len = lengths[i];
            long long half = lengths[i - 1];
            if (k > half) {
                k -= half;
                if (operations[i - 1] == 1) {
                    shift++;
                }
            }
        }
        char c = 'a';
        c = ((c - 'a' + shift) % 26) + 'a';
        return c;
    }
};