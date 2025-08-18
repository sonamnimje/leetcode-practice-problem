class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) 
    {
        sort(meetings.begin(), meetings.end());
        long long covered = 0; 
        long long start = meetings[0][0];
        long long end = meetings[0][1];
        for (int i = 1; i < meetings.size(); i++) 
        {
            if (meetings[i][0] <= end) 
            {
                end = max(end, (long long)meetings[i][1]);
            } else {
                covered += (end - start + 1);
                start = meetings[i][0];
                end = meetings[i][1];
            }
        }
        covered += (end - start + 1);
        return (int)((long long)days - covered);
    }
};