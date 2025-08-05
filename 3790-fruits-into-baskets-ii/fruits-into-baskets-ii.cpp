class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) 
    {
        int n = fruits.size();
        int unplaced = 0;
        vector<bool> used(n, false);  
        for (int i = 0; i < n; ++i) 
        {
            bool placed = false;
            for (int j = 0; j < n; ++j) 
            {
                if (!used[j] && baskets[j] >= fruits[i]) 
                {
                    used[j] = true;   
                    placed = true;   
                    break;
                }
            }
            if (!placed) 
            {
                unplaced++; 
            }
        }
        return unplaced;
    }
};