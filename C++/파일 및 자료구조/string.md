# string 헤더 파일

## 1. 문자열 수정 및 추가

- append( ) : 다른 문자열이나 문자를 현재 문자열 뒤에 덧붙인다.

```cpp
s.append(” World”)
```

- insert( ) : 특정 위치에 문자열을 삽입한다.

```cpp
s.insert(6, “World”)
```

- erase( ) : 특정 위치부터 지정된 길이만큼의 문자를 삭제한다.

```cpp
s.erase(5, 6)
// 인덱스 5부터 6개의 문자를 지운다.
```

- replace( ) : 특정 위치부터 지정된 길이만큼의 문자열을 다른 문자열로 바꾼다.

```cpp
s.replace(6, 5, "World")
// 인덱스 6부터 5개의 문자를 World로 바꾼다.
```

## 2. 정보 확인 및 검색

- length( ) 또는 size( ) : 문자열의 길이를 반환한다.
- empty( ) : 문자열이 비어있는지 확인한다.
- find( ) : 문자열에서 특정 문자가 처음 나타나는 인덱스를 찾는다.
- substr( ) : 문자열의 특정 부분을 잘라내어 새로운 문자열로 반환한다.

```cpp
string k = s.substr(6, 5)
// 인덱스 6부터 5개의 문자를 잘라낸 후 k에 반환한다.
```

## 3. 요소 접근

- [ ] 연산자 : 배열처럼 인덱스를 이용해 문자에 접근한다.
- at( ) : [ ]와 마찬가지로 인덱스로 문자에 접근하지만, 범위를 벗어나면 예외를 발생시켜 더 안전하다.

## 4. 타입 변환

- to_string( ) : int, double 등의 숫자를 string으로 변환한다.

```cpp
to_string(123) // "123"
```

- stoi( ), stol( ), stoll : string을 int, long, long long으로 변환한다.
- stod( ), stold : string을 double, long double로 변환한다.
