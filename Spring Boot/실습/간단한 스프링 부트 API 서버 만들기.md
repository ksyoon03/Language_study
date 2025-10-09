# 간단한 스프링 부트 API 서버 만들기

## 1. 스프링 부트 프로젝트 생성

- [Sping Initializer](https://start.spring.io/) ← 링크 접속
    - 접속 후 설정

![image.png](image.png)

![image.png](image%201.png)

## 2. 파일 살펴보기

- `src/main/java/com/example/myfirstapp` 폴더 안의 `MyFirstAppApplication.java` 파일 :
    - **프로젝트의 심장부 역할**
    
    ![image.png](image%202.png)
    
    ```java
    package com.example.my_first_app;
    
    import org.springframework.boot.SpringApplication;
    import org.springframework.boot.autoconfigure.SpringBootApplication;
    
    @SpringBootApplication
    public class MyFirstAppApplication {
    
    	public static void main(String[] args) {
    		SpringApplication.run(MyFirstAppApplication.class, args);
    	}
    }
    ```
    

## 3. API 코드 작성하기

1. `src\main\java\com\example\my_first_app` 폴더 우클릭 후 `새로 만들기` → `Java Class` 선택
2. 클래스 이름으로 `HelloController`입력 후 엔터
3. 생성된 `HelloController.java`  파일에 코드 입력

```java
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloController {

    @GetMapping("/hello")
    public String sayHello() {
        return "Hello, 형님! 스프링 부트의 세계에 오신 것을 환영합니다!";
    }
}
```

### 코드 해설

- `@RestController` : 해당 클래스가 **웹 요청**을 받는 **특별 클래스(컨트롤러)**라고 스프링에게 알려주는 꼬리표
- `@GetMapping("/hello")` : 서버의 `/hello` 라는 주소로 GET 요청을 보내면, `sayHello()` 메소드를 실행시켜달라는 요청을 보냄

## 4. 서버 실행하고 결과 확인

1. 왼쪽 탐색기에서 `MyFirstAppApplication.java` 파일을 찾아 더블 클릭
2. `main` 메소드 옆에 있는 실행 버튼을 누르고 `Run 'MyFirstAppApplication.main()'`을 클릭
3. 콘솔 창에 아래 메시지가 보이면 서버가 성공적으로 켜졌다는 뜻
    - `Tomcat started on port(s): 8080`
4. 웹 브라우저의 주소창에 아래 주소를 입력
    - `http://localhost:8080/hello`
- **실행 화면**
    
    ![image.png](image%203.png)
    

## 결론

- 직접 new HelloController()를 하지 않아도, 스프링이 알아서 객체를 생성 및 관리 해준다.
    
    → **DI(의존성 주입)**와 **IoC(제어의 역전)**의 핵심
