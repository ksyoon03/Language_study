# 할 일 목록 API 만들기

## 문제

당신은 개인 프로젝트로 사용할 간단한 할 일 목록 API 서버를 만들게 되었습니다. 할 일들을 관리하고, 상태에 따라 조회하는 기능을 만들어야 합니다.

---

## **요구사항:**

1. **`Todo` 클래스 만들기**
    - 할 일(Todo)은 다음 정보를 가집니다.
        - `id` (고유번호) - `long` 타입
        - `task` (할 일 내용) - `String` 타입
        - `isDone` (완료 여부) - `boolean` 타입 (true 또는 false)
2. **`TodoController` 클래스 만들기 (`@RestController`)**
    - 데이터베이스 대신, 할 일 데이터를 저장할 `HashMap`을 만드세요.
        - **Key**: 할 일의 `id` (`long`)
        - **Value**: `Todo` 객체
    - `HashMap`에 미리 3개 이상의 할 일 데이터를 넣어두세요. (완료된 일과 미완료된 일을 섞어서 만들어 보세요.)
3. **API 엔드포인트(Endpoint) 3개 만들기 (`@GetMapping`)**
    - **API 1: 특정 ID로 할 일 조회하기**
        - **URL**: `/todos/{id}`
        - **기능**: URL 경로의 `id` 값을 **`@PathVariable`*로 받아오세요.
        - `HashMap`에서 해당 `id`의 할 일을 찾아, 그 내용과 완료 상태를 문자열로 반환하세요.
            - (예: `"Task: [스프링 부트 공부하기], Status: [Incomplete]"`)
            - (예: `"Task: [저녁 장보기], Status: [Complete]"`)
        - 해당 `id`의 할 일이 없으면, `"해당 ID의 할 일을 찾을 수 없습니다."` 라고 반환하세요.
    - **API 2: 완료 상태로 할 일 목록 필터링하기**
        - **URL**: `/todos/search`
        - **기능**: `?done=true` 또는 `?done=false` 형식의 쿼리 파라미터를 **`@RequestParam`*으로 받아오세요.
        - `HashMap`의 모든 `Todo` 객체 중, 요청된 `done` 상태와 일치하는 할 일들을 모두 찾으세요.
        - 찾은 모든 할 일의 `task` 내용을 쉼표(`,`)로 이어서 하나의 긴 문자열로 만들어 반환하세요.
            - (예: `"스프링 부트 공부하기, 프로젝트 구조 생각하기"`)
        - 일치하는 할 일이 하나도 없으면, `"해당 상태의 할 일이 없습니다."` 라고 반환하세요.

---

## 실행 결과

(아래 데이터는 예시이며, 만든 데이터에 따라 결과는 달라질 수 있습니다.)

- **`http://localhost:8080/todos/1`** 접속 시
    
    > Task: [스프링 부트 공부하기], Status: [Incomplete]
    > 
- **`http://localhost:8080/todos/3`** 접속 시
    
    > Task: [저녁 장보기], Status: [Complete]
    > 
- **`http://localhost:8080/todos/search?done=false`** 접속 시
    
    > 스프링 부트 공부하기,프로젝트 구조 생각하기
    > 
- **`http://localhost:8080/todos/search?done=true`** 접속 시
    
    > 저녁 장보기
    > 

---

## 코드

```java
package com.example.my_first_app;

public class Todo {
    long id;
    String task;
    boolean isDone;

    public String getInfo(){
        String status;
        if(isDone){
            status="Complete";
        }
        else{
            status="Incomplete";
        }
        return "Task: [" + task + "], Status: [" +  status + "]";
    }
}

```

```java
package com.example.my_first_app;

import java.util.HashMap;
import java.util.ArrayList;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class TodoController {

    HashMap<Long, Todo> todoMap = new HashMap<>();

    public TodoController() {
        Todo todo1 = new Todo();
        todo1.id = 1L;
        todo1.task = "스프링 부트 공부하기";
        todo1.isDone = false;

        Todo todo2 = new Todo();
        todo2.id = 2L;
        todo2.task = "저녁 장보기";
        todo2.isDone = true;

        Todo todo3 = new Todo();
        todo3.id = 3L;
        todo3.task = "프로젝트 구조 생각하기";
        todo3.isDone = false;

        todoMap.put(todo1.id, todo1);
        todoMap.put(todo2.id, todo2);
        todoMap.put(todo3.id, todo3);
    }

    @GetMapping("/todos/{id}")
    public Object foundID(@PathVariable("id") long id) {
        Todo tmp = todoMap.get(id);
        if (tmp != null) {
            return tmp.getInfo();
        } else {
            return "해당 ID의 할 일을 찾을 수 없습니다.";
        }
    }

    @GetMapping("/todos/search")
    public Object foundStatus(@RequestParam(value = "done", defaultValue = "false") boolean done) {
        ArrayList<String> output = new ArrayList<>();
        for (Todo td : todoMap.values()) {
            if (td.isDone == done) {
                output.add(td.task);
            }
        }
        if (output.isEmpty()) {
            return "해당 상태의 할 일이 없습니다.";
        } else {
            return String.join(", ",output);
        }
    }
}

```

### 팁

- **반복문 활용**
    
    ```java
    if (output.isEmpty()){
            return"해당 상태의 할 일이 없습니다.";
        }
        else{
            String tmp = "";
    
            for (int i = 0; i < output.size() - 1; i++) {
    
                tmp = output.get(i) + ", ";
            }
            tmp += output.getLast();
            return tmp;
        }
    ```
    
    `String.join()`을 사용하면 위와 같이 문자열 사이에 콤마를 넣기 위해 복잡한 반복문을 사용할 필요가 없다.
    
- **`String.join()` 활용**
    
    ```java
    if (output.isEmpty()) {
                return "해당 상태의 할 일이 없습니다.";
            } else {
                return String.join(", ",output);
            }
    ```
    
    위와 같이 `String.join(”, “, output)`을 활용하면 `output`의 각 문자열 사이에 콤마를 자동으로 넣어준다.