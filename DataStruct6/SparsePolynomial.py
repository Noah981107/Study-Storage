class Node : # 연결리스트를 위한 노드 클래스
    def __init__(self,elem,link=None) : # 생성자. 디폴트 인수 사용
        self.data = elem # 데이터 멤버 생성 및 초기화
        self.link = link # 링크 생성 및 초기화
         
class LinkedList : # 연결된 리스트
    def __init__(self) : # 생성자 
        self.head = None # 리스트 항목이 없기에 self.head = None
    def isEmpty(self) : return self.head == None # 공백상태 검사
    def clear(self) : self.head =None # 리스트 초기화
    def size (self) : # 리스트 항목 수 계산
        node = self.head # 시작 노드 
        count = 0 # 리스트 항목의 수를 세기위한 변수 count
        while node is not None : # node가 None이 아닐 때 까지 반복
            node = node.link # 다음 노드로 이동
            count += 1 # count 증가
        return count # count 반환
    def display(self, msg = 'LinkedList : ') : # 스택의 항목 출력 함수
        print(msg, end = "") # 입력받은 메세지 msg 출력
        node = self.head # 시작 노드
        while node is not None : # node가 None이 아닐 때 까지 반복
            print(node.data, end = "->") # node의 데이터 멤버 출력
            node = node.link # 다음 노드로 이동
        print(' ') 
    def getNode(self, pos) : # pos 위치의 노드 반환
        if pos < 0 : return None  # pos 위치가 0보다 작으면 None 반환
        node = self.head # node는 head 부터 시작
        while pos > 0 and node != None : # pos 위치가 0보다 크고, node가 None이 아닐 때 까지 반복
            node = node.link # node를 다음 노드로 이동
            pos -= 1 # 남은 반복 횟수 줄임 
        return node # pos 위치의 노드 반환
    def getEntry(self,pos) : # pos 위치의 노드의 데이터 반환
        node = self.getNode(pos) # pos번째 노드 가져오기
        if node == None : return None # 찾는 노드가 없는경우에는 None 반환
        else : return node.data # 찾는 노드가 있으면 그 노드의 데이터 반환
    def replace(self,pos,elem) : # pos위치의 노드의 데이터를 변경
        node = self.getNode(pos) # pos번째 노드 가져오기
        if node != None : node.data = elem # 데이터 필드에 elem 복사
    def find(self,data) : # 데이터로 data를 갖는 노드 반환 
        node = self.head # node는 head 부터 시작
        while node is not None : # 모든 노드에서 찾기위한 반복 
            if node.data == data : return node # 원하는 data의 값의 노드를 반환 
            node = node.link # node를 다음 노드로 이동 
        return node # 찾아지지 않으면 마지막 노드가 가르키는 None 반환
    def insert(self,pos,elem) : # 연결된 리스트에서 pos번째에 elem의 데이터를 가지는 노드 삽입
        before = self.getNode(pos-1) # before 노드를 찾음 
        if before == None : # 맨앞에 삽입하는 경우
            self.head = Node(elem,self.head) # 맨 앞에 삽입함
        else : # 중간에 삽입하는 경우
            node = Node(elem, before.link) # 노드 생성 이전 노드가 앞의 노드를 가리키게 함
            before.link = node # 이전 노드가 삽입한 노드를 가리키게 함
    def delete(self, pos) : # pos위치의 노드를 삭제
        before = self.getNode(pos-1) # before 노드를 찾음
        if before == None : # 시작노드를 삭제
            if self.head is not None : # 공백이 아니면 
                self.head = self.head.link # head를 다음으로 이동 
        elif before.link != None : # 중간에 있는 노드 삭제 
            before.link = before.link.link # 이전의 노드가 삭제할 노드의 앞의 노드를 가리키게 함

class Term : # 다항식의 항을 나타내는 클래스
    def __init__(self, expo, coef) : 
        self.expo = expo # 항의 지수
        self.coef = coef # 항의 계수

class SparesePoly(LinkedList) : # 희소 다항식 클래스
    def __init__(self) : # 생성자
        super().__init__() # 부모 클래스의 생성자를 부름
    def degree(self) : # 최고차수 반환
        if self.head == None : return 0
        else : return self.head.data.expon
    def display(self, msg = " ") :
         print(msg, end = "") # 입력받은 메세지 msg 출력
         node = self.head # 시작 노드
         while node is not None : # node가 None이 아닐 때 까지 반복
            print(node.data.coef," x^",node.data.expo,end = " ") # node의 데이터 멤버 출력
            if node.link == None : # node의 다음 노드가 None이면 반복문을 빠져나감
                break 
            print("+", end = " ")
            node = node.link # 다음 노드로 이동
         print(" ")
    def read(self) : # 사용자로부터 두 개의 다항식을 입력받음
        self.clear() # 다항식 클래스를 비움
        token = input("입력(계수 지수 계수 지수 ... [엔터] : ").split(" ")
        for i in range(len(token) // 2) :
            self.insert(self.size(), Term(int(token[i*2+1]), float(token[i*2])))
    
    def add(self,b) : # 두 다항식을 더하는 메소드
        c = SparesePoly() # 두 다항식의 결과를 저장할 객체 c
        node1 = self.head # 더해지는 다항식의 시작 노드
        node2 = b.head # 더할 다항식의 시작 노드
        while node1 is not None and node2 is not None : # 노드 두개가 둘다 None일 경우 종료 
            if(node1.data.expo == node2.data.expo) : # 항의 지수가 같을 경우
                c.insert(c.size(), Term(node1.data.expo, node1.data.coef + node2.data.coef))
                node1= node1.link
                node2= node2.link
            elif (node1.data.expo > node2.data.expo) : # 항의 지수가 클 경우
                c.insert(c.size(), Term(node1.data.expo, node1.data.coef))
                node1= node1.link
            else : # 항의 지수가 작을 경우
                c.insert(c.size(), Term(node2.data.expo,node2.data.coef))
                node2= node2.link
        return c
    
    def neg(self) : # 다항식의 전체 항에 -1을 곱하는 경우
        d = SparesePoly() # 두 다항식의 결과를 저장할 객체 d
        node = self.head # 노드의 시작 
        while node is not None : # 노드가 None일경우 종료
            d.insert(d.size(), Term(node.data.expo, -node.data.coef))
            node = node.link
        return d

    def sub(self,b) : # 다항식의 뺄셈 
        e = SparesePoly() # 두 다항식의 결과를 저장할 객체 e
        node1 = self.head # 빼지는 다항식의 시작노드
        node2 = b.head # 빼는 다항식의 시작 노드 
        while node1 is not None and node2 is not None : # 노드 두개가 둘다 None일 경우 종료
            if(node1.data.expo == node2.data.expo) : # 항의 지수가 같을 경우
                e.insert(e.size(), Term(node1.data.expo, node1.data.coef - node2.data.coef))
                node1= node1.link
                node2= node2.link
            elif (node1.data.expo > node2.data.expo) : # 항의 지수가 클 경우 
                e.insert(e.size(), Term(node1.data.expo, node1.data.coef))
                node1= node1.link
            else : # 항의 지수가 작을 경우
                e.insert(e.size(), Term(node2.data.expo,-node2.data.coef))
                node2= node2.link
        return e

    def mult(self,b) : # 다항식의 곱셈  
        f = SparesePoly() # 두 다항식의 결과를 저장할 객체 f
        node1 = self.head # 곱해지는 다항식의 시작 노드
        node2 = b.head # 곱하는 다항식의 시작 노드 
        while node1 is not None and node2 is not None : # 노드 두개가 둘다 None일 경우 종료
                f.insert(f.size(),Term((node1.data.expo + node2.data.expo),(node1.data.coef * node2.data.coef)))
                node2 = node2.link
        node1 = node1.link
        return f
#==========================================================================
a = SparesePoly()
b = SparesePoly()

a.read()
b.read()
c = a.add(b)
d = a.neg()
e = a.sub(b)
f = a.mult(b)

a.display(" A = ")
b.display(" B = ")
c.display(" A+B = ")
d.display(" -A = ")
e.display(" A-B = ")
f.display(" AxB = ")