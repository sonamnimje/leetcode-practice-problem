#include <bits/stdc++.h>
using namespace std;

struct Key {
    int s, d, t;
    bool operator==(Key const& o) const { return s==o.s && d==o.d && t==o.t; }
};
struct KeyHash {
    size_t operator()(Key const& k) const noexcept {
        // simple mixing into 64-bit then hash
        uint64_t x = (uint64_t)k.s * 1000003u + (uint64_t)k.d * 10007u + (uint64_t)k.t;
        return std::hash<uint64_t>()(x);
    }
};

class Router {
    int memoryLimit;
    deque<array<int,3>> q; // FIFO: {source, destination, timestamp}
    unordered_set<Key, KeyHash> seen; // duplicates
    unordered_map<int, deque<int>> destMap; // destination -> deque of timestamps (increasing)

public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        Key k{source, destination, timestamp};
        if (seen.count(k)) return false;

        // evict oldest if needed
        if ((int)q.size() >= memoryLimit) {
            auto old = q.front(); q.pop_front();
            Key oldk{old[0], old[1], old[2]};
            seen.erase(oldk);
            auto &dq = destMap[old[1]];
            // oldest overall must be the oldest for that destination => pop_front
            if (!dq.empty() && dq.front() == old[2]) dq.pop_front();
            // if dq becomes empty we can optionally erase the key to save memory
            if (dq.empty()) destMap.erase(old[1]);
        }

        // add new packet
        q.push_back({source, destination, timestamp});
        seen.insert(k);
        destMap[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto pkt = q.front(); q.pop_front();
        Key k{pkt[0], pkt[1], pkt[2]};
        seen.erase(k);
        auto &dq = destMap[pkt[1]];
        if (!dq.empty() && dq.front() == pkt[2]) dq.pop_front();
        if (dq.empty()) destMap.erase(pkt[1]);
        return {pkt[0], pkt[1], pkt[2]};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destMap.find(destination);
        if (it == destMap.end()) return 0;
        auto &dq = it->second;
        // deque supports random-access iterators; lower_bound/upper_bound works
        auto lb = lower_bound(dq.begin(), dq.end(), startTime);
        auto ub = upper_bound(dq.begin(), dq.end(), endTime);
        return int(ub - lb); // random-access -> O(1) distance
    }
};
