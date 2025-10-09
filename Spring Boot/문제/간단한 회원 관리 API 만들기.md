# 간단한 회원 관리 API 만들기

## 문제

당신은 회사의 백엔드 팀에 막 합류한 신입 개발자입니다. 당신에게 주어진 첫 번째 임무는 간단한 회원 관리 API를 만드는 것입니다.

---

## **요구사항:**

1. **`User` 클래스 만들기**
    - 회원은 다음 정보를 가집니다.
        - `id` (회원 고유번호) - `long` 타입
        - `username` (이름) - `String` 타입
        - `email` (이메일) - `String` 타입
2. **`UserController` 클래스 만들기 (`@RestController`)**
    - 이 클래스 안에 `main` 함수가 아닌, API 요청을 처리하는 메소드들을 만듭니다.
    - 데이터베이스 대신, 회원 데이터를 저장할 `HashMap`을 하나 만드세요.
        - **Key**: 회원의 `id` (`long`)
        - **Value**: `User` 객체
    - `HashMap`에 미리 3명 이상의 회원 데이터를 넣어두세요.
3. **API 엔드포인트(Endpoint) 2개 만들기 (`@GetMapping`)**
    - **API 1: 특정 ID로 회원 조회하기**
        - **URL**: `/users/{id}`
        - **기능**: URL 경로에 포함된 `id` 값을 **`@PathVariable`*을 사용해서 받아오세요.
        - `HashMap`에서 해당 `id`를 가진 회원을 찾아서, 그 회원의 `username`과 `email`을 문자열로 조합하여 반환하세요. (예: `"Username: 홍길동, Email: hong@example.com"`)
        - 만약 해당 `id`의 회원이 없으면, `"해당 ID의 회원을 찾을 수 없습니다."` 라는 메시지를 반환하세요.
    - **API 2: 특정 이름으로 회원 검색하기**
        - **URL**: `/users/search`
        - **기능**: URL의 쿼리 파라미터 `?username=이름` 형식으로 들어온 값을 **`@RequestParam`*을 사용해서 받아오세요.
        - `HashMap`의 모든 `User` 객체를 하나씩 확인(반복문)하여, 파라미터로 받은 `username`과 일치하는 회원을 찾으세요.
        - 찾았다면, 그 회원의 `id`와 `email`을 문자열로 조합하여 반환하세요. (예: `"ID: 1, Email: hong@example.com"`)
        - 만약 일치하는 이름의 회원이 없으면, `"해당 이름의 회원을 찾을 수 없습니다."` 라는 메시지를 반환하세요.

---

## 실행 결과

서버를 실행하고 웹 브라우저에서 아래 주소로 접속했을 때, 다음과 같은 결과가 나오면 성공입니다! (회원 데이터는 만드신 것에 따라 다를 수 있습니다.)

- **`http://localhost:8080/users/2`** 접속 시
    
    > Username: 김철수, Email: kim@example.com
    > 
- **`http://localhost:8080/users/99`** (없는 ID) 접속 시
    
    > 해당 ID의 회원을 찾을 수 없습니다.
    > 
- **`http://localhost:8080/users/search?username=이영희`** 접속 시
    
    > ID: 3, Email: lee@example.com
    > 
- **`http://localhost:8080/users/search?username=스티브`** (없는 이름) 접속 시
    
    > 해당 이름의 회원을 찾을 수 없습니다.
    > 

---

## 코드

```java
package com.example.my_first_app;

public class User {
        long id;
        String username;
        String email;

        public String getUserInfo(){
            return "Username: " + username + ", Email: " + email;
        }
}
```

```java
package com.example.my_first_app;

import java.util.HashMap;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;

@RestController
public class UserController {

    HashMap <Long, User> userMap = new HashMap<>();

    public UserController(){
        setUserInfo();
    }

    public void setUserInfo() {
        User user1 = new User();
        user1.id = 1L;
        user1.username = "김상윤";
        user1.email = "kim@gmail.com";

        User user2 = new User();
        user2.id = 2L;
        user2.username="윤지호";
        user2.email="yun@gmail.com";

        User user3 = new User();
        user3.id = 3L;
        user3.username="한형민";
        user3.email="han@gmail.com";

        userMap.put(user1.id, user1);
        userMap.put(user2.id, user2);
        userMap.put(user3.id, user3);
    }

    @GetMapping("/users/{id}")
        public Object foundID(@PathVariable("id") long id){
            User foundUser = userMap.get(id);
            if(foundUser!=null){
                return foundUser.getUserInfo();
            }
            else{
                return "해당 ID의 회원을 찾을 수 없습니다.";
            }
        }

    @GetMapping("/users/search")
    public Object foundName(@RequestParam(value="username") String username){
        for(User u : userMap.values()){
            if(u.username.equals(username)){
                return u.getUserInfo();
            }
        }
        return "해당 이름의 회원을 찾을 수 없습니다.";
    }
}

```