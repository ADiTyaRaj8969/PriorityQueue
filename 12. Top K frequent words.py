"""
Task: Return the K most frequent words from a list of strings
Time Complexity: O(n log k)
Space Complexity: O(n)
"""

import heapq
from collections import Counter

def top_k_words(words,k):
    cnt = Counter(words)
    pq = []
    for w,f in cnt.items():
        heapq.heappush(pq, (f, w))
        if len(pq)>k: heapq.heappop(pq)
    res = [heapq.heappop(pq)[1] for _ in range(len(pq))]
    return res[::-1]

print('Top words:', top_k_words(['i','love','leetcode','i','love','coding'],2))
