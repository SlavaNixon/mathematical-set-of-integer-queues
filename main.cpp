// Множество очередей целого типа
// множество l2
// очередь l1
#include <iostream>
#include <stdio.h> // Функции стандартного ввода - вывода
#include <stdlib.h> // Функция malloc
struct ochered{
	int data;
	struct ochered* next;
}; //  создали структуру очереди с указателем на след. элемент

typedef struct ochered Ftype; // переназвали очередь на тип Ftype

Ftype* CreateFtype(int data){
	Ftype *a;
	a = (Ftype*)malloc(sizeof(Ftype));
	a->data = data;
	a->next = NULL;
	return a;
} // создаем первый элемент очереди

Ftype* AddFtype(Ftype* a,int data){
	while(a->next != NULL){
		a = a->next;
	}
	Ftype* CreatedFtype = (Ftype*)malloc(sizeof(Ftype));
	CreatedFtype->next = NULL;
	CreatedFtype->data = data;
	a->next = CreatedFtype;
	return a->next;
} // создает последующие элементы очереди. Дополнительно возвращает адрес последнего элемента очереди.

void PrintFtype(Ftype* uk){
	Ftype* a = uk;
	int i=1;
	printf("Очередь:\n");
	while(a != NULL){
		printf("Элемент[%d] %d\n",i,a->data);
		a = a->next;
		i++;
}
printf("\n");
} // вывод целых типов лежащих в очереди

int LengthFtype(Ftype* uk){
	int len = 0;
	if (uk == NULL) return 0;
	else{
		while(uk != NULL){
		uk = uk->next;
		len++;
		}
	return len;
	}
} // определяет длину очереди

void DeleteAllFtype(Ftype* uk){
	Ftype* a = uk;
	Ftype* buffer = uk;
	do{
		buffer = a->next;
		free(a);
		a = buffer;
	}while(a != NULL);
} // удаляет все элементы очереди, при этом очищая память

Ftype* DeleteFirstFtype(Ftype* e){
	Ftype* buf = e->next;
	free(e);
	e = buf;
	return e;
} // удаляет первый элемент очереди, при этом очищает память

int readInt(){
	int num =0;
	std::cout<<"Введите целое число:";
	scanf("%d",&num);
	return num;
} // просит ввести целое число. Возвращает его

Ftype* MenuFtype(){
	int number=-1;
	int mode =0;
	int REMEBMER = 0; // специальная переменная нужная для 6ого пункта
	Ftype* e = NULL;
	Ftype* last = NULL;
	while(1){
	printf("Доступные операции:\n");
	printf("1. Начать работу с очередью\n");
	printf("2. Сделать очередь пустой\n");
	printf("3. Проверить пуста ли очередь\n");
	printf("4. Вывести значение элемента в начале очереди\n");
	printf("5. Удалить начало очереди\n");
	printf("6. Взять элемент из начала очереди\n");
	printf("7. Изменить значение в начале очереди\n");
	printf("8. Добавить элемент в конец очереди\n");
	printf("9. Распечатать очередь\n");
	printf("10. Закончить работу с очередью\n\n");
	printf("Выберите пункт меню:\n");

	scanf("%d",&number);
	system("cls"); // очистить консоль
	
	if (number == 1 && mode == 1) std::cout<<"Вы уже начали работу с очередью.\n";
	if (number == 1) mode = 1;
	if (mode ==1){
		if (number ==2 && LengthFtype(e)>0){
				DeleteAllFtype(e);
				e = NULL;
				last = NULL;
		}
		if (number ==3) LengthFtype(e)?std::cout<<"Очередь НЕ пуста.\n":std::cout<<"Очередь ПУСТА.\n";
		if (LengthFtype(e)>0){
		if (number ==4) std::cout<<"Значение элемента в начале = "<<e->data<<"\n";
		if (number ==5) e=DeleteFirstFtype(e);
		if (number ==6){
			REMEBMER = e->data;
			std::cout<<"Значение взятого элемента элемента = "<< REMEBMER <<"\n";
			e = DeleteFirstFtype(e);
		}
		if (number ==7) e->data = readInt();
		}
		else if (number>=4 && number<=7) std::cout<< "Ошибка. Очередь пуста.\n";
		if (number ==8) LengthFtype(e)?last=AddFtype(e,readInt()):e = CreateFtype(readInt()); // если длина = 0, то вызвыается ф-я создающая первый элем, иначе ф-я создающая последующие э-ты
		if (number ==9) PrintFtype(e);
		if (number ==10) return e;
	}
	else std::cout << "Вы не начали работу с очередью. Пункт 1.\n";
}
} // Меню очереди

int main(){
	setlocale(LC_ALL, "Russian"); // Включение русского языка в проект
	
	MenuFtype();
	
	return 0;
}

/*
	Ftype* e = NULL;
	Ftype* last = NULL;
	e = CreateFtype(50);
	last = AddFtype(e,53);
	last = AddFtype(e,533);
	PrintFtype(e);
*/
