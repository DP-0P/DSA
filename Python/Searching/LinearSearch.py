def LinearSearch(array , search):
    
    index = -1
    for i in range(0,len(array)):
        if(i==search):
            index==i
            
    if(i<0):
        print("Searched element is not available in the array")
    else:
        print("Searched element is available at index "+i)
        
# Time Complexity -
# Best Case - O(1)
# Worst Case - O(n)
# Average Case - O(n/2)

# Space complexity - O(1)
