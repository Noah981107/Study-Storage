# Bag을 추상자료형으로 구현하기
# python 사용
def contains(bag,e):  #bag에 e가 있으면 True, 없으면 False
    return e in bag

def insert(bag,e):    #bag에 e항목을 맨 마지막에 추가
    bag.append(e)

def remove(bag,e):    #bag에서 e항목을 제거
    bag.remove(e)

def count(bag):       #bag에 있는 전체 항목의 갯수를 셈
    return len(bag)

def numOf(bag, e) :   #bag에 있는 e항목의 갯수를 셈
    count = 0
    for i in range(len(bag)):
        if bag[i] == e :
            count = count + 1
    return count

#===========================================
myBag = []                 # myBag이라는 객체
insert(myBag, '휴대폰')    # myBag에 휴대폰 추가
insert(myBag, '지갑')      # myBag에 지갑 추가
insert(myBag, '손수건')    # myBag에 손수건 추가
insert(myBag, '빗')        # myBag에 빗 추가
insert(myBag, '자료구조')  # myBag에 자료구조 추가
insert(myBag, '야구공')    # myBag에 야구공 추가
 
print("기존 가방속의 물건 : ", myBag)  # 가방속의 물건 내용 출력
add = input('\n추가 하고 싶은 물건을 입력하세요 : ')  # 추가하고 싶은 물건의 입력을 input메소드를 이용하여 add에 저장 
insert(myBag, add) #입력받은 물건을 가방에 추가
elim = input('\n빼고 싶은 물건을 입력하세요 : ') # 제거하고 싶은 물건의 입력을 input메소드를 이용하여 elim에 저장  
remove(myBag, elim)  # 입력받은 물건을 가방에서 제거
print("\n현재 가방속의 물건 : ", myBag) # 물품을 추가 및 제거한 후 현재 가방속의 물건 내용 출력

goods = input("\n찾으시는 물건을 입력해주세요 : ").strip()  # 찾으시는 물건의 입력을 input메소드를 이용하여 goods에 저장
print("\n찾으시는 물건의 갯수: ", numOf(myBag,goods)) # myBag안에 찾으시는 물건의 갯수를 출력

