# Python code for linear searching an array
# and return the postion of the query if it exists
# else return -1, does not exist

# Search method
def search(arr, n, x):
    assert type(x) == int
    assert len(arr) < 10**3
    assert n == len(arr)
    
    for i in range (0, n):
        if arr[i] == x :
            return i;
    return -1;
    
# Driver code
def main():
    arr = [90, 22, 79, 59, 54, 12, 29, 47, 7, 96]
    n = len(arr)
    # Query
    query = input("Enter an integer query: ")
    # Searchig
    result = search(arr, n, query) 
    if result == -1: 
        print("Element is not present in array") 
    else: 
        print("Element is present at position", result+1);


# Running main module when called from source
# Using special variable
# __name__
if __name__=="__main__":
    main()










        
