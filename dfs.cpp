#include <iostream>
#include <vector>
using namespace std;

vector<int> example[10]; // 10개의 노드를 가질 수 있는 인접 리스트
bool check[10];     // 방문한 노드를 체크하는 배열 (무한 루프 방지)

void dfs(int x) {   // x는 현재 탐색 중인 노드의 번호
    check[x] = true;    // 노드 x를 방문 했다고 표시
    cout << x << " ";

    for (int i = 0; i < example[x].size(); i++) { // 현재 노드 x에 연결된 모든 노드들을 순회
        int y = example[x][i];  // 다음으로 이동할 연결 노드 y
        if (!check[y]) {    // 만약 다음 노드 y를 아직 방문하지 않았다면
            dfs(y);    // y번 노드에서 DFS 진행 (재귀 호출)
        }
    }
}

int main() {
    // 인접 리스트를 활용하여 컴퓨터들의 연결 상태를 설정
    // 1번 노드 -> 2번 노드 = 2번 노드 -> 1번 노드 (양방향 연결)
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