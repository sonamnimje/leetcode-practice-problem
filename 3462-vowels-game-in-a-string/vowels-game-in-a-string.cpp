class Solution {
public:
    bool doesAliceWin(string s) 
    {
        static const unordered_set<char> V = {'a','e','i','o','u'};
        for (char c : s) if (V.count(c)) return true;
        return false; 
    }
};