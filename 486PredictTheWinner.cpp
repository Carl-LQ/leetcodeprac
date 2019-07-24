class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.size() == 0)
            return true;
        int N = nums.size();
        vector<vector<int>> f(N, vector<int>(N, 0));
        vector<vector<int>> s(N, vector<int>(N, 0));
        for (int j = 0; j < N; ++j) {
            f[j][j] = nums[j];
            for (int i = j - 1; i >= 0; --i) {
                f[i][j] = max(nums[i]+s[i+1][j], nums[j]+s[i][j-1]);
                s[i][j] = min(f[i+1][j], f[i][j-1]);
            }
        }
        
        return f[0][N-1] >= s[0][N-1];
    }
};


// brute force
// means first pick, nums[i...j]
int f(vector<int> &nums, int i, int j) {
    if (i == j)
        return nums[i];
    
    return max(nums[i]+s(nums, i+1, j), nums[j]+s[nums, i, j-1]);
}

// means second pick, nums[i...j]
int s(vector<int> &nums, int i, int j) {
    if (i == j)
        return 0;
    
    return min(f(nums, i+1, j), f(nums, i, j-1));
}

// get maximal score
int win(vector<int>& nums) {
    if (nums.size() == 0) 
        return 0;
    
    return max(f(nums, 0, nums.size()-1), s(nums, 0, nums.size()-1));
}