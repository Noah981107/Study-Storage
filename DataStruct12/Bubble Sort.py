def printStep(arr,val) : # 정렬 단계를 출력하는 함수
    print(" Step %2d = " % val, end = " ") 
    print(arr) # 해당 단계의 배열 상태를 출력

def bubble_sort(A) : # 버블 정렬을 통한 정렬
    n = len(A) # 인수 A의 길이 n
    for i in range(n-1,0,-1) : #n의 길이만큼 반복한다
        bChanged = False # 교환이 일어나지 않았을때는 False
        for j in range(i) : 
            if(A[j]>A[j+1]) : # 앞의 항목이 뒷 항목보다 클 경우에는 
                A[j], A[j+1] =  A[j+1], A[j] # 두 항목을 바꾼다
                bChanged = True # 교환이 일어났음으로 True
        if not bChanged : # 교환이 일어나지 않으면
            return False # False를 반환
            break;
        printStep(A,n-i); # 정렬하고 있는 단계별 상태를 출력
    #return True # 정렬이 완료되면 True를 반환

'''
data1 = [1,2,3,4,5,6] # 정렬된 리스트 data1
print("Original : ", data1)
if(bubble_sort(data1)) :
    print("Bubble : ", data1)
else :
    print("이미 정렬되어 있는 배열 입니다.")

'''

data2 = [3,1,5,6,7,2,4] # 정렬이 안된 리스트 data2
print("Original : ", data2)
bubble_sort(data2)