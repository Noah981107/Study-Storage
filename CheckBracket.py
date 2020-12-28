class Stack: # 스택을 구성하는 클래스
	def __init__(self): # 생성자를 이용한 스택 객체 생성 메소드
		self.top = []

	def isEmpty(self) : return len(self.top) == 0 # 스택이 비어있는지 아닌지 여부를 판단하는 메소드
	def size(self) : return len(self.top) # 스택의 길이를 측정하는 메소드

	def clear(self) :self.top = [] # 스택을 초기화하는 메소드

	def push(self, item): self.top.append(item) # 스택에 구성을 추가하는 메소드

	def pop(self): # 스택에서 맨 위의 항복을 추출하는 메소드
		if not self.isEmpty() : # 스택이 비어 있지 안으면 
			return self.top.pop(-1) # 맨 위의 항목 추출

	def peek(self): # 스택에서 맨 위의 항목을 선택하는 메소드 
		if not self.isEmpty() : # 스택이 비어 있지 않으면 
			return self.top[-1] # 맨 위의 항목을 선택
#=========================================================
def checkBracketesV2(statement) : # 괄호 검사 함수
	msg1 = "조건 1 위반" # 조건 1을 위반 하였을 때의 메세지를 나타내는 변수 msg1
	msg2 = "조건 2 위반" # 조건 2을 위반 하였을 때의 메세지를 나타내는 변수 msg2
	msg3 = "조건 3 위반" # 조건 3을 위반 하였을 때의 메세지를 나타내는 변수 msg3
	nLine = 1; # 라인을 계산하기 위한 변수 nLine 초기값은 1
	nChar = 0; # 문자 수를 계산하기 위한 변수 nChar 초기값은 0
	stack = Stack() # 스택을 나타내는 Stack() 클래스의 객체 stack 선언
	for line in lines : # 라인의 수만큼 반복하여 괄호 검사 
		for ch in statement : # 라인에서 문자수 만큼 반복하여 괄호 검사
			if (ch == '\n') : # 마지막 문자가 다음 칸으로 넘어가는 \n 이면 라인수 1증가
				nLine = nLine + 1
			nChar = nChar + 1 # 문자수 계산, 1씩 증가
			if ch in ('{','[','(') : # 문자가 {, [, ( 이면 스택 항목으로 넣음
				stack.push()
			elif ch in ('}',']',')') : # 문자가 }, ], ) 이면
				if stack.isEmpty() : # 스택이 비어있으면
					return (False, msg2,nLine,nChar) # 조건 2 위반
				else : # 스택이 비어 있지 않으면
					left = stack.pop() # 스택의 맨위의 항목부터 추출
					if ( ch == '}' and left != '{') or \
						( ch == ']' and left != '[') or \
						( ch == ']' and left != '[') :
					    return (False, msg3, nLine, nChar)  # 조건 3 위반
	return (False, msg1,nLine,nChar) # 조건 1 위반 
def isValidSource(lines) : # 괄호 검사의 결과를 반환하는 함수
	 jb = checkBracketesV2(lines) # 괄호 검사 함수의 반환값을 변수 jb에 저장
	 if jb[0] == False : # jb의 첫번째 항목이 False이면
		 return (jb[1],jb[2],jb[3]) # jb의 나머지 항목을 반환 
	 else : # jb의 첫번째 항목이 True이면
		 return (0,0,0) # 0을 반환
#=======================================================
filename = "ArrayStack.h" # ArrayStack.h를 괄호 검사 하기위해서 파일이름에 저장 
#filename = "CheckBracketMain.cpp" # CheckBracketMain.cpp를 괄호 검사 하기위해서 파일이름에 저장
print('스택의 응용1: 괄호 검사 %s\n'%filename) # 괄호검사 프로그램임을 알림
#filename = input("검사할 파일 이름:") # 괄호 검사 하고자하는 파일명을 입력받음
infile = open(filename, "r") # 파일을 읽기 모드로 연다
lines = infile.readlines(); # 파일의 한줄한줄 저장한다 
infile.close() # 파일을 닫는다 

eCode, Icnt, ccnt = isValidSource(lines) # 괄호 검사의 결과를 반환하는 함수의 반환값을 변수 eCode, Icnt, ccnt에 저장
print(filename, "-->", eCode) # 어떤 조건을 위반했는지를 출력
print(" 라인수 = ", Icnt) # 몇번째 라인인지를 출력
print(" 문자수 = ", ccnt) # 몇번째 문자인지를 출력
