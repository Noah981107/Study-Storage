INF = 9999 # 최대거리
def choose_vertex(dist,found) : # 최소 거리를 가진 정점을 선택하는 함수
    min = INF # 최소 거리를 최대거리로 설정 
    minpos = -1 # 최소 거리를 가진 정점의 인덱스
    for i in range(len(dist)) : #
        if dist[i] < min and found[i] == False : # 정점 간의 거리가 최소거리보다 작고, 해당위치에서 찾지 못햇으면
            min = dist[i] # 해당 정점 간의 거리가 최소거리
            minpos = i # 그 위치의 인덱스를 저장
    return minpos # 해당 위치의 인덱스 반환

def shortest_path_dijkstra(vtx, adj, start) : # 최단경로 코드
    vsize = len(vtx) # 정점의 갯수
    dist = list(adj[start]) # 정점간의 거리를 저장할 리스트
    path = [start] * vsize # 경로를 저장할 리스트
    found = [False] * vsize # 찾은 정점에 대한 정보를 저장할 리스트
    found[start] = True # 처음 위치는 찾음
    dist[start] = 0 # 처음 위치의 거리는 0

    for i in range(vsize) :
        u = choose_vertex(dist, found) # 최소 거리를 가진 정점을 선택하는 함수 실행 후 반환값 삽입
        found[u] = True # 반환된 위치를 찾았다고 표시
        for w in range(vsize) :
            if not found[w] : # found의 w번째가 False이면 실행
                if dist[u] + adj[u][w] < dist[w] : # 거리를 비교해서 실행
                    dist[w] = dist[u] + adj[u][w] # 거리를 변경
                    path[w] = u # 경로에 해당 위치를 삽입
    return (dist,path) # 정점간의 거리와, 경로를 반환

def print_route(collection,start) : # 경로를 출력하는 함수
    dist = collection[0] # 정점간의 거리에 대한 정보를 가진 리스트 dist
    path = collection[1] # 경로를 나타내는 리스트 path
    stack = [] # 경로를 출력하기 위한 스택  
    print("\nSrc->Dst   Dist   Path")
    for end in range(len(vertex)) :
        final_end = end # end가 변화하기에 최종 목적지의 값을 저장 
        if end != start : # end가 start와 다를 때 실행
            print(" %s -> %s    %2d     %s->" % (vertex[start], vertex[end], dist[end],  vertex[start]), end = " ")
            while path[end] != start : # 경로에서 나오는 값이 시작 지점과 다를때까지 반복
                stack.append(vertex[path[end]]) # 스택에 순서대로 삽입
                end = path[end] # end 의 값을 이전 경로로 변경
            while stack : # 스택이 빌때까지 반복
                print("%s->" % stack.pop(),end= " ") # 스택의 위에서부터 하나씩 꺼내서 출력
            print("%s" % vertex[final_end],end=" ") # 마지막 최종 목적지 출력
        print()

#====================================================
vertex = ['A', 'B', 'C', 'D', 'E', 'F', 'G'] # 정점에 대한 정보를 가진 리스트
weight = [[0,   7,   INF,   INF,   3,   10,   INF], # 간선과 가중치에 대한 정보를 가진 리스트
          [7,   0,   4,     10,    2,   6,    INF],  
          [INF, 4,   0,     2,     INF, INF,  INF],
          [INF, 10,  2,     0,     11,  9,    4],  
          [3,   2,   INF,   11,    0,   13,   5],  
          [10,  6,   INF,   9,     13,  0,    INF],
          [INF, INF, INF,   4,     5,   INF,  0]]

print("Shortest Path By Dijkstra Algorithm")
collection = shortest_path_dijkstra(vertex,weight,0) # 최단경로 코드 실행
print_route(collection,0) # 경로 전체 출력