#include <iostream>
using namespace std;

int main() {
    //yΪ���ӵ�������mΪͷ��������nΪ�ŵ�����
    int m, n;
    cout << "���������뼦���õ����������ȵ���������";
    cin >> m >> n;

    if (n < 2 * m || n > 4 * m || n % 2 == 1) {
        cout << "�޽�";
    } else {
        //n-2mһ��Ϊż��
        int y = (n - 2 * m) / 2;
        int x = m - y;
        cout << "����" << x << " �ã�" << y << endl;
    }

    return 0;
}
