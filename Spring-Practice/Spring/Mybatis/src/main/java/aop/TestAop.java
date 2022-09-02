package aop;

import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.springframework.stereotype.Component;

@Aspect
@Component
public class TestAop {

    @Around("execution( * controller.TestController..*(..))")
    public Object LogInLog(ProceedingJoinPoint proceedingJoinPoint) {
        Object result = null;
        try {
            long beforeTime = System.currentTimeMillis();
            System.out.println("aop start -around !! ");
            result = proceedingJoinPoint.proceed();
            System.out.println("aop end - around !! ");
            long afterTime = System.currentTimeMillis();
            long secDiffTime = (afterTime - beforeTime);
            System.out.println("시간차이: " +secDiffTime);
        } catch (Throwable throwable) {
            System.out.println("exception!! ");
        }
        return result;
    }

}
