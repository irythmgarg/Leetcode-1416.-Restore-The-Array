class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[100001]; // dp[i] stores the number of ways to split s[i:]

    // Recursive function to count the number of valid ways to split s[i:]
    int count(string &s, int k, int i)
    {
        // If we've reached the end of the string, it's a valid split
        if (i >= s.length()) return 1;

        // If the string starts with '0', it's invalid
        if (s[i] == '0') return 0;

        // If result is already computed, return it
        if (dp[i] != -1) return dp[i];

        long long num = 0; // Store the current number being formed
        long long ans = 0; // Total number of valid splits from index i

        // Try forming all valid numbers starting at index i
        for (int j = i; j < s.length(); j++)
        {
            num = num * 10 + (s[j] - '0'); // Build the number digit by digit

            // Stop if the number exceeds k
            if (num > k) break;

            // Recur for the rest of the string and add to answer
            ans += count(s, k, j + 1);
            ans %= mod; // Take modulo at each step to prevent overflow
        }

        // Store and return the result for index i
        return dp[i] = ans;
    }

    // Main function to initiate the recursive process
    int numberOfArrays(string s, int k) {
        memset(dp, -1, sizeof(dp)); // Initialize dp array with -1
        return count(s, k, 0);      // Start recursion from index 0
    }
};
