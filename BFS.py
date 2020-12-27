



map = [[ '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' ], # 미로 맵
      [ 'e', '0', '0', '0', '0', '1', '1', '1', '0', '1' ],
      [ '1', '1', '0', '1', '1', '1', '0', '0', '0', '1' ],
      [ '1', '1', '0', '1', '0', '1', '0', '1', '0', '1' ],
      [ '1', '1', '0', '1', '0', '1', '0', '1', '0', '1' ],
      [ '1', '0', '0', '0', '0', '1', '0', '1', '0', '1' ],
      [ '1', '0', '1', '1', '0', '1', '0', '1', '0', 'x' ],
      [ '1', '0', '1', '1', '0', '0', '0', '1', '1', '1' ],
      [ '1', '0', '1', '1', '0', '1', '1', '1', '1', '1' ],
      [ '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' ]]
#===========================================================
MAX_QSIZE = 10 # 미로의 크기가 10*10이므로 최대크기를 나타내는 상수 MAX_QSIZE
class CircularQueue: # 원형큐를 이용하여 미로탐색을 구현하기위한 CircularQueue 클래스
    def __init__(self): # 파이썬 리스트를 이용한 큐 구현
        self.front = 0 # 원형큐의 전단의 위치 설정
        self.rear = 0 # 원형큐의 후단의 위치 설정 
        self.items = [None] * MAX_QSIZE # 원형큐의 크기 설정 
    def isEmpty(self) : return self.front == self.rear # 큐가 비어있는지를 판단하는 함수 전단과 후단이 같은 결과를 반환 
    def isFull(self) : return self.front == (self.rear+1) % MAX_QSIZE # 큐가 꽉 찼는지를 알려주는 함수
    def clear(self) : self.front = self.rear # 큐를 초기화 하는 함수

    def enqueue(self, item) : # 큐에 항목을 추가하는 함수
        if not self.isFull() :
            self.rear = (self.rear+1) % MAX_QSIZE
            self.items[self.rear] = item

    def dequeue(self) : # 큐에 항목을 제거하는 함수 
        if not self.isEmpty() :
            self.front = (self.front+1) % MAX_QSIZE
            return self.items[self.front]

    def peek(self) : # 큐에서 하나의 항목을 선택하는 함수
        if not self.isEmpty() :
            return self.items[(self.front +1) % MAX_QSIZE]
         
    def size(self) : # 큐의 길이, 크기를 알려주는 함수
        return (self.rear - self.front + MAX_QSIZE) % MAX_QSIZE

#================================================================================
def isValidPos(x,y) :  # 미로 탐색중 범위를 넘어가는지 확인하는 함수
    if x<0 or y<0 or x>=MAX_QSIZE or y>= MAX_QSIZE :
        return False
    else :
        return map[y][x] == '0' or map[y][x] == 'x'
def BFS() : # 큐를 이용한 미로찾기 실행 함수
    que = CircularQueue() # 큐 객체 생성
    que.enqueue((0,1)) # 시작 지점에 대한 정보를 큐에 추가 
    print('BFS:')
    
    while not que.isEmpty() : # 큐가 빌때까지 실행
        here = que.dequeue() # 현재위치는 큐의 맨 앞 항목
        print(here,end='->')
        x,y = here # 현재위치를 변경
        if(map[y][x] == 'x') : return True
        else :
            map[y][x] = '.'  # 지나간 지점에 대해서는 . 으로 표시함
            if isValidPos(x,y-1) : que.enqueue((x,y-1)) # 아래로 한칸 이동
            if isValidPos(x,y+1) : que.enqueue((x,y+1)) # 위로 한칸 이동
            if isValidPos(x-1,y) : que.enqueue((x-1,y)) # 왼쪽으로 한칸 이동
            if isValidPos(x+1,y) : que.enqueue((x+1,y)) # 오른쪽로 한칸 이동    
    return False
#===============================================================
result = BFS() # 변수 result에 DFS()의 반환값을 넣음
if result : print('--> 미로탐색 성공') # result의 값이 True면 실행
else : print('--> 미로탐색 실패') # result의 값이 False일 경우
