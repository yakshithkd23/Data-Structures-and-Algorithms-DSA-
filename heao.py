import heapq # finding largest element in the max_heap, smallest element in min_heap
min_heap = []
heapq.heappush(min_heap, 10)
heapq.heappush(min_heap, 20)
heapq.heappush(min_heap, 5)

print(heapq.heappop(min_heap))  

max_heap = []
heapq.heappush(max_heap, -10) 
heapq.heappush(max_heap, -20)
heapq.heappush(max_heap, -5)

print(-heapq.heappop(max_heap))  