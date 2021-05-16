package aop;

import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.springframework.stereotype.Component;

@Aspect
@Component
public class TestAop {

    @Around("execution( * controller.TestController..*(..))") // login 전, 후 실행 around
    public Object LogInLog(ProceedingJoinPoint proceedingJoinPoint) {
        Object result = null;
        try {
            System.out.println("aop start -around !! ");
            result = proceedingJoinPoint.proceed(); // do target
            System.out.println("aop end - around !! ");
        } catch (Throwable throwable) { // 에러 발생 실행
            System.out.println("exception!! ");
        }
        return result;
    }

}
