def sort012(array):
    low = 0
    mid = 0
    high = len(array)-1
    for i in array:
        if array[mid] == 0:
            temp = array[mid]
            array[mid] = array[low]
            array[low] = temp
            mid+=1
            low+=1
        
        elif array[mid] == 1:
            mid+=1
            
        else:
            temp = array[mid]
            array[mid] = array[high]
            array[high] = temp
            high-=1
            
array = [1,2,1,1,2,0,1,0,2,0,2,0]
sort012(array)
print(array)