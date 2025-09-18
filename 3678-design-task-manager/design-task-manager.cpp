class TaskManager {
    struct Task {
        int priority, taskId, userId;
        bool operator<(const Task& other) const {
            if (priority == other.priority) return taskId < other.taskId;
            return priority < other.priority; // max-heap by priority
        }
    };

    priority_queue<Task> pq;  // global heap
    unordered_map<int, pair<int,int>> mp; // taskId -> {userId, priority}

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) add(t[0], t[1], t[2]);
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId, priority};
        pq.push({priority, taskId, userId});
    }
    
    void edit(int taskId, int newPriority) {
        auto [userId, _] = mp[taskId];
        mp[taskId] = {userId, newPriority};
        pq.push({newPriority, taskId, userId});
    }
    
    void rmv(int taskId) {
        mp.erase(taskId); // lazy delete
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            if (mp.count(top.taskId)) {
                auto [uid, pr] = mp[top.taskId];
                if (uid == top.userId && pr == top.priority) {
                    mp.erase(top.taskId);
                    return uid;
                }
            }
        }
        return -1;
    }
};