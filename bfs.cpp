#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> example[10];   // 10���� ��带 ���� �� �ִ� ���� ����Ʈ
bool check[10];     // �湮�� ��带 üũ�ϴ� �迭 (���� ���� ����)

void bfs(int x) {   // x�� Ž���� ������ ����� ��ȣ
    queue <int> q;  // BFS Ž���� ���� ť
    q.push(x);  // ���� ��� x�� ť�� ����
    check[x] = true;    // ���� ��� x�� �湮 �ߴٰ� ǥ��
    cout << x << " ";

    while (!q.empty()) {    // ť�� ������� �ʴٸ� �ݺ�
        int y = q.front();  // ���� Ž�� ���� ��� y�� ť���� ����
        q.pop();    // ���� ���� ť���� ����

        for (int i = 0; i < example[y].size(); i++) {   // ���� ��� y�� ����� ��� ������ ��ȸ
            int z = example[y][i];  // �������� �̵��� ���� ��� z
            if (!check[z]) {    // ���� ���� ��� z�� ���� �湮���� �ʾҴٸ�
                check[z] = true;    // ���� ��� z�� �湮�ߴٰ� ǥ��
                q.push(z);  // ���� ��� z�� ť�� �߰�
                cout << z << " ";
            }
        }
    }
}

int main() {
    // ���� ����Ʈ�� Ȱ���Ͽ� ��ǻ�͵��� ���� ���¸� ����
    // 1�� ��� -> 2�� ��� = 2�� ��� -> 1�� ���
    // (����� ����)
    example[1].push_back(2);
    example[2].push_back(1);
    example[1].push_back(3);
    example[3].push_back(1);
    example[2].push_back(4);
    example[4].push_back(2);
    example[3].push_back(4);
    example[4].push_back(3);

    cout << "BFS Ž�� ����: ";
    bfs(1);    // 1�� ��忡�� BFS ����
    cout << endl;
}