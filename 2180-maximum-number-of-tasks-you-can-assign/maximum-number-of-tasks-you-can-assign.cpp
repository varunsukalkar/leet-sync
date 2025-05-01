class Solution {
public:
     bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k) {
        multiset<int> total_available_workers(workers.end() - k, workers.end());
        int remaining_pills = pills;

        for (int i = k - 1; i >= 0; --i) {
            int task = tasks[i];
            auto it = total_available_workers.lower_bound(task);
            if (it != total_available_workers.end()) {
                total_available_workers.erase(it);
            } 
            else {
                if (remaining_pills == 0) return false;
                it = total_available_workers.lower_bound(task - strength);
                if (it == total_available_workers.end()) return false;
                total_available_workers.erase(it);
                remaining_pills--;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int lo = 0, hi = min(tasks.size(), workers.size());
        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(check(tasks, workers, pills, strength, mid)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
};