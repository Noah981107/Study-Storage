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
MAX_SIZE = 10 # 미로의 크기가 10*10이므로 최대크기를 나타내는 상수 MAX_SIZE
class PriorityQueue : # 우선순위큐로 미포탐색을 구현하기위한 PriorityQueue 클래스
    def __init__(self) : # 파이썬 리스트를 이용한 큐 구현
        self.items=[]

    def isEmpty(self) : # 큐가 비어있는지를 판단하는 함수
        return len(self.items) ==0

    def size(self) : return len(self.items) # 큐의 길이, 크기를 알려주는 함수

    def clear(self) : self.items = [] # 큐를 초기화하는 함수

    def enqueue(self, item) : # 큐에 항목을 추가하는 함수
        self.items.append(item)

    def findMaxIndex(self) : # 큐에서 최댓값을 찾는 함수
        if self.isEmpty() : return None # 큐가 비어있다면 None 반환
        else :
            highest = 0 # 최댓값을 0으로 설정 
            for i in range(1,self.size()) : # 큐의 길이만큼 반복문 진행
                if self.items[i][2] > self.items[highest][2] : # 각 칸에 대하여 비교 진행 
                    highest = i 
            return highest

    def dequeue(self) : # 큐에 항목을 제거하는 함수
        highest = self.findMaxIndex()
        if highest is not None :
            return self.items.pop(highest)

    def peek(self) : # 큐의 항목을 선택하는 함수
        highest = findMaxIndex()
        if highest is not None :
            return self.items[highest]
#================================================================================
def isValidPos(x,y) : # 미로 탐색중 범위를 넘어가는지 확인하는 함수
    if x<0 or y<0 or x>=MAX_SIZE or y>= MAX_SIZE :
        return False
    else :
        return map[y][x] == '0' or map[y][x] == 'x'

import math # math 패키지를 사용
(ox,oy) =(7,10) # 출구의 위치
def dist(x,y) : # 출구로부터의 거리계산 함수
    (dx,dy) = (ox-x, oy-y)
    return math.sqrt(dx*dx + dy*dy)

def MySmartSearch() : # 우선순위큐를 이용한 미로탐색
    q = PriorityQueue() # 우선순위큐 객체 생성
    q.enqueue((0,1,-dist(0,1))) # 초기 시작 위치를 큐에 추가
    print('PQueue :')
    
    while not q.isEmpty() : # 큐가 빌때까지 실행
        here = q.dequeue()  # 현재위치를 큐에서 꺼냄
        print(here[0:2], end = '->')
        x,y,_ = here # 현재 위치를 거리를 추가하여 변경
        if(map[y][x] == 'x') : return True 
        else :
             map[y][x] = '.' # 지나간 지점에 대해서는 . 으로 표시함
        if isValidPos(x,y-1) : q.enqueue((x,y-1,-dist(x,y-1))) # 아래로 한칸 이동
        if isValidPos(x,y+1) : q.enqueue((x,y+1,-dist(x,y+1))) # 위로 한칸 이동
        if isValidPos(x-1,y) : q.enqueue((x-1,y,-dist(x-1,y))) # 왼쪽으로 한칸 이동
        if isValidPos(x+1,y) : q.enqueue((x+1,y,-dist(x+1,y))) # 오른쪽로 한칸 이동
        print('우선순위큐 : ', q.items)
    return False
#===============================================================
result = MySmartSearch() # 변수 result에 MySmartSearch()의 반환값을 넣음
if result : print('--> 미로탐색 성공') # result의 값이 True면 실행
else : print('--> 미로탐색 실패') # result의 값이 False일 경우
