class Node : # 노드 클래스
    def __init__(self,elem,link=None) : # 생성자에서 디폴트 인수를 사용하여 초기화
        self.data = elem # 데이터 멤버 생성 및 초기화
        self.link = link # 링크 생성 및 초기화
class Entry: # 엔트리 클래스
    def __init__(self,key,value) : # 생성자에서 디폴트 인수를 사용하여 초기화
        self.key = key # 키
        self.value = value # 값
    def __str__(self) : # 키와 값에 대한 출력
        return str("%s:%s"%(self.key, self.value))
class HashChainMap : # 해시 체인 맵
    def __init__(self,M) : # 생성자에서 디폴트 인수 사용
        self.table = [None] * M # M 크기의 테이블 생성
        self.M = M
    
    def hashFn(self,key) : # 사용할 해시 함수 
        sum = 0 # 문자열의 아스키 코드 값을 저장할 변수 sum
        for c in key : # 문자열의 모든 문자에 대해
            sum = sum + ord(c) # 아스키 코드 값을 모두 더함  
        return sum % self.M # 테이블의 수만큼 나눈 나머지 반환

    def insert(self,key,value) : # 삽입 연산 메소드, 인수로 키와 값을 입력받음 
        idx = self.hashFn(key) # 입력한 키에 해당하는 해시 주소 계산 
        entry = Entry(key,value) # 엔트리를 생성
        node = Node(entry)
        if self.table[idx] is None : # 테이블의 항목이 비었을때
            node.link = self.table[idx]
            self.table[idx] = node # 테이블의 idx항목은 node로 시작
        else : # 항목이 비어있지 않을때
           for i in range (1,len(self.table)-idx) : # 해시 체인 맵의 길이에서 해시함수 반환값을 뺀 만큼 반복
               if self.table[idx+i] is None : # 테이블이 비어있으면
                   node.link = self.table[idx+i] # 그자리에 정보 삽입
                   self.table[idx+i] = node # 정보를 연결
                   break; 
               if idx + i == 13 : # 해시 체인 맵의 끝에 도달했을때
                   idx = 0 # 다시 인덱스를 0으로 변경하여 저장
       
    def search(self,key) : # 탐색 연산 메소드
        idx = self.hashFn(key) # 입력한 키에 해당하는 해시 주소 계산
        while self.table[idx] is not None : # 테이블의 항목이 비어 있지 않을때
            if self.table[idx].data.key == key : # 테이블 항목이 키와 동일하면
                return self.table[idx].data # 테이블 항목의 데이터 반환 
            else : # 맵의 항목이 비어있을때
                for i in range(1,len(self.table)-idx) : # 해시 체인 맵의 길이에서 해시함수 반환값을 뺀 만큼 반복
                    if self.table[idx+i].data.key == key : # 맵의 키와 입력 키가 동일하면
                        return self.table[idx+i].data # 그 위치에서의 데이터 반환
                    else : 
                        self.table[idx].link # 다음 순서로 넘김
        return None

    def delete(self,key) : # 삭제 연산 메소드
        idx = self.hashFn(key) # 입력한 키에 해당하는 해시 주소 계산
        while self.table[idx] is not None : # 맵이 비어있지 않으면 반복
            if self.table[idx].data.key == key : # 맵 항목의 데이터 키와 동일하면
                return self.table[idx].data # 그 위치의 데이터 반환
            else : # 맵 항목의 데이터 키와 동일하지 않으면
                for i in range(1,len(self.table)-idx) : # 해시 체인 맵의 길이에서 해시함수 반환값을 뺀만큼 반복
                    if (self.table[idx+i].data.key == key) : # 맵 항목의 데이터 키와 동일하면
                        self.table[idx+i] = None # 그 자리를 비움
                        break # 반복문 탈출
                    else :
                        self.table[idx].link # 다음 순서로 넘김
                break
        return None

       
    def display(self,msg) : # 출력 연산 메소드
        print(msg) # 메시지 출력
        for idx in range(len(self.table)) : # 테이블 길이만큼 반복
            node = self.table[idx] # 시작 노드 
            if node is not None : # 노드가 None이 아니면
                print("[%2d] -> " % idx , end ='') # 출력
                while node is not None : # 노드가 None이 아니면 반복
                    print(node.data, end = '') # 노드 출력
                    node = node.link # 다음 순서로 넘김
                print()
#=========================================================================
map = HashChainMap(13)
map.insert('data', '자료')
map.insert('structure', '구조')     
map.insert('sequential search', '선형 탐색')
map.insert('game', '게임')
map.insert('binary search', '이진 탐색')
map.display("나의 단어장: ")

print("탐색: game --> ", map.search('game'))
print("탐색: over --> ", map.search('over'))
print("탐색: data --> ", map.search('data'))

map.delete('game')
map.display("나의 단어장: ")
print("탐색: game -->", map.search('game'))
