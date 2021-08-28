def firstIndex(arr, n):
    # Your code goes here
    first = -1
    if n==1:
            if arr[0] == 1:
                return 0
    for i in range(0,n-1):
            if arr[i] == 1:
                first = i
    if first != -1:
        return first
    elif first == -1:
        return -1


def maxProfit(prices):
    min = prices[0]
    max = 0
    for i in range(0,len(prices)):
       if min>prices[i]:
           min = prices[i]
           
       elif max<prices[i]-min:
           max = prices[i]
    
    return max

prices = [7,6,4,3,1]
test = [1]
print(firstIndex(test,1))
# print(maxProfit(prices))