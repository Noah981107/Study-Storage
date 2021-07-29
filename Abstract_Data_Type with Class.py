class Bag() :            # Bag 클래스
    
    bag = list()         # 변수 bag은 리스트
    
    def insert(e) :# 리스트 bag에 e를 추가하는 함수
        bag.append(e)
                         
    def remove(self, e) :# 리스트 bag에서 e를 제거하는 함수
        bag.remove(e)
#================================
myBag = Bag()             # 객체 생성
bag = myBag.bag           
myBag.insert('휴대폰')    # myBag에 휴대폰 추가
myBag.insert('지갑')      # myBag에 지갑 추가
myBag.insert('손수건')    # myBag에 손수건 추가
myBag.insert('빗')        # myBag에 빗 추가
myBag.insert('자료구조')  # myBag에 자료구조 추가
myBag.insert('야구공')    # myBag에 야구공 추가
print('내 가방속의 물건 : ', bag)

myBag.insert('JAVA')        # myBag에 빗 추가
myBag.remove('휴대폰')    # myBag에 손수건 추가
print('내 가방속의 물건 : ', bag) 






