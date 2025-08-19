class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left=0, right = 0, maxLen =0 ;
        while(right< nums.size())
        {
            if(nums[right] == 1)
            {
                maxLen = max(maxLen, right-left+1);
                right ++;
            }
            else{
                //reset window after 0
                right++;
                left = right;
            }
        }
        return maxLen;
    }
};