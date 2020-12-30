MAX_QSIZE = 10
class CircularQueue: # 원형큐를 이용하여 미로탐색을 구현하기위한 CircularQueue 클래스
    def __init__(self): # 파이썬 리스트를 이용한 큐 구현
        self.front = 0 # 원형큐의 전단의 위치 설정
        self.rear = 0 # 원형큐의 후단의 위치 설정 
        self.items = [None] * MAX_QSIZE # 원형큐의 크기 설정 

    def enqueue(self, item) : # 큐에 항목을 추가하는 함수
       if not self.isFull() :
           self.rear = (self.rear+1) % MAX_QSIZE
           self.items[self.rear] = item 
           
    def isFull(self) : return self.front == (self.rear+1) % MAX_QSIZE # 큐가 꽉 찼는지를 알려주는 함수
    def isEmpty(self) : return self.front == self.rear # 큐가 비어있는지를 판단하는 함수 전단과 후단이 같은 결과를 반환
   
    def dequeue(self) : # 큐에 항목을 제거하는 함수 
        if not self.isEmpty() :
            self.front = (self.front+1) % MAX_QSIZE
            return self.items[self.front]

class TNode : # 이진트리를 위한 노드 클래스
    def __init__(self,data,left,right) : # 생성자
        self.data = data # 노드의 데이터
        self.left = left # 왼쪽 자식 노드
        self.right = right # 오른쪽 자식 노드

def inorder(n) : # 중위 순회
    if n is not None : # root 노드가 None이 아니면
        inorder(n.left) # 왼쪽 서브트리 처리
        print(n.data, end = " ") # 루트노드 처리
        inorder(n.right) # 오른족 서브트리 처리
         
def preorder(n) : # 전위 순회
    if n is not None : # root 노드가 None이 아니면 
        print(n.data, end = " ") # 루트노드 처리
        preorder(n.left) # 왼쪽 서브트리 처리
        preorder(n.right) # 왼쪽 서브트리 처리


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

def calc_height(n) : # 트리의 높이 계산 
    if n is None : # n이 None이면 공백트리 이므로 
        return 0 # 0을 반환
    hLeft = calc_height(n.left) # 왼쪽 서브트리의 높이
    hRight = calc_height(n.right) # 오른쪽 서브트리의 높이
    if(hLeft>hRight) : # 더 높은 높이에 1을 더해 반환
        return hLeft + 1 
    else :
        return hRight + 1
#=====================================================================
g = TNode('G', None, None)
c = TNode('C', None, None)
d = TNode('D', None, None)
b = TNode('B', c, d)
f = TNode('F', None, g)
e = TNode('E', None, f)
root = TNode('A', b, e)

print('\n   In-order : ', end = " ")
inorder(root)
print('\n\n  Pre-order : ', end = " ")
preorder(root)
print('\n\n post-order : ', end = " ")
postorder(root)
print('\n\nLevel-order : ', end = " ")
levelorder(root)
print()
print("\n노드의 개수 = %d개" % count_node(root))
print("\n단말의 개수 = %d개" % count_leaf(root))
print("\n트리의 높이 = %d" % calc_height(root))
