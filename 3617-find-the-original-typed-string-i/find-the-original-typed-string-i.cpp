class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
    vector<pair<char, int>> groups;
    int i = 0;
    while (i < n) {
        char ch = word[i];
        int j = i;
        while (j < n && word[j] == ch) {
            j++;
        }
        groups.push_back({ch, j - i});
        i = j;
    }
    int total = 1; 
    for (auto& [ch, count] : groups) {
        if (count >= 2) {
            total += (count - 1); 
        }
    }
    return total;
    }
};