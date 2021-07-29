class TNode : # 이진트리를 위한 노드 클래스
    def __init__(self,data,left,right) : # 생성자
        self.data = data # 노드의 데이터
        self.left = left # 왼쪽 자식 노드
        self.right = right # 오른쪽 자식 노드
         
def preorder(n) : # 전위 순회
    if n is not None : # root 노드가 None이 아니면 
        print(n.data, end = " ") # 루트노드 처리
        preorder(n.left) # 왼쪽 서브트리 처리
        preorder(n.right) # 왼쪽 서브트리 처리

def inorder(n) : # 중위 순회
    if n is not None : # root 노드가 None이 아니면
        inorder(n.left) # 왼쪽 서브트리 처리
        print(n.key, end = " ") # 루트노드 처리
        inorder(n.right) # 오른족 서브트리 처리

def postorder(n) : # 후위 순회
    if n is not None : # root 노드가 None이 아니면
        postorder(n.left) # 왼쪽 서브트리 처리
        postorder(n.right) # 오른쪽 서브트리 처리
        print(n.data, end = " ") # 루투 노드 처리

def levelorder(root) : # 레벨 순회
    queue = CircularQueue() # 원형 큐를 이용햐여 큐 객체 초기화
    queue.enqueue(root) # 큐에 root 노드를 제일 먼저 집어 넣음
    while not queue.isEmpty() : # 큐가 빌때까지 반복
        n = queue.dequeue() # 큐의 맨 앞의 노드를 꺼냄
        if n is not None : #
            print(n.data, end =' ') # 노드의 정보를 출력
            queue.enqueue(n.left) # 꺼낸 노드의 왼쪽 자식을 큐에 삽입
            queue.enqueue(n.right) # 꺼낸 노드의 오른쪽 자식을 큐에 삽입

def count_node(n) : # 트리의 노드 수 계산
    if n is None : # n이 None 이면 공백트리 이므로
        return 0 # 0반환
    else : # 공백트리가 아닐경우
        return 1 + count_node(n.left) + count_node(n.right) # 좌우 서브트리의 노드수의 합 + 1을 반환

def count_leaf(n) : # 단말노드 갯수 계산
    if n is None : # n이 None이면 공백트리 이므로
        return 0 # 0을 반환
    elif n.left is None and n.right is None : # 좌우 자식노드가 비어있으면 단말노드 
        return 1 # 1을 반환
    else :
        return count_leaf(n.left) + count_leaf(n.right) # 비 단말 노드 일 경우에는 좌우 서브트리의 결과합을 반환

def is_complete_binary_tree(n) : # 완전 이진트리 확인 
    check_cbt = (2 ** calc_height(n))-1 # 2의 트리의 높이수만큼 제곱에서 -1했을때가 완전 이진 트리의 노드의 수
    if (check_cbt == count_node(n)) : # 트리의 노드 수와 완전 이진트리일 경우의 노드수를 비교
        return True # 동일하면 True
    else : # 동일하지 않다면
        return False # False

def calc_height(n) : # 트리의 높이 계산 
    if n is None : # n이 None이면 공백트리 이므로 
        return 0 # 0을 반환
    hLeft = calc_height(n.left) # 왼쪽 서브트리의 높이
    hRight = calc_height(n.right) # 오른쪽 서브트리의 높이
    if(hLeft>hRight) : # 더 높은 높이에 1을 더해 반환
        return hLeft + 1 
    else :
        return hRight + 1

class BSTNode : # 이진탐색트리를 위한 노드 클래스 
    def __init__(self,key,value) : # 생성자 
        self.key = key # 생성자를 이용한 키 초기화
        self.value = value # 생성자를 이용한 값 초기화
        self.left = None
        self.right = None

def search_bst(n,key) : # 이진탐색트리 탐색연산
    if n == None : # n이 None이면 공백트리이므로
        return None # 0 반환
    elif key == n.key : # 입력한 키와 key와 동일하면 탐색성공 n 반환
        return n
    elif key < n.key : # 입력한 키가 n의 키보다 작으면  
        return search_bst(n.left,key) # 왼쪽 서브트리 탐색
    else : # 입력한 키가 n의 키보다 크면
        return search_bst(n.right,key) # 오른쪽 서브트리 탐색

def search_value_bst(n,value) : # 값을 이용한 탐색
    if n == None : return None # n이 None이면 공백트리이므로 0 반환
    elif value == n.value : # 입력한 값과 n의 값이 동일하면 n 반환
        return n
    res = search_value_bst(n.left,value) # 왼쪽 서브트리에서 탐색
    if res is not None : # 탐색이 성공이면
        return res # 결과 반환
    else :  # 탐색 실패일 경우
        return search_value_bst(n.right,value) # 오른쪽 서브트리에서 탐색

def search_max_bst(n) : # 최대 값의 노드 탐색
    while n != None and n.right != None :# 모든 노드를 다 비교
        n = n.right
    return n

def search_min_bst(n) : # 최소 값의 노드 탐색
    while n!= None and n.right != None : # 모든 노드를 다 비교
        n = n.left
    return n

