class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0, right=0, maxLen = 0, ZeroCount =0;
        while(right< nums.size())
        {
            if(nums[right] == 0)
            {
                ZeroCount++;
            }
        // if zeros exceed k
        while(ZeroCount> k)
        {
            if(nums[left]  == 0)
            {
                ZeroCount--;
            }
            left++;
        }
        maxLen = max(maxLen, right-left+1);
        right++;
        } 
        return maxLen;
    }
};