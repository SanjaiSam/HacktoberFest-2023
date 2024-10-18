# Approach 1: Sorting the List
def max_value_sort(arr):
    if not arr:  # Check if the list is empty
        return None  # Or raise an exception
    arr.sort()
    return arr[-1]

# Approach 2: Iterating Through the List
def max_value_iterate(arr):
    if not arr:  # Check if the list is empty
        return None  # Or raise an exception
    max_element = arr[0]

    for i in range(1, len(arr)):  # Start from index 1
        if arr[i] > max_element:
            max_element = arr[i]

    return max_element

# Approach 3: Using Built-in Function
def max_value_builtin(arr):
    if not arr:  # Check if the list is empty
        return None  # Or raise an exception
    return max(arr)  # This works without recursion now

# Example usage
if __name__ == "__main__":
    arr = [3, 5, 1, 8, 2]

    print("Max using sort:", max_value_sort(arr))
    print("Max using iterate:", max_value_iterate(arr))
    print("Max using builtin:", max_value_builtin(arr))
