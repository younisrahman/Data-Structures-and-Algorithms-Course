for capacity in range(w+1):
            arr[item][capacity] = "i : "+str(item) + ' j : '+str(capacity)
            # # This is guaranteed to exist
            # maxValWithoutCurr = arr[item - 1][capacity]
            # maxValWithCurr = 0  # We initialize this value to 0
            # # We use item - 1 to account for the extra row at the top
            # weightOfCurr = wt[item - 1]
            # if capacity >= weightOfCurr:  # We check if the knapsack can fit the current item
            #     # If so, maxValWithCurr is at least the value of the current item
            #     maxValWithCurr = val[item - 1]
            #     # remainingCapacity must be at least 0
            #     remainingCapacity = capacity - weightOfCurr
            #     # Add the maximum value obtainable with the remaining capacity
            #     maxValWithCurr += arr[item - 1][remainingCapacity]

            #     # Pick the larger of the two
            #     arr[item][capacity] = max(maxValWithoutCurr, maxValWithCurr)