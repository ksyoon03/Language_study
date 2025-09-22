# utility 헤더 파일

## 1. pair와 make_pair()

- pair : 서로 다른 타입의 두 값을 하나의 객체로 묶어주는 클래스 템플릿이다.
    
    first와 second라는 멤버 변수로 두 값에 접근할 수 있다.
    

```cpp
pair <int, string> p1(21, "나이");
cout << p1.first << " " << p2.second << endl;
// 21 나이
```

- make_pair( ) : pair 객체를 생성할 때 사용하며, 템플릿 인자를 명시하지 않아도 된다.

```cpp
auto p2 = make_pair(21, "나이");
cout << p2.first << " " << p2.second << endl;
// 21 나이
```

## 2. swap()

- swap( ) : 두 변수나 객체의 값을 맞바꾸는 함수이다.

```cpp
string s1 = "Kim";
string s2 = "Park";
swap(s1, s2);
// s1 = Park, s2 = Kim
```