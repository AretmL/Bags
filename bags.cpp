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

    int things[n];
    
    cout << "Введите вес каждого предмета:\n";
    
    for(int i{0}; i < n; i ++){
    	do{
    		flag1 = 0;
			cout << i + 1 << ") ";
			cin >> x;
			if(cin.fail() || x < 0){
				flag1 = 1;
				cout << "Ошибка! Вы ввели недопустимый символ! Введите положительное число!\n";
				cin.clear();
				cin.ignore();
			}
		}
		while(flag1 != 0);
    	things[i] = x;
	}

    return 0;
}