//package P17;
//import org.aspectj.lang.annotation.*;
//import org.aspectj.lang.JoinPoint;
//import org.aspectj.lang.Signature;
//
//@Aspect
//public class LoggingAspect {
//
//    @Before("execution(* com.example.service.*.*(..))")
//    public void logBeforeMethodExecution(JoinPoint joinPoint) {
//        Signature signature = joinPoint.getSignature();
//        System.out.println("Before executing " + signature.toShortString());
//    }
//
//    @AfterReturning(pointcut = "execution(* com.example.service.*.*(..))", returning = "result")
//    public void logAfterMethodExecution(JoinPoint joinPoint, Object result) {
//        Signature signature = joinPoint.getSignature();
//        System.out.println("After executing " + signature.toShortString() + ". Result: " + result);
//    }
//
//    @AfterThrowing(pointcut = "execution(* com.example.service.*.*(..))", throwing = "exception")
//    public void logAfterException(JoinPoint joinPoint, Exception exception) {
//        Signature signature = joinPoint.getSignature();
//        System.out.println("Exception after executing " + signature.toShortString() + ". Exception: " + exception.getMessage());
//    }
//}
//
//
//public class TestAOPPrincipals {
//}
