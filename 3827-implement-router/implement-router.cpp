class Router {
public:
       using Packet = vector<int>;
    int memory;
    queue<Packet> q;
    unordered_set<string> seen;
    unordered_map<int, vector<int>> timestampMap;
    string generateKey(int s, int d, int t) {
        return to_string(s) + "#" + to_string(d) + "#" + to_string(t);
    }

public:
    Router(int memoryLimit) {
        memory = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = generateKey(source, destination, timestamp);
        if (seen.count(key)) return false;
        seen.insert(key);
        q.push({source, destination, timestamp});
        timestampMap[destination].push_back(timestamp);
        if ((int)q.size() > memory) {
            Packet old = q.front(); q.pop();
            string oldKey = generateKey(old[0], old[1], old[2]);
            seen.erase(oldKey);

            auto& vec = timestampMap[old[1]];
            auto it = lower_bound(vec.begin(), vec.end(), old[2]);
            if (it != vec.end() && *it == old[2]) {
                vec.erase(it);
            }
        }

        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        Packet front = q.front(); q.pop();

        string key = generateKey(front[0], front[1], front[2]);
        seen.erase(key);

        auto& vec = timestampMap[front[1]];
        auto it = lower_bound(vec.begin(), vec.end(), front[2]);
        if (it != vec.end() && *it == front[2]) {
            vec.erase(it);
        }

        return front;
    }

    int getCount(int destination, int startTime, int endTime) {
        if (!timestampMap.count(destination)) return 0;
        auto& vec = timestampMap[destination];

        auto low = lower_bound(vec.begin(), vec.end(), startTime);
        auto high = upper_bound(vec.begin(), vec.end(), endTime);

        return high - low;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */