# BFS와 DFS

<aside>

### 개념

- 그래프나 트리에서 노드를 탐색하는데 사용되는 대표적인 알고리즘
</aside>

<aside>

### BFS (너비 우선 탐색)

- 시작 노드에서 **가까운 노드부터 차례대로** 탐색하는 방식
    - 시작점에서 한 단계씩 주변 노드를 탐색함
        - 예) 미로 찾기 게임에서 출구까지 가는 가장 짧은 길을 찾을 때 사용됨
- **탐색 원리 :** 큐 자료 구조를 사용하여 먼저 방문한 노드를 먼저 처리
- **특징 :**
    - 최단 경로를 찾는데 유용함
    - 재귀적으로 동작하지 않으며, 반복문으로 구현하는 것이 일반적임
    - 탐색 범위가 길어지기 때문에 메모리 사용량이 많아질 수 있음
- **예시:**

![bfs.gif](bfs.gif)

- **예제 코드**

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> example[10];
// 10개의 노드를 가질 수 있는 인접 리스트
bool check[10];
// 방문한 노드를 체크하는 배열 (무한 루프 방지)

void bfs(int x) {   // x는 탐색을 시작할 노드의 번호
    queue <int> q;  // BFS 탐색을 위한 큐
    q.push(x);  // 시작 노드 x를 큐에 넣음
    check[x] = true;    // 시작 노드 x를 방문 했다고 표시
    cout << x << " ";

    while (!q.empty()) {
    // 큐가 비어있지 않다면 반복
        int y = q.front();
        // 현재 탐색 중인 노드 y를 큐에서 꺼냄
        q.pop();
        // 꺼낸 노드는 큐에서 제거

        for (int i = 0; i < example[y].size(); i++) {
        // 현재 노드 y와 연결된 모든 노드들을 순회
            int z = example[y][i];
            // 다음으로 이동할 연결 노드 z
            if (!check[z]) {
            // 만약 다음 노드 z를 아직 방문하지 않았다면
                check[z] = true;
                // 다음 노드 z를 방문했다고 표시
                q.push(z);
                // 다음 노드 z를 큐에 추가
                cout << z << " ";
            }
        }
    }
}

int main() {
    // 인접 리스트를 활용하여 컴퓨터들의 연결 상태를 설정
    // 1번 노드 -> 2번 노드 = 2번 노드 -> 1번 노드
    // (양방향 연결)
    example[1].push_back(2);
    example[2].push_back(1);
    example[1].push_back(3);
    example[3].push_back(1);
    example[2].push_back(4);
    example[4].push_back(2);
    example[3].push_back(4);
    example[4].push_back(3);

    cout << "BFS 탐색 순서: ";
    bfs(1);    // 1번 노드에서 BFS 시작
    cout << endl;
}
```

</aside>

<aside>

### DFS (깊이 우선 탐색)

- 시작 노드에서 **한 방향으로 최대한 깊숙이** 들어가 탐색하는 방식
    - 막다른 길에 다다르면 다시 돌아와서 다른 길로 탐색을 시작함
        - 예) 미로  찾기 게임에서 한쪽 벽을 따라가는 방식과 유사함
- **탐색 원리 :** 스택 자료 구조나 재귀 함수를 사용하여 마지막에 방문한 노드를 먼저 처리함
- **특징 :**
    - 모든 노드를 방문해야 할 때 유용함
    - 재귀 함수로 구현하기 때문에 코드가 간결할 수 있음
    - BFS보다 메모리 사용량이 적은 경우가 많음
- **예시:**

![dfs.gif](dfs.gif)

- **예제 코드**

```cpp
#include <iostream>
#include <vector>

using namespace std;

vector<int> example[10];
// 10개의 노드를 가질 수 있는 인접 리스트
bool check[10];    
// 방문한 노드를 체크하는 배열 (무한 루프 방지)

void dfs(int x) {   // x는 현재 탐색 중인 노드의 번호
    check[x] = true;    // 노드 x를 방문 했다고 표시
    cout << x << " ";

    for (int i = 0; i < example[x].size(); i++) {
    // 현재 노드 x에 연결된 모든 노드들을 순회
        int y = example[x][i]; 
        // 다음으로 이동할 연결 노드 y
        if (!check[y]) {   
        // 만약 다음 노드 y를 아직 방문하지 않았다면
            dfs(y);   
            // y번 노드에서 DFS 진행 (재귀 호출)
        }
    }
}

int main() {
    // 인접 리스트를 활용하여 컴퓨터들의 연결 상태를 설정
    // 1번 노드 -> 2번 노드 = 2번 노드 -> 1번 노드
    // (양방향 연결)
    example[1].push_back(2);
    example[2].push_back(1);
    example[1].push_back(3);
    example[3].push_back(1);
    example[2].push_back(4);
    example[4].push_back(2);
    example[3].push_back(4);
    example[4].push_back(3);

    cout << "DFS 탐색 순서: ";
    dfs(1); // 1번 노드에서 DFS 시작
    cout << endl;
    return 0;
}
```

</aside>