class Solution {
public:
    const int mod = 1e9 + 7;

    // Recursive function to count the number of ways to split the string
    // such that every number formed is <= k and doesn't start with '0'
    int count(string &s, int k, int i)
    {
        // Base case: if we've reached the end, it's a valid split
        if (i >= s.length()) return 1;

        // If the current number starts with '0', it's invalid
        if (s[i] == '0') return 0;

        long long num = 0;     // Stores the number being formed
        long long ans = 0;     // Stores total ways from this index

        // Try forming numbers from index i to j
        for (int j = i; j < s.length(); j++)
        {
            // Form the number by appending one digit at a time
            num = num * 10 + (s[j] - '0');

            // If number exceeds k, stop (further digits will only increase it)
            if (num > k) break;

            // Recur for the remaining string and accumulate answers
            ans += count(s, k, j + 1);
            ans %= mod;  // Take modulo at every step to avoid overflow
        }

        return ans;
    }

    // Entry point: returns total number of ways to split string into valid integers
    int numberOfArrays(string s, int k) {
        return count(s, k, 0);
    }
};
