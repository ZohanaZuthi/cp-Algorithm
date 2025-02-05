// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int N = nums.size();
        vector<int> dp(N, -1); // Use vector instead of raw array

        function<int(int)> lis = [&](int i)
        {
            if (dp[i] != -1)
                return dp[i]; // Memoization step
            int ans = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    ans = max(ans, lis(j) + 1);
            }
            return dp[i] = ans;
        };

        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            ans = max(ans, lis(i));
        }
        return ans;
    }
};
