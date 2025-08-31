#include <iostream>
#include <vector>
using namespace std;

vector<int> example[10]; // 10���� ��带 ���� �� �ִ� ���� ����Ʈ
bool check[10];     // �湮�� ��带 üũ�ϴ� �迭 (���� ���� ����)

void dfs(int x) {   // x�� ���� Ž�� ���� ����� ��ȣ
    check[x] = true;    // ��� x�� �湮 �ߴٰ� ǥ��
    cout << x << " ";

    for (int i = 0; i < example[x].size(); i++) { // ���� ��� x�� ����� ��� ������ ��ȸ
        int y = example[x][i];  // �������� �̵��� ���� ��� y
        if (!check[y]) {    // ���� ���� ��� y�� ���� �湮���� �ʾҴٸ�
            dfs(y);    // y�� ��忡�� DFS ���� (��� ȣ��)
        }
    }
}

int main() {
    // ���� ����Ʈ�� Ȱ���Ͽ� ��ǻ�͵��� ���� ���¸� ����
    // 1�� ��� -> 2�� ��� = 2�� ��� -> 1�� ��� (����� ����)
    example[1].push_back(2);
    example[2].push_back(1);
    example[1].push_back(3);
    example[3].push_back(1);
    example[2].push_back(4);
    example[4].push_back(2);
    example[3].push_back(4);
    example[4].push_back(3);

    cout << "DFS Ž�� ����: ";
    dfs(1); // 1�� ��忡�� DFS ����
    cout << endl;
    return 0;
}