#include <iostream>
#include <windows.h>
#include <string>
#include <math.h>

using namespace std;

int main() {
    
	setlocale(LC_ALL, "rus");

    int n, x, flag1{0};
    
    do{
    	flag1 = 0;
		cout << "Введите количество предметов: ";
		cin >> n;
    	if(cin.fail() || n < 0){
			flag1 = 1;
			cout << "Ошибка! Вы ввели недопустимый символ! Введите положительное число!\n";
			cin.clear();
			cin.ignore();
		}
	}
	while(flag1 != 0);

    return 0;
}