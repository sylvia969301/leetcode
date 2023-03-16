import heapq
from collections import defaultdict

"""  [Problem]
        - You are given a network of n nodes, labeled from 1 to n.
          You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi),
          where ui is the source node, vi is the target node, 
          and wi is the time it takes for a signal to travel from source to target.
    
    [Idea]
        - Use Dijkstra's algorithm (greedy approach) to find the shortest path.

    [Complexity]
        - Time : O(N + ELogN) -Standard Time complexity of Dijkstra's algorithm
        - Space : O(N + E) - for adjacency list and maintaining Heap.
"""
class Solution_Dijkstra(object):
    def networkDelatTime(self, times, n, k):
        minHeap = [(0, k)] #(time, node)
        visited = set()
        elapsedTime = [0] + [float('inf')] * n
        
        adjList = defaultdict(list)
        for x, y, w in times:
            adjList[x].append((y, w))
        # print(adjList)

        while minHeap:
            # print(minHeap)
            travelTime, node = heapq.heappop(minHeap) # (0, 2)
            visited.add(node)
            if len(visited) == n : break
            if travelTime < elapsedTime[node]:
                elapsedTime[node] = travelTime
                for y, w in adjList[node]:
                    heapq.heappush(minHeap, (travelTime + w, y))
        maxT = max(elapsedTime)
        return maxT if maxT < float('inf') else -1
    
class Solution_2_Dijkstra(object):
    def networkDelayTime(self, times, n, k):
        """
        :type times: List[List[int]]
        :type n: int
        :type k: int
        :rtype: int
        """
        minHeap = [(0, k)]
        visited = set()

        adjList = defaultdict(list)
        for x, y, w in times:
            adjList[x].append((w, y))

        while minHeap:
            travelTime, node = heapq.heappop(minHeap)
            visited.add(node)

            if len(visited)== n :
                return travelTime
            
            for time, adjNode in adjList(node):
                if adjNode not in visited:
                    heapq.heappush(minHeap, (travelTime+time, adjNode))

        return -1

