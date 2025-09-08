class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int size = timeSeries.size();
        int out = duration;
        for (int i = 1; i < size; i++) {
            out += min(timeSeries[i] - timeSeries[i - 1], duration);
        }
        return out;
    }
};