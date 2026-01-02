"""
Task: Check if a given array represents a valid max-heap
Time Complexity: O(n)
Space Complexity: O(1)
"""

def is_max_heap(a):
    n=len(a)
    for i in range((n-2)//2+1):
        l=2*i+1; r=2*i+2
        if l<n and a[i] < a[l]: return False
        if r<n and a[i] < a[r]: return False
    return True

print(is_max_heap([90,15,10,7,12,2,7,3]))
