answer = 0 # 정답을 나타내는 전역변수 answer

class Polynomial : # 다항식 클래스
    def __init__(self) : # 생성자를 이용하여 리스트 객체 생성
        self.coef = []
    
    def degree(self) : # 다항식의 차수를 반환하는 메소드
        return len(self.coef) - 1 # 리스트의 길이에서 -1을 해야지 다항식의 최고차수와 일치한다

    def display(self,msg = "f(x) = ") : # 다항식을 출력하는 메소드
        length = len(self.coef) # len()을 이용하여 객체의 길이를 변수 length에 저장
        print("%s" % msg, end = " ") # 매개변수 f(x) =  에 해당하는 메세지 출력
        for n in range(length-1,-1,-1) : # 리스트의 길이에서 -1씩 줄이면서 반복문을 진행
            print("\t%sx^%d\t" % (self.coef[n], n), end = " "); # 사용자가 입력한 다항식의 계수를 출력
            if(n == 0) : # 0차수에 해당하면 반복문을 종료
                break;
            print("+", end = " ") # 한 차수가 끝날때마다 + 기호를 출력
        print("\n")

    def add(self, b) : # 다항식의 덧셈을 진행하는 메소드
        z = Polynomial() # 덧셈의 결과를 저장할 다항식 클래스 객체 z
        for n in range(len(self.coef)) : # 객체의 길이에 따라 반복문을 진행
            z.coef.append(self.coef[n]+b.coef[n]) # 비어있는 다항식 객체 z에 두 다항식의 더한 값을 저장
        return z
        
    def eval(self,x) : # 다항식에 일정한 값을 넣어 결과값을 도출하는 메소드
        length = len(self.coef) # len()을 이용하여 객체의 길이를 변수 length에 저장
        import math # 제곱 연산을 진행하기 위하여 math 클래스를 사용함
        for n in range(length) :  # 객체의 길이만큼 반복문을 진행 
            self.coef[n] = self.coef[n] * pow(x,n) # 각 차수에 맞게 값을 넣어 그 결과를 다시 리스트에 저장
        for n in range(length) : # 객체의 길이만큼 반복문을 진행
            global answer # 정답을 나타내느 전역변수 answer 사용
            answer += self.coef[n] # 리스트에 계산되어 있는 값을 다 더하여 answer의 값을 정함
        return answer # 정답 answer 반환 

    def neg(self,x) : # 다항식의 뺄셈을 진행하기 위한 메소드 
        length = len(self.coef) # len()을 이용하여 객체의 길이를 변수 length에 저장
        for n in range(length) : # 객체의 길이만큼 반복문을 진행
            self.coef[n] = -(self.coef[n]) # 리스트의 각 요소에 음수 처리를 함
        return self # 객체를 반환 

    def read(self) : # 사용자로부터 다항식의 차수의 계수를 입력받는 메소드
        deg = int(input("다항식의 최고 차수를 입력하시오: ")) # 사용자로부터 최고차수를 입력받고 몇차항 다항식인지에 해당하는 deg를 저장
        for n in range(deg+1) : # deg의 길이보다 1크게 반복문을 실행
            coef = float(input("\tx^%d의 계수 : " % (deg-n))) # 사용자로부터 각 차수에 해당하는 계수를 입력받음
            self.coef.append(coef) # 리스트 객체에 계수를 추가
        self.coef.reverse() # 리스트 객체의 각 인덱스안에 저장되어있는값을 반대로 전환함

#=======================================================================

a = Polynomial() # 리스트 객체 a 생성
b = Polynomial() # 리스트 객체 b 생성
a.read() # 사용자로부터 객체 a의 다항식의 차수를 입력받음
b.read() # 사용자로부터 객체 b의 다항식의 차수를 입력받음
c = a.add(b) # 다항식의 덧셈 연산 진행 
a.display("A(x) = ") # 객체 a의 다항식 출력
b.display("B(x) = ") # 객체 b의 다항식 출력
c.display("C(x) = ") # 객체 c의 다항식 출력
print("C(2) = ", c.eval(2)) # 객체 c에 2의 값을 넣어 결과값 도출