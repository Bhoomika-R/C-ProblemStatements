class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        OldToNew = {}
        
        def dfs(node):
            if node in OldToNew:
                return OldToNew[node]
            
            copy = Node(node.val)
            OldToNew[node] = copy
            for neighbours in node.neighbors:
                copy.neighbors.append(dfs(neighbours))
            return copy
        
        return dfs(node) if node else None
