def insertionSort(arr):
    n = len(arr)  
    
    # If the array is empty or has one element, no need to sort
    if n <= 1:
        return   
    
    # Traverse through 1 to n
    for i in range(1, n):  
        key = arr[i]  # The current element to be compared
        j = i - 1
        
        # Move elements of arr[0..i-1] that are greater than key
        # to one position ahead of their current position
        while j >= 0 and key < arr[j]:  
            arr[j + 1] = arr[j]  
            j -= 1
            
        arr[j + 1] = key  # Place the key in the correct position

# Example usage
arr = [12, 11, 13, 5, 6]
insertionSort(arr)
print("Sorted array:", arr)
