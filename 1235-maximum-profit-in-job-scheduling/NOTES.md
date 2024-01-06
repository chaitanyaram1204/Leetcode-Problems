​# Intuition
The problem requires selecting non-overlapping jobs to maximize the total profit. We can approach this by sorting the jobs based on their end times and then use dynamic programming to find the maximum profit for each job.

# Approach
1. **Sort the Jobs:** Sort the jobs based on their end times.
2. **Dynamic Programming:** Use dynamic programming to find the maximum profit for each job. For each job, consider two cases:
   - Pick the current job: Add its profit to the maximum profit of the job that finishes just before it starts.
   - Skip the current job: Consider the maximum profit obtained so far without including the current job.
3. **Memoization:** Use memoization to avoid recomputing the same subproblems.
4. **Binary Search for Previous Job:** For each job, use binary search to find the job that finishes just before it starts to efficiently determine the index for the recursive call.

# Complexity
- **Time complexity:** The sorting step takes O(n log n), and for each job, there is a binary search operation, resulting in a time complexity of O(n log n).
- **Space complexity:** The space complexity is O(n) due to the memoization array.
