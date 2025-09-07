class Solution {
public:
    void backtrack( int n, vector<int>& nums,
                   vector<vector<int>>& result , vector<int>& path , vector<bool>& visited) {
        if (path.size() == n) {
            result.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;

           
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

            visited[i] = true;
            path.push_back(nums[i]);
            backtrack( n , nums, result, path, visited);
            path.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());  
        int n = nums.size();

        vector<int> path;
        vector<vector<int>> result;
        vector<bool> visited(nums.size(), false);
        backtrack(n, nums,result, path, visited);
        return result;
    }
};