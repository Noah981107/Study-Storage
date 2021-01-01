def print_graph(adj,vtx) : # 그래프를 출력하는 함수
    for i in range(len(vtx)) : # 정점을 저장한 리스트의 길이만큼 반복
        print(vtx[i], "의 인접정접 : ", end = " ") # 정점의 인접정점의 정보 출력
        for j in range(len(adj[i])) :
            if(adj[i][j] == 1) : # 간선이 연결되어 있으면
                print(vtx[j], end =" ") # 그 위치에 해당하는 정점 출력
        print()  

def dfs_recur(adj,vtx,visited,id) : # 깊이 우선탐색 알고리즘 2
    print(vtx[id], end = " ") # 시작 위치의 정점 출력
    if vtx[id] not in visited : # 정점이 방문 리스트에 없으면
        visited.append(vtx[id]) # 방문 리스트에 추가
    for nxt_id in range(len(adj[id])) : # 간선을 이용하여 정점을 찾는 반복문
        if(adj[id][nxt_id] == 1 and vtx[nxt_id] not in visited) : # 간선으로 연결되어 있고, 해당 위치의 정점이 방문리스트에 없으면
            dfs_recur(adj,vtx,visited,nxt_id) # 깊이 우선탐색 알고리즘 2 실행

def dfs(adj,vtx,s) : # 깊이 우선탐색 알고리즘 1
    n = len(vtx) 
    visited = [] * n # vtx의 길이만큼 방문 리스트 생성
    dfs_recur(adj,vtx,visited,s) # 깊이 우선탐색 알고리즘 2

from queue import Queue

def bfs(adj,vtx,id) : # 너비 우선탐색 알고리즘
    queue = Queue() # 인접 정점을 보관할 큐
    queue.put_nowait(vtx[id]) # 큐에 시작 지점의 정점을 삽입
    visited = [] * len(vtx) # 방문 리스트에 해당하는 리스트

    visited.append(queue.get_nowait()) # 시작 정점은 큐에 들어가 있으므로 큐에서 꺼내 방문 리스트에 삽입
    for id in range(8) :
        for nxt_id in range(8) :
            if(adj[id][nxt_id] == 1 and vtx[nxt_id] not in visited) : # 간선으로 연결되어 있고, 해당 위치의 정점이 방문리스트에 없으면
                queue.put_nowait(vtx[nxt_id]) # 큐에 해당위치의 정점 삽입
        output = queue.get_nowait() # 큐에 삽입했던 정점을 빼냄
        if(output not in visited) : # 빼낸 정점이 방문리스트에 없으면
            visited.append(output) # 방문 리스트에 삽입
    for i in range(len(visited)) : # 방문 리스트를 출력하여 너비 우선탐색 내용 출력
        print(visited[i], end = " ")

#========================================================
vertex = ['A','B','C','D','E','F','G','H']
adjMat =[[ 0,  1,  1,  0,  0,  0,  0,  0], #A
         [ 1,  0,  0,  1,  0,  0,  0,  0], #B
         [ 1,  0,  0,  1,  1,  0,  0,  0], #C
         [ 0,  1,  1,  0,  0,  1,  0,  0], #D
         [ 0,  0,  1,  0,  0,  0,  1,  1], #E   
         [ 0,  0,  0,  1,  0,  0,  0,  0], #F
         [ 0,  0,  0,  0,  1,  0,  0,  1], #G
         [ 0,  0,  0,  0,  1,  0,  1,  0]] #H

print("<그래프 출력>")
print_graph(adjMat,vertex)

print('\nDFS : ', end="")
dfs(adjMat,vertex,0)
print()

print('\nBFS :', end = " ")
bfs(adjMat,vertex,0)
print()
