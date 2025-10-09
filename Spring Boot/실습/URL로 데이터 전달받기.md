# URL로 데이터 전달받기

## 사용자가 URL을 통해 데이터를 보내는 방법

### **가장 흔한 두 가지 방법**

- **쿼리 파라미터 (Query Parameter)** : `.../hello?name=Steve` 처럼 **URL 뒤에 `?`를 붙여** 보내는 방식
- **경로 변수 (Path Variable)** : `…/hello/Steve` 처럼 **URL 경로의 일부**로 데이터를 보내는 방식

---

## `@RequestParam`으로 쿼리 파라미터 받기

1. `HelloController.java` 파일을 아래와 같이 수정한다.

```java
package com.example.my_first_app;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam; // 추가된 부분
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloController {

    @GetMapping("/hello") // 쿼리 파라미터 방식
    public String sayHello(@RequestParam(value = "name", defaultValue = "World") String name) {
        return "Hello, " + name + "!";
    }
}
```

- **코드 해설:**
    - `@RequestParam(…)` : URL에 담겨온 쿼리 파라미터를 받아서 뒤에 오는 변수에 넣어주는 메소드
        - `value = “name”` : `?name=값` 형태로 들어오는 파라미터를 찾는다.
        - `defaultValue = “World”` : 만약 `name` 파라미터가 URL에 없으면, 기본값으로 “World”를 사용한다.
        - `String name` : `name` 파라미터의 값을 이 변수에 저장한다.

- **테스트 방법:**
    1. 서버를 재시작한다.
    2. 웹 브라우저에서 아래 두 주소를 각각 입력해본다.
        - `http://localhost:8080/hello`
            - `name` 파라미터가 없으므로 `defaultValue` 가 적용된다.
            - **결과**: `Hello, World!`
                
                ![image.png](image.png)
                
        - `http://localhost:8080/hello?name=Steve`
            - `name` 파라미터 값으로 “Steve”가 전달된다.
            - **결과**: `Hello, Steve!`
                
                ![image.png](image%201.png)
                

---

## `@PathVariable`로 경로 변수 받기

1. `HelloController.java` 파일을 아래와 같이 수정한다.

```java
package com.example.my_first_app;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.PathVariable; // 추가된 부분
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloController {

    @GetMapping("/hello") // 쿼리 파라미터 방식
    public String sayHello(@RequestParam(value = "name", defaultValue = "World") String name) {
        return "Hello, " + name + "!";
    }

    @GetMapping("/hello/{name}") // 경로 변수 방식
    public String sayHelloPath(@PathVariable("name") String name) {
        return "Hello from path, " + name + "!";
    }
}
```

- **코드 해설:**
    - `@GetMapping("/hello/{name}")` : URL 경로의 `{name}` 부분이 변수로 사용될 것이라고 알려준다.
    - `@PathVariable("name")` : `{name}` 자리에 들어온 값을 뒤에 오는 `String name` 변수에 넣어준다.
    
    <aside>
    <img src="https://www.notion.so/icons/info-alternate_red.svg" alt="https://www.notion.so/icons/info-alternate_red.svg" width="40px" />
    
    - **`{name}` 처럼 중괄호 `{}` 를 사용하는 이유**
        
        해당 자리가 고정된 글자가 아니라 **변수가 들어올 자리**라는 것을 스프링에게 알려주는 **약속(문법)**이기 때문이다.
        
        즉, `{name}`은 ‘name’이라는 이름의 **자리 표시자 (placeholder)** 역할을 한다.
        
        ```java
        // 1. URL 경로에서 {name}이라는 이름의 "빈칸"을 만든다.
        @GetMapping("/hello/{name}")
        public String sayHelloPath(
                // 2. 위에서 만든 "{name}" 빈칸에 채워진 값을
                //    이 "name" 변수에 넣어달라고 요청한다.
                @PathVariable("name") String name
        ) {
            return "Hello from path, " + name + "!";
        }
        ```
        
    </aside>
    

- **테스트 방법:**
    1. 서버를 재시작한다.
    2. 웹 브라우저에서 아래 주소를 입력한다.
        - `http://localhost:8080/hello/Steve`
            - URL 경로의 “Steve”라는 값이 `name` 변수로 전달된다.
            - **결과**: `Hello from path, Steve!`
                
                ![image.png](image%202.png)