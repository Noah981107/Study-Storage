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

class Stack() : # 스택으로 미로탐색을 구현하기위한 Stack 클래스
    def __init__(self) : # 파이썬 리스트를 이용한 스택 구현
        self.top = []
    def isEmpty(self) : return len(self.top) ==0 # 스택이 비어있는지를 판단하는 함수
    def size(self) : return len(self.top) # 스택의 길이, 크기를 알려주는 함수
    def clear(self) : self.top = [] # 스택을 초기화하는 함수
     
    def push(self, item) : # 스택의 맨위에 항목을 추가하는 함수
        self.top.append(item) 
    
    def pop(self) : # 스택의 맨위의 항목을 빼는 함수
        if not self.isEmpty() : # 스택이 비어있지 않으면 실행
            return self.top.pop(-1) 
    
    def peek(self) : # 스택의 맨위의 항목을 선택하는 함수
        if not self.isEmpty() : # 스택이 비어있지 않으면 실행
            return self.top[-1]

#========================================

def isValidPos(x,y) : # 미로 탐색중 범위를 넘어가는지 확인하는 함수
    if x<0 or y<0 or x>=MAX_SIZE or y>= MAX_SIZE :
        return False
    else :
        return map[y][x] == '0' or map[y][x] == 'x'

def DFS() : # 스택을 이용한 미로찾기 실행 함수
    stack = Stack() # 스택 객체 생성
    stack.push((0,1)) # 시작 지점에 대한 정보를 스택에 추가
    print('DFS: ') 
    
    while not stack.isEmpty() : # 스택이 빌때까지 실행
        here = stack.pop() # 현재위치는 스택의 맨위의 항목
        print(here, end = ' ') 
        (x,y) = here # 현재 위치를 튜플로 변경
        if(map[y][x] == 'x') : # 도착지점 x이면 반환값 True
            return True
        else :
            map[y][x] = '.' # 지나간 지점에 대해서는 . 으로 표시함
            if isValidPos(x,y-1) : stack.push((x,y-1)) # 아래로 한칸 이동
            if isValidPos(x,y+1) : stack.push((x,y+1)) # 위로 한칸 이동
            if isValidPos(x-1,y) : stack.push((x-1,y)) # 왼쪽으로 한칸 이동
            if isValidPos(x+1,y) : stack.push((x+1,y)) # 오른쪽로 한칸 이동   
        print(' 현재 스택: ', stack)
    return False
#==============================================================                
result = DFS() # 변수 result에 DFS()의 반환값을 넣음
if result : print('--> 미로탐색 성공!') # result의 값이 True면 실행 
else : print('--> 미로탐색 실패ㅠㅠ') # result의 값이 False일 경우
