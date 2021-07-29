def find_connected_component(graph) :
    visited = set()
    colorList = []

    for vtx in graph :
        if vtx not in visited :
            print(vtx)
            color = dfs_cc(graph,[],vtx,visited)
            colorList.append(color)
    print("그래프 연결 성분 개수 = %d" % len(colorList))
    print(colorList)
    return colorList

def dfs_cc(graph,color,vertex,visited) :
    if vertex not in visited :
        visited.add(vertex)
        color.append(vertex)
        nbr = graph[vertex] - visited
        for v in nbr :
            dfs_cc(graph,color,v,visited)
    return color 

def find_bridges(adj,vtx) :
    n = len(vtx)
    count = 0
    for i in range(n) :
        for j in range(i+1,n) :
            if adj[i][j] != 0 :
                adj[i][j] = adj[i][j] = 0
                if find_connected_component(adj,vtx) == 1 :
                    count += 1
                    print("Bridge%d : " % (count,vtx[i],vtx[j]))
                adj[i][j] = adj[i][j] = 1
    return count
#================================
mygraph = {"A" : set(["B", "C"]),
           "B" : set(["A"]),
           "C" : set(["A"]),
           "D" : set(["E"]),
           "E" : set(["D"])}
print('Find_Conneted_Component :')
find_connected_component(mygraph)
print()
