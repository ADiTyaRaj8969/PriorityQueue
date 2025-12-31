"""
Task: Find sum of elements between K1-th and K2-th smallest elements
Time Complexity: O(n log n)
Space Complexity: O(1) extra
"""

def sum_between(a,k1,k2):
    a_sorted = sorted(a)
    return sum(a_sorted[k1:k2-1])

print('Sum between:', sum_between([1,3,12,5,15,11],3,6))
