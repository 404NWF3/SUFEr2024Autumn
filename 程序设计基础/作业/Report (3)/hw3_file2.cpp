#include <iostream>
using namespace std;

void replaceAll(char s[], char c1, char c2) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c2) s[i] = c1;
    }
}

int main() {
    char s1[81] = "nannies";
    char c1, c2;
    replaceAll(s1, 'd', 'n');
    cout << s1 << endl;
    cout << "�������ַ���:";
    cin.getline(s1, 80, '\n');
    cout << "��������滻�ַ�:";
    cin >> c2;
    cout << "�������滻���ַ�:";
    cin >> c1;
    replaceAll(s1, c1, c2);
    cout << s1;
    return 0;
}
