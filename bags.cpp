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

    int x_count{0}, flag{0}, x1, y, n1 = n;
	int answer[n] = {0};
	int repeat[n] = {0};
	
	for(int i1{0}; i1 < n; i1++){
		n1 = n;
		x_count = 0;
		flag = 0;
		x1 = things[i1];
		for(int i2{0}; i2 < n; i2++){
			y = things[i2];
			if(x1 > y){
				x_count += 1;
			}
			else if(x1 == y && flag == 0){
				flag = 1;
			}
			else if(x1 == y && flag == 1){
				x_count += 1;
			}
		}
		if(repeat[n - 1 - x_count] == 0){
			answer[n - 1 - x_count] = x1;
			repeat[n - 1 - x_count] = x1;
		}
		else{
			while(repeat[n1 - 1 - x_count] != 0){
				n1 += 1;
			}
			answer[n1 - 1 - x_count] = x1;
			repeat[n1 - 1 - x_count] = x1;
		}
	}
	
	int bag1{0}, bag2{0}, count_bag1{0}, count_bag2{0}; 
	int bag1_mass[n];
	int bag2_mass[n];
	
	for(int i3{0}; i3 < n; i3++){
		if(bag1 == bag2){
			bag1 += answer[i3];
			bag1_mass[count_bag1] = answer[i3];
			count_bag1 += 1;
		}
		else if(bag1 > bag2){
			bag2 += answer[i3];
			bag2_mass[count_bag2] = answer[i3];
			count_bag2 += 1;
		}
		else if(bag2 > bag1){
			bag1 += answer[i3];
			bag1_mass[count_bag1] = answer[i3];
			count_bag1 += 1;
		}
	}
	count_bag1 -= 1;
	count_bag2 -= 1;

	cout << "Вес первого рюкзака составляет " << bag1 << " кг.\n";
	cout << "В нем лежат вещи данного веса: ";
	for(int i4{0}; i4 < n; i4++){
		if(i4 <= count_bag1){
			cout << bag1_mass[i4] << "; ";
		}
		else{
			break;
		}
	}
	cout << "\n";
	
	cout << "Вес второго рюкзака составляет " << bag2 << " кг.\n";
	cout << "В нем лежат вещи данного веса: ";
	for(int i5{0}; i5 < n; i5++){
		if(i5 <= count_bag2){
			cout << bag2_mass[i5] << "; ";
		}
		else{
			break;
		}
	}
	cout << "\n";
	
	cout << "Разница веса рюкзаков составляет: " << abs(bag1 - bag2) << " кг." << endl;

    return 0;
}