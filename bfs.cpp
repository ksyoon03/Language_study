#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> example[10];   // 10개의 노드를 가질 수 있는 인접 리스트
bool check[10];     // 방문한 노드를 체크하는 배열 (무한 루프 방지)

void bfs(int x) {   // x는 탐색을 시작할 노드의 번호
    queue <int> q;  // BFS 탐색을 위한 큐
    q.push(x);  // 시작 노드 x를 큐에 넣음
    check[x] = true;    // 시작 노드 x를 방문 했다고 표시
    cout << x << " ";

    while (!q.empty()) {    // 큐가 비어있지 않다면 반복
        int y = q.front();  // 현재 탐색 중인 노드 y를 큐에서 꺼냄
        q.pop();    // 꺼낸 노드는 큐에서 제거

        for (int i = 0; i < example[y].size(); i++) {   // 현재 노드 y와 연결된 모든 노드들을 순회
            int z = example[y][i];  // 다음으로 이동할 연결 노드 z
            if (!check[z]) {    // 만약 다음 노드 z를 아직 방문하지 않았다면
                check[z] = true;    // 다음 노드 z를 방문했다고 표시
                q.push(z);  // 다음 노드 z를 큐에 추가
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