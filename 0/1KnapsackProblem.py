# print('0/1 Knapsack Problem')

# def knapsack(w, wt, val, n):


#     return arr


w = 10
n = 4
val = [20, 30, 10, 50]
wt = [1, 3, 4, 6]
arr = [[0 for i in range(w+1)] for j in range(n+1)]
for item in range(1, n+1):

    for capacity in range(1, w+1):
        # arr[item][capacity] = item, capacity
        # print(arr[item][capacity])
        # This is guaranteed to exist
        maxValWithoutCurr = arr[item - 1][capacity]
        maxValWithCurr = 0  # We initialize this value to 0
        # We use item - 1 to account for the extra row at the top
        weightOfCurr = wt[item - 1]
        if capacity >= weightOfCurr:  # We check if the knapsack can fit the current item
            # If so, maxValWithCurr is at least the value of the current item
            maxValWithCurr = val[item - 1]
            # remainingCapacity must be at least 0
            remainingCapacity = capacity - weightOfCurr
            # Add the maximum value obtainable with the remaining capacity
            maxValWithCurr += arr[item - 1][remainingCapacity]

            # Pick the larger of the two
        arr[item][capacity] = max(maxValWithoutCurr, maxValWithCurr)
        print(max(maxValWithoutCurr, maxValWithCurr))
for r in arr:
    for c in r:
        print(c, end=" ")
    print()
