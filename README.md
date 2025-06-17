# Leetcode-1416.-Restore-The-Array
# 🤖 Number of Arrays to Form an Integer <= k - README

## 📊 Problem Statement

You are given a string `s` containing only digits and an integer `k`. You need to split the string into **non-empty** substrings such that:

1. Each substring represents a **positive integer without leading zeros**.
2. Each integer is **less than or equal to k**.

Return the total number of ways to split the string under the above constraints. Since the answer may be large, return it modulo `10^9 + 7`.

---

## 🪄 Approach 1: Pure Recursion

### ✅ Idea

We use recursion to try every possible way to split the string by choosing a valid number starting at every index and recursively solving the rest.

### 📉 Steps:

1. At each index, try to take 1 to `n` digits and form a number.
2. If the number starts with `0`, skip (invalid).
3. If the number exceeds `k`, break.
4. Recursively compute the count for the rest of the string.

### ⏱ Time Complexity

* **Exponential**, due to overlapping subproblems.

### � Space Complexity

* O(n) for recursion stack.

### 📖 Example

```text
s = "123", k = 12
Valid splits: [1|2|3], [12|3], [1|23] => 2 valid (23 > 12 is invalid)
```

---

## 🧪 Approach 2: Recursion + Memoization (Top-Down DP)

### ✅ Idea

Same as recursive approach but we **cache** the results using a `dp[]` array to avoid recomputation.

### 📉 Steps:

1. Maintain a dp array of size `s.length()` initialized with `-1`.
2. For each index, if `dp[i] != -1`, return the stored result.
3. Else compute the result as in the recursive method.
4. Store and return the value.

### ⏱ Time Complexity

* **O(n \* log k)**: For each index, we try up to `log(k)` length numbers.

### � Space Complexity

* **O(n)** for the dp array and recursion stack.

### 💪 Benefits

* Much faster than the pure recursive approach.
* Prevents TLE for large strings.

---

## 🔄 Comparison

| Feature              | Recursive Only | Recursive + Memoization |
| -------------------- | -------------- | ----------------------- |
| Time Complexity      | Exponential    | O(n \* log k)           |
| Space Complexity     | O(n)           | O(n)                    |
| Handles Large Input  | ❌              | ✅                       |
| Reuse of Subproblems | ❌              | ✅                       |

---

## 🌐 Example

```text
Input: s = "1000", k = 10000
Output: 1
Explanation: Only valid split is [1000]
```

---

## 👤 Author

**Ridham Garg**

> Designed with clarity ✨ and performance ⚡ in mind! Let me know if you'd like a bottom-up (tabulation) approach as well 🚀
