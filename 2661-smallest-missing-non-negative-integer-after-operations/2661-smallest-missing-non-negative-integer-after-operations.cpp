class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) 
    {
        unordered_map<int, int> count;
        // Step 1: Normalize remainders and count occurrences
        for (int x : nums) 
        {
            int r = ((x % value) + value) % value;
            count[r]++;
        }
        // Step 2: Find the smallest missing non-negative integer
        int mex = 0;
        while (true) 
        {
            int r = mex % value;
            if (count[r] > 0) 
            {
                count[r]--;
                mex++;
            } else 
            {
                break;
            }
        }
        return mex;
    }
};