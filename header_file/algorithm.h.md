# algorithm 헤더 파일

## 1. 정렬 및 재배열

- sort( ) : 지정된 범위의 요소를 오름차순으로 정렬한다. 내림차순으로 정렬하는 것도 가능하다.

```cpp
vector <int> v = {3, 2, 4, 1}
sort(v.begin(), v.end())    // {1, 2, 3, 4}
sort(v.rbegin(), v.rend())  // {4, 3, 2, 1}
```

- stable_sort () : sort와 동일하지만 더 안정적인 정렬이 가능하다. 단, sort에 비해 속도가 느리다.

```cpp
vector <int> v = {3, 2, 4, 1}
stable_sort(v.begin(), v.end())    // {1, 2, 3, 4}
stable_sort(v.rbegin(), v.rend())  // {4, 3, 2, 1}
```

| sort() | 안정성이 별로 중요하지 않을 때 사용한다.
추가 메모리를 사용하지 않아 효율적이다. |
| --- | --- |
| stable_sort() | 안정성이 반드시 필요할 때 사용한다.
pair 클래스와 같이 쓰면 유용하다. |
- reverse( ) : 지정된 범위의 요소 순서를 뒤집는다.

```cpp
string v = "Hello";
reverse(v.begin(), v.end());  // "olleH"
```

## 2. 탐색 및 검색

- find( ) : 지정된 범위에서 특정 값을 가진 첫 번째 요소를 찾는다. 해당 요소를 찾으면 그 위치의 반복자(iterator)를 반환하고, 없으면 end() 반복자를 반환한다.

```cpp
vector <int> = {1, 2, 3, 4};
auto it = find(v.begin(), v.end(), 3);
// it은 세 번째 요소(3)을 가리킨다.
```

- count( ) : 지정된 범위에서 특정 값과 일치하는 요소의 개수를 센다.

```cpp
vector <int> v = {1, 2, 2, 3, 4};
int num = count(v.begin(), v.end(), 2); // num = 2
```

- distance(a, b) : a에서 b까지의 거리 차이를 계산함

```cpp
vector <int> v = {1, 2, 3, 4, 5};
int num = distance(v.begin(), v.begin() + 2) // num = 2
```

## 3. 값 비교 및 조건 확인

- min( ) / max( ) : 두 개의 값 중에서 더 작은/큰 값을 반환한다.

```cpp
int min_num = min(10, 20); // min_num = 10
int max_num = max(30, 40); // max_num = 40
```

- min / max_element( ) : 지정된 범위에서 가장 작은/큰 요소를 가리키는 반복자를 반환한다.

```cpp
vector <int> v = {1, 2, 3, 4};
auto min_it = min_element(v.begin(), v.end()); // min_it은 1을 가리킨다
auto max_it = max_element(v.begin(), v.end()); // max_it은 4를 가리킨다.
```

- all_of( ) / any_of( ) / none_of( ) : 람다 함수를 사용하여 범위 내 모든 요소가(all_of),
    
    한 요소라도(any_of), 또는 어떤 요소도 만족하지 않는지(none_of) 확인하여 bool 값을 반환한다.
    

```cpp
vector <int> v = {2, 4, 6, 8);
bool allEven = all_of(v.begin(), v.end(), [](int i){ return i % 2 == 0;});
// allEven = True

bool anyEven = any_of(v.begin(), v.end(), [](int i){ return i % 2 == 0;});
// anyEven = True

bool noneEven = none_of(v.begin(), v.end(), [](int i){ return i % 2 == 0;});
// noneEven = False
```

## 4. 유용한 기타 함수

- unique( ) : 정렬된 범위에서 연속적으로 중복되는 요소를 제거한다. 이 함수는 실제로 컨테이너의 크기를 줄이지 않고, 중복되지 않는 요소들을 범위의 앞쪽으로 이동시킨 후 새로운 반복자를 반환한다.

```cpp
vector <int> v = {1, 2, 2, 3, 3, 3, 4};
auto new_end = unique(v.begin(), v.end());
// v는 {1, 2, 3, 4, 2, 3, 3}이 되고, new_end는 4 다음을 가리킨다.
v.erase(new_end, v.end())
// 이렇게 해야 실제로 크기가 줄어든다.
```

- swap( ) : 두 변수나 객체의 값을 맞바꾼다.

```cpp
int a = 10, b = 20;
swap(a, b);
// a는 20, b는 10
```