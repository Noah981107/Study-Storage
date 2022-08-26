from random import *                                                 # random 모듈에서의 모든 식별자를 사용
min = 0                                                              # 최솟값 min을 0으로 초기화
max = 99                                                             # 최댓값 max를 99로 초기화
chance = 0                                                           # 시도한 기회 chance를 0으로 초기화
answer = randint(min,max)                                            # 정답 answer은 최솟갑과 최댓값의 사이에서 난수로 생성
print('Up and Down Game')                                            # Up and Down Game 출력
for n in range(10) :                                                 # 기회가 10번임으로 반복문을 이용하여 10번 반복
 chance = chance +1                                                  # 반복문이 한번 돌아갈때마다 기회 chance를 1씩 증가
 print('[범위 : %d ~ %d]' % (min, max))                              # 최솟값과 최댓값의 범위를 나타냄
 guess = (int)(input('숫자를 입력하세요 : '))                        # 사용자로부터 숫자를 입력받음
 if guess == answer :                                                # 추측값과 정답이 같을 경우
     break                                                           # break문을 이용하여 반복문을 빠져나감
 elif guess > answer :                                               # 추측값이 정답보다 클 경우
     print('틀렸습니다!! 더 작은 숫자 입니다')                       # 틀렸다는 내용을 출력
     print('\n')                                                     # 한줄 띄기
     max = guess                                                     # 최댓값을 추측값으로 변경
 elif guess < answer :                                               # 추측값이 정답보다 작을 경우
     print('틀렸습니다!! 더 큰 숫자 입니다')                         # 틀렸다는 내용을 출력
     print('\n')                                                     # 한줄 띄기
     min = guess                                                     # 최솟값을 추측값으로 변경
 elif chance == 10:                                                  # 기회 chance가 10일 경우
     break                                                           # break 문을 이용하여 반복문을 빠져나감
if chance == 10 :                                                    # 기회 chance가 10일 경우 
    print('모든 기회가 끝났습니다. 다시 도전해주세요')               # 모든 기회가 끝났다는것을 알림
else :
 print("정답은 %d 입니다~ %d번만에 맞추셨습니다." % (answer,chance)) # 정답과 시도 횟수를 출력