def insert_bst(r,n) : # 노드 삽입 연산
    if n.key < r.key : # 삽입할 노드의 키가 루트보다 작으면
        if r.left is None : # 루트의 왼쪽 자식이 없으면
            r.left = n # n은 루트의 왼쪽 자식이 됨
            return True 
        else : # 루트의 왼쪽 자식이 있으면
            return insert_bst(r.left,n) # 왼쪽 자식에게 삽입하도록 함
    elif n.key > r.key :  # 삽입할 노드의 키가 루트보다 크면
        if r.right is None : # 루트의 오른쪽 자식이 없으면
            r.right = n # n은 루트의 오른쪽 자식이 됨
            return True
        else :  # 루트의 오른쪽 자식이 있으면
            return insert_bst(r.right,n) # 오른쪽 자식에게 삽입하도록 함1
    else : # 키가 중복되면
        return False # 삽입 실패

def delete_bst_case1(parent,node,root) : # 단말 노드 삭제
    if parent is None : # 삭제할 단말 노드가 루트이면
        root = None # 공백트리가 됨
    else : 
        if parent.left == node : # 삭제할 노드가 부모의 왼쪽 자식이면
            parent.left = None # 부모의 왼쪽 링크를 None
        else : # 오른쪽 자식이면
            parent.right = None # 부모의 오른쪽 링크를 None
    return root # root가 변경될 수 있으므로 반환

def delete_bst_case2(parent,node,root) : # 자식이 하나인 노드 삭제
    if node.left is not None : #삭제할 노드가 왼쪽 자식만 가짐
        child = node.left # child는 왼쪽 자식
    else : # 삭제할 노드가 오른쪽 자식만 가짐
        child = node.right # childe는 오른쪽 자식

    if node == root : # 없애려는 노드가 루트이면
        root = child # 이제 child가 새로운 루트가 됨
    else : # 
        if node is parent.left : # 삭제할 노드가 부모의 왼쪽 자식
            parent.left = child # 부모의 왼쪽 링크를 변경
        else : # 삭제할 노드가 부모의 오른쪽 자식
            parent.right = child # 부모의 오른쪽 링크를 변경
    return root # root가 변경될 수 있으므로 반환

def delete_bst_case3(parent,node,root) : # 두 개의 자식을 모두 갖는 노드의 삭제
    succp = node # 후계자의 부모 노드
    succ = node.right # 후계자 노드
    while (succ.left != None) : # 후계자와 부모노드 탐색
        succp = succ
        succ = succ.left
    if (succp.left == succ) : # 후계자가 왼쪽 자식이면
        succp.left = succ.right # 후계자의 오른쪽 자식 연결
    else : # 후계자가 오른쪽 자식이면
        succp.right = succ.left # 후계자의 왼쪽 자식 연결
    node.key = succ.key # 후계자의 키와 값을
    node.value = succ.value # 삭제할 노드에 복사
    node = succ # 실제로 삭제하는것은 후계자 노드

    return root #root 반환

def delete_bst(root,key) : # 이진탐색트리 삭제연산
    if root == None : return None

    parent = None # 삭제할 노드의 부모 탐색
    node = root # 삭제할 노드 탐색
    while node != None and node.key != key : # parent 탐색
        parent = node
        if key <  node.key : node = node.left
        else : node = node.right 
    if node == None : return None # 삭제할 노드가 없음
    if node.left == None and node.right == None : # 단말 노드
        root = delete_bst_case1(parent,node,root)
    elif node.left == None or node.right == None : # 유일한 자식
        root = delete_bst_case2(parent,node,root)
    else : # 두개의 자식
        root = delete_bst_case3(parent,node,root)
    return root # root 반환


class BSTMap() : # 이진탐색트리를 이요한 맵
    def __init__(self) : # 생성자
        self.root = None
    def isEmpty(self) : return self.root == None # 맵 공백검사
    def clear(self) : self.root = None # 맵 초기화
    def size(self) : return count_node(self.root) # 노드수 계산
    def search(self,key) : return search_bst(self.root,key) # 키를 이용한 탐색
    def searchValue(self,key) : return search_value_bst(self.root,key) # 값을 이용한 탐색
    def findMax(self) : return search_max_bst(self.root) # 최댓값 탐색
    def findMin(self) : return search_min_bst(self.root) # 최솟값 탐색

    def insert(self,key, value = None) : # 삽입 연산
        n = BSTNode(key, value)
        if self.isEmpty() :
            self.root = n
        else : 
            insert_bst(self.root,n)
    def delete(self,key) : # 삭제 연산
        self.root = delete_bst(self.root,key)
    def display(self, msg = 'BSTMap :') : # 출력연산
        print(msg, end ='') 
        inorder(self.root)
        print()

#========================================================
map = BSTMap()
data = [35,18,7,26,12,3,68,22,30,99]

print("[삽입연산] : ", data)
for key in data :
    map.insert(key)
map.display("[중위 순회] : ")
if map.search(26) != None : print('[탐색 26] : 성공')
else : print('[탐색 26] : 실패')
if map.search(25) != None : print('[탐색 25] : 성공') 
else : print('[탐색 25] : 실패')

map.delete(3);  map.display("[   3 삭제] : ")
map.delete(68); map.display("[  68 삭제] : ")
map.delete(18); map.display("[  18 삭제] : ")
map.delete(35); map.display("[  35 삭제] : ")