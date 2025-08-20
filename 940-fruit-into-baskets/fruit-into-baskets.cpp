class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        unordered_map<int, int> count; 
        int left = 0, right = 0, maxLen = 0;
        while (right < fruits.size()) 
        {
            count[fruits[right]]++;
            // if more than 2 types, shrink from left
            while (count.size() > 2) 
            {
                count[fruits[left]]--;
                if (count[fruits[left]] == 0) 
                {
                    count.erase(fruits[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};