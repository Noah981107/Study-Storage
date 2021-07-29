def fib(n): # 순환 방식을 이용한 피보나치 수열                             
    if n == 0 : return 0
    elif n==1 : return 1
    else : 
        return fib(n-1) + fib(n-2)
    
def fib_iter(n): # 반복 방식을 이용한 피보나치 수열
    if (n<2) : return n

    last = 0
    current = 1
    for i in range(2, n+1) :
        tmp = current
        current += last
        last = tmp
    return current

def check_time(n) : # 순환방식에서의 시간을 체크
    import time
    start = time.time()
    fib(n)
    end = time.time()
    return end - start

def check_time_iter(n) : # 반복방식에서의 시간을 체크
    import time
    start = time.time()
    fib_iter(n)
    end = time.time()
    return end - start

#======================================
select = int(input("피보나치 수열을 찾고 싶은 수를 입력하세요 : ")) # 피보나치 수열을 찾고싶은 번째에 해당하는 숫자를 input메소드를 이용하여 int형으로 select에 저장
print("반복 피보나치 수열 : ",fib_iter(select)) # 반복 피보나치 수열 출력
print("순환 피보나치 수열 : ",fib(select)) # 순환 피보나치 수열 출력

print("\n<반복과 순환의 속도처리 차이 비교>")
for i in range(1,40) : # 반복문을 이용하여 반복과 순환의 처리속도 차이 비교
    import time
    start = time.time()
    print('n=',i,'반복 : ',check_time_iter(i), '순환 : ', check_time(i))





