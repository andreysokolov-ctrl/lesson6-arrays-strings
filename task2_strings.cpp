#include <iostream>
#include <string>
using namespace std;
int main() {
    const string OPEN  = "<strong>";
    const string CLOSE = "</strong>";
    const int OPEN_LEN  = OPEN.length();   // длина тега: не пересчитываем каждый раз

    string line;
    cout << "Введите текст (пустая строка — конец ввода):" << endl;

    while (getline(cin, line)) {
        // Пустая строка — сигнал завершения ввода
        if (line.empty()) break;
        size_t openPos  = line.find(OPEN);
        size_t closePos = line.find(CLOSE);
        if (openPos  != string::npos &&
            closePos != string::npos &&
            closePos > openPos) {
            size_t nameStart = openPos + OPEN_LEN;
            string name = line.substr(nameStart, closePos - nameStart);

            cout << name << endl;
        }
       
    }

    return 0;
}
