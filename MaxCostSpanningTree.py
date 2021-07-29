parent = [] # 노드들의 부모 노드를 가르킬 리스트 parent
set_size = 0 # 집합의 갯수는 0

def init_set(nSets) : # 집합의 초기화 함수
    global set_size, parent # 전역변수 parent, set_size 사용
    set_size = nSets # 집합의 개수 설정
    for i in range(nSets) : # 집합의 개수 만큼
        parent.append(-1) # 모든 노드에 대하여 부모 노드를 -1로 설정

def find(id) : # 부모노드를 찾는 함수
    while (parent[id] >=0) : # 노드의 부모노드가 없을때까지 반복
        id = parent[id] # id는 부모 노드의 id로 갱신
    return id # 트리의 최상단 노드인 부모 노드 반환
 
def union(s1,s2) : # 두 집합을 합하는 함수
    global set_size # 전역변수 set_size 사용 
    parent[s1] = s2  # s2를 s1의 부모 노드로 변경하여 s1, s2를 합침
    set_size = set_size - 1 # 집합의 개수를 1 감소

def MSTKruskal(vertex, adj) : # 최소 비용 신장 트리 알고리즘
    vsize = len(vertex) # 정점의 갯수 7
    init_set(vsize) # 집합의 갯수를 7로 설정
    eList = [] # 정점과 간선에 대한 정보를 담을 eList

    for i in range(vsize-1) : # 정점의 갯수만큼 반복
        for j in range(i+1, vsize) :  # 가중치를 포함한 간선에 대한 리스트에서 항목을 찾음
            if adj[i][j] != None : # 간선이 있으면
                eList.append((i,j,adj[i][j])) # 리스트에 위치와 간선의 가중치를 넣음
    eList.sort(key=lambda e : e[2]) # 리스트를 정렬함

    edgeAccepted = 0 # 간선의 갯수를 세기위한 변수 edgeAccepted
    sum = 0 # 가중치의 합을 계산하기 위한 변수 sum
    while (edgeAccepted < vsize-1) : # 정점의 갯수 -1 만큼 반복
        e = eList.pop(-1) # 리스트의 맨 위에서 하나 꺼냄
        uset = find(e[0])  # 정점1의 위치를 저장할 변수 uset
        vset = find(e[1])  # 정점2의 위치를 저장할 변수 vset
    if uset != vset : # 두 정점이 같지 않으면 실행
            print("간선 추가 : (%s,%s,%s) " %  (vertex[e[0]], vertex[e[1]], e[2]))
            union(uset,vset)  # 두 정점을 합침
            sum += e[2] # 가중치를 다 더함
            edgeAccepted += 1 # 간선의 갯수 1 증가
            print("MaxST 가중치의 합 = ", sum) # 가중치의 합 출력

#==================================================================================================
vertex = ['A', 'B', 'C', 'D', 'E', 'F', 'G'] # 정점에 해당하는 리스트
weight = [[None,    29,    None,    None,    None,    10,    None],  # 가중치를 포함한 간선에 대한 리스트
          [29,      None,  16,      None,    None,    None,  15],   
          [None,    16,    None,    12,      None,    None,  None], 
          [None,    None,  12,      None,    22,      None,  18],   
          [None,    None,  None,    22,      None,    27,    25],   
          [10,      None,  None,    None,    27,      None,  None], 
          [None,    15,    None,    18,      25,      None,  None]] 

print("MST By Kruskal's Algorithm")
MSTKruskal(vertex,weight)

