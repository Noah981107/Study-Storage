# **5주차 - 6장.AOP**

## **목차**
[1. 효율적인 테스트 방법](#1.-효율적인-테스트-방법)<br>
[2. 테스트 대상 오브젝트 고립](#2.-테스트-대상-오브젝트-고립)<br>
[3. 단위 테스트](#3.-단위-테스트)<br>
[4. 통합 테스트](#4.-통합-테스트)<br>
[5. 단위 테스트 or 통합 테스트 선택 가이드 라인](#5.-단위-테스트-or-통합-테스트-선택-가이드-라인)<br>
[6. 목 프레임워크](#6.-목-프레임워크)<br>
[7. 프록시](#7.-프록시)<br>
[8. 데코레이터 패턴](#8.-데코레이터-패턴)<br>
[9. 프록시 패턴](#9.-프록시-패턴)<br>
[10. 다이내믹 프록시](#10.-다이내믹-프록시)<br>
[11. 팩토리 빈](#11.-팩토리-빈)<br>
<br>


## **1. 효율적인 테스트 방법**
 - 할 수 있는한 가장 작은 단위로 쪼개서 테스트
   - 테스트 실패 시 : 원인 찾기 쉬움
   - 불가능한 경우 : 다른 오브젝트와 환경에 의존하고 있는 경우
---
<br>

## **2. 테스트 대상 오브젝트 고립**
 - UserService 에서는 UserDao, TransactionManager, MailSender에 의존관계를 가짐
 - 의존관계가 있기 때문에 UserService에 대한 테스트는 UserDao, TransactionManager, MailSender가 함께 테스트 됨
 - 목 오브젝트를 이용하여 테스트에 대한 검증 실시
 - 테스트 대상이 외부 환경(의존 관계)에 영향이 없도록 하는 방법
   1. 테스트를 고립
   2. 테스트 대역을 사용 
 - 테스트 대상 오브젝트 고립을 통한 이점 : 테스트 수행 시간이 빨라짐
   - 직접적으로 필요하지 않은 의존 오브젝트와 서비스를 모두 제거
   - 반복적인 테스트를 위하여 테스트 수행시간 단축은 필수
---
<br>

## **3. 단위 테스트**
 - 테스트 대역을 이용해 의존 오브젝트나 외부 리소스를 사용하지 않도록 고립시켜서 하는 테스트
---
<br>

## **4. 통합 테스트**
 - 두 개 이상의 성격이나 계층이 다른 오브젝트를 연동하거나 외부 DB, 파일 또는 서비스 등의 리소스가 참여하는 테스트
---
<br>

## **5. 단위 테스트 or 통합 테스트 선택 가이드 라인**
 - 항상 단위 테스트를 먼저 고려
 - 스텁이나 목 오브젝트 등의 테스트 대역을 이용하여 테스트를 만들기
 - 외부 리소스를 사용해야만 가능한 테스트는 통합테스트로 사용
 - 여러 개의 단위가 의존관계를 가지고 동작할 경우 통합 테스트 필요
 - 단위 테스트를 만들기가 너무 복잡하면 통합 테스트
 - 스프링 테스트 컨텍스트 프레임워크를 이용하는 테스트는 통합 테스트
 - **통합 테스트 라도 조금씩은 단위 테스트로 검증하기**
---
<br>

## **6. 목 프레임워크**
 1. 의존 라이브러리 추가
    ```xml
    <dependency>
        <groupId>org.mockito</groupId>
        <artifactId>mockito-all</artifactId>
        <version>1.9.5</version>
    </dependency>
    ```
 2. 스태틱 메소드 호출로 목 클래스를 생성
    ```java
    UserDao mockUserDao = mock(UserDao.class);
    ```
 3. 스텁 기능 추가 : mockUserDao.getAll()이 호출 되었을 때 users를 리턴
     ```java
    when(mockUserDao.getAll()).thenReturn(this.users);
    ```
 4. 메소드 호출 횟수 확인 방법 : update 메소드가 두 번 호출됐는지 확인
    ```java
    verify(mockUserDao, times(2)).update(any(User.class));
    ```
 5. Mockito 목 오브젝트 사용법
    1. 인터페이스를 이용해 목 오브젝트 생성
    2. 리턴할 값이 있으면 지정
    3. 테스트 대상 오브젝트에 의존성 주입
    4. 검증  
---
<br>

## **7. 프록시**
 - 부가기능 외에 나머지 모든 기능은 핵심기능을 가진 클래스에 위임해야함
 - 핵심 기능은 부가기능을 가진 클래스를 모름
 - 부가기능이 클라이언트가 사용하려고 하는 핵심 기능처럼 위장애서 클러이언트의 요청을 받아줌
 - 사용 목적에 따른 구분
   1. 클라이언트가 타깃에 접근하는 방법을 제어
   2. 타깃에 부가적인 기능을 부여 
---
<br>

## **8. 데코레이터 패턴**
 - 타깃에 부가적인 기능을 런타임 시에 다이내믹하게 부여해주는 패턴
 - 같은 인터페이스를 구현한 타겟과 여러 개의 프록시를 사용 가능
 - 데코레이터의 다음 위임 대상은 인터페이스로 선언하고 생성자나 수정자 메소드를 통해 위임 대상을 외부에서 런타임 시에 주입받을 수 있도록 해야함
---
<br>

## **9. 프록시 패턴**
 - 타깃에 대한 접근 방법을 제어하려는 목적을 가진 패턴
 - 타깃의 기능을 확정하거나 추가하지 않고 클라이언트가 타깃에 접근하는 방식을 변경
---
<br>

## **10. 다이내믹 프록시**
 - 리플랙션 기능을 이용해서 사용 (리플랙션 : 자바의 코드 자체를 추상화해서 접근하는 방법)
 - 프록시 팩토리에 의해 런타임 시 다이내믹하게 만들어지는 오브젝트
 - 다이내믹 프록시 오브젝트는 타깃의 인터페이스와 같은 타입으로 만들어짐
 - 부가기능은 프록시 오브젝트와 독립적으로 InvocationHandler를 구현한 오브젝트에 담아서 사용
    ```java
    class MyProxyHandler implements InvocationHandler {
    private Object target;

    public MyProxyHandler(Object target) {
        this.target = target;
    }

    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        System.out.println("메소드 호출 전");
        int result = (int) method.invoke(target, args);
        System.out.println("메소드 호출 후");
        return result;
        }
    }
    ```
---
<br>

## **11. 팩토리 빈**
 - 스프링을 대신해서 오브젝트의 생성로직을 담당하도록 만들어진 특별한 빈
 - 스프링의 FactoryBean이라는 인터페이스를 구현하여 오브젝트 생성
     ```java
    package org.springframework.beans.factory;

    public interface FactoryBean<T> {
        T getObject() throws Exception; // 빈 오브젝트를 생성해서 돌려준다.
        Class<? extends T> getOBjectType(); // 생성되는 오브젝트의 타입을 알려준다.
        boolean isSingleton(); // getObject()가 돌려주는 오브젝트가 항상 같은 싱글톤 오브젝트인지 알려준다.
    }
    ```
---
<br>