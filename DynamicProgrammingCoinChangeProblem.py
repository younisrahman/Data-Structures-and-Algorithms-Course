import sys


def minCoin(n, arr, dp):

    if n == 0:
        return 0
    ans = sys.maxsize

    for i in range(len(arr)):
        if n-arr[i] >= 0:
            if dp[n-arr[i]] != -1:

            subAns = minCoin(n - arr[i], arr, dp)
            if subAns != sys.maxsize and subAns + 1 < ans:
                ans = subAns + 1
    return ans


n = 18
arr = [7, 5, 1]
dp = [n+1]*-1
dp[0] = 0
print(minCoin(n, arr, dp))
