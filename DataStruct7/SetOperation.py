class Set : # 집합 클래스
    def __init__(self) : # 생성자
        self.items=[] # 원소를 저장하기 위한 리스트
    
    def size(self) : # 집합의 크기
        return len(self.items) # lent() 메소드를 이용하여 리스트의 길이 반환 

    def display(self,msg) : # 화면에 출력
        print(msg, self.items) # 메시지 + 집합의 내용 출력

    def contains(self, item) : # 집합이 item을 포함하는지 확인함
        return item in self.items # item이 self.items에 있는지 in 연산자를 사용하여 검사함.
    
    def insert(self,elem) : # 정렬된 상태를 유지하면서 elem 삽입
        if elem in self.items : return # self에 elem이 있으면 삽입 안함
        for idx in range(len(self.items)) : # self의 길이만큼 
            if elem < self.items[idx] : # self.items[idx]의 idx를 찾음
                self.items.insert(idx,elem) # 그 위치에 삽입
                return
        self.items.append(elem) # 맨 뒤에 삽입

    def __eq__(self,setB) : # 두 집합이 같은 집합인지 비교연산
        if self.size() != setB.size() : # self와 setB의 크기가 같지않으면 실행불가
            return False 
        for idx in range(len(self.items)) : # self의 길이만큼 idx 반복
            if self.items[idx] != setB.items[idx] : # 원소별로 같은지 검사
                return False 
        return True

    def delete(self,elem) : # 집합에서 elem 삭제
        if elem in self.items : # 집합에 elem이 있으면 
            self.items.remove(elem) # 집합에서 elem 삭제

    def union(self, setB) : # 합집합을 만드는 메소드
        newSet = Set() # 합집합을 나타낼 newSet
        a = 0 # 집합 self의 원소에 대한 인덱스
        b = 0 # 집합 setB의 원소에 대한 인덱스
        while a < len(self.items) and b <len(setB.items) : # self의 길이와 b의 길이만큼 반복
            valueA = self.items[a] # 집합 self의 현재 원소
            valueB = setB.items[b] # 집합 setB의 현재 원소
            if (valueA < valueB) : # self의 현재원소의 값이 setB의 현재 원소의 값보다 작을 경우
                newSet.items.append(valueA) # self의 현재 원소 값을 newSet에 삽입
                a += 1 # self 집합의 인덱스 증가
            elif (valueA > valueB) : # self의 현재 원소의 값이 setB의 현재 원소보다 값이 클 경우
                newSet.items.append(valueB) # setB의 현재 원소 값을 newSet에 삽입
                b += 1 # setB 집합의 인덱스 증가
            else :  # 두 집합의 원소가 같을 경우
                newSet.items.append(valueA) # self의 현재원소를 newSet에 삽입
                a += 1 # self 집합의 인덱스 증가 
                b += 1 # setB 집합의 인덱스 증가
        while a < len(self.items) : # self 집합의 남은 원소를 모두 추가
                newSet.items.append(self.items[a])
                a +=  1
        while b < len(setB.items) : # setB 집합의 남은 원소를 모두 추가
                newSet.items.append(setB.items[b])
                b += 1    
        return newSet # 합집합 반환

    def intersect(self,setB) : # 교집합을 만드는 메소드
        newSet = Set() # 교집합을 나타날 newSet
        a = 0 # 집합 self의 원소에 대한 인덱스
        b = 0 # 집합 setB의 원소에 대한 인덱스
        while a < len(self.items) and b < len(setB.items) : # 집합 setB의 원소에 대한 인덱스
            valueA = self.items[a] # 집합 self의 현재 원소
            valueB = setB.items[b] # 집합 setB의 현재 원소  
            if (valueA != valueB) : # 현재의 원소들이 다를 경우
                b += 1 # 집합 self를 기준으로하여 집합 setB의 인덱스를 1증가
                if (b == len(setB.items)) : # 집합 setB의 인덱스를 증가하다가 인덱스 끝에 도달하면
                    b = 0 # 집합 setB의 인덱스를 0으로 초기화
                    a += 1 # 기준 집합 self의 인덱스를 1증가
            if (valueA == valueB) : # 현재의 원소들이 같을 경우
                newSet.items.append(valueA) # 교집합 newSet에 삽입
                a += 1 # 집합 self의 인덱스 증가
                b += 1 # 집합 setB의 인덱스 증가
        return newSet # 교집합 newSet 반환

    def difference(self, setB) : # 차집합을 만드는 메소드
        newSet = Set() # 차집합을 나타낼 newSet
        a = 0 # 집합 self의 원소에 대한 인덱스
        b = 0 # 집합 setB의 원소에 대한 인덱스
        while a < len(self.items) and b < len(setB.items) : # 집합 setB의 원소에 대한 인덱스
            valueA = self.items[a] # 집합 self의 현재 원소
            valueB = setB.items[b] # 집합 setB의 현재 원소
            if(valueA != valueB) : # 현재의 원소들이 다를 경우
                b += 1 # 비교 집합 setB의 인덱스를 1증가
                if (b == len(setB.items)) :  # 집합 setB의 인덱스를 증가하다가 인덱스 끝에 도달하면
                    newSet.items.append(valueA)  # 차집합 newSet에 삽입
                    a += 1 # 집합 self의 인덱스 증가
                    b = 0  # 집합 setB의 인덱스 초기화
            else : # 현재의 원소들이 같을 경우
                a += 1 # 집합 self의 인덱스 증가
                b += 1 # 집합 setB의 인덱스 증가
        return newSet # 차집합 newSet 반환
#=======================================================================
setA = Set()
setA.insert(9)
setA.insert(2)
setA.insert(1)
setA.display('Set A:')
    
setB = Set()
setB.insert(9)
setB.insert(6)
setB.insert(5)
setB.insert(0)
setB.display('Set B:')
setA.union(setB).display('A U B : ')
setA.intersect(setB).display('A ^ B : ')
setA.difference(setB).display('A - B : ')