class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };
        
        // Max heap {gain, pass, total}
        priority_queue<tuple<double,int,int>> pq;
        
        for (auto &c : classes) {
            pq.push({gain(c[0], c[1]), c[0], c[1]});
        }
        
        while (extraStudents--) {
            auto [g, pass, total] = pq.top();
            pq.pop();
            pass++;
            total++;
            pq.push({gain(pass, total), pass, total});
        }
        
        double sum = 0.0;
        while (!pq.empty()) {
            auto [g, pass, total] = pq.top();
            pq.pop();
            sum += (double)pass / total;
        }
        
        return sum / classes.size();
    }
};
