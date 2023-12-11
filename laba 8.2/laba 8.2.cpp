#include <iostream>
#include <locale>
#include <string>

using namespace std;

/*
* Лабораторная работа 8. Задание 2. Индивидуальный вариант 24.
* Дано зашифрованное предложение на английском языке и кодовое смещение K (0 < K < 10). Расшифровать предложение.
* return 0 - все ок. return 1 - ошибка.
*/

int main() {
    setlocale(LC_ALL, "rus");

    int k;
    string alphabet1 = "abcdefghijklmnopqrstuvwxyz";
    string alphabet2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string predl;

    cout << "Введите зашифрованное предложение на английском языке: ";

    getline(cin, predl);

    cout << "Введите кодовое смещение К: ";
    cin >> k;

    if (k < 0 || k > 10) {
        cerr << "Смещение должно быть в промежутке от 0 до 10!";
        return 1;
    }

    for (int i = 0; i < predl.size(); i++) {
        for (int j = 0; j < 26; j++) {
            if (predl[i] == alphabet1[j]) {
                if (j < k) {
                    predl[i] = alphabet1[26 - k + j];
                    break;
                }
                else {
                    predl[i] = alphabet1[j - k];
                    break;
                }
            }
            else {
                if (predl[i] == alphabet2[j]) {
                    if (j < k) {
                        predl[i] = alphabet2[26 - k + j];
                        break;
                    }
                    else {
                        predl[i] = alphabet2[j - k];
                        break;
                    }
                }
            }
        }
    }

    cout << "Расшифрованное предложение: " << predl;

}