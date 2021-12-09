// Множество очередей целого типа
// множество l2
// очередь l1

#define ANSI_COLOR_MAGENTA "\x1b[35m" // включить фиолетовый цвет
#define ANSI_COLOR_RESET   "\x1b[0m" // включить белый цвет

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
	if (a == NULL) {std::cout<<"Ошибка. Память переполненна.\n"; exit(1);}
	else {
	a->data = data;
	a->next = NULL;
	}
	return a;
} // создаем первый элемент очереди

Ftype* AddFtype(Ftype* a,int data){
	while(a->next != NULL){
		a = a->next;
	}
	Ftype* CreatedFtype = (Ftype*)malloc(sizeof(Ftype));
	if (CreatedFtype == NULL) {std::cout<<"Ошибка. Память переполненна.\n"; exit(1);}
	else {
	CreatedFtype->next = NULL;
	CreatedFtype->data = data;
	a->next = CreatedFtype;
	}
	return a->next;
} // создает последующие элементы очереди. Дополнительно возвращает адрес последнего элемента очереди.

void PrintFtype(Ftype* uk,int place){
	Ftype* a = uk;
	int i=1+place;
	printf("Очередь:\n");
	while(a != NULL){
		printf("Элемент[%d] %d\n",i,a->data);
		a = a->next;
		i++;
}
printf("\n");
} // вывод целых типов лежащих в очереди в столбик

void PrintlnFtype(Ftype* uk){
	Ftype* a = uk;
	while(a != NULL){
		printf("%d ",a->data);
		a = a->next;
}
printf("\n");
} // вывод целых типов лежащих в очереди в столбик

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
	std::cout<<"Введите целое число: ";
	scanf("%d",&num);
	return num;
} // просит ввести целое число. Возвращает его

Ftype* MenuFtype(){
	int number=-1;
	int mode =0;
	int REMEBMER = 0; // специальная переменная нужная для 6ого пункта
	int place = 0;
	int MAX_Ftype = 5; // максимальное количество элементов в очереди
	Ftype* e = NULL; // указатель на начало очереди
	Ftype* last = NULL; // указатель на конец очереди
	while(1){
	printf(ANSI_COLOR_MAGENTA);
	printf("Структура данных: очередь. Максимальная длина = %d\n",MAX_Ftype);
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
		if (number ==5) {e=DeleteFirstFtype(e);if(LengthFtype(e))place++;};
		if (number ==6){
			REMEBMER = e->data;
			std::cout<<"Значение взятого элемента = "<< REMEBMER <<"\n";
			e = DeleteFirstFtype(e);
			place++;
		}
		if (number ==7) e->data = readInt();
		}
		else if (number>=4 && number<=7) std::cout<< "Очередь пуста.\n";
		if (number ==8) {

		if (place+LengthFtype(e)<MAX_Ftype) // проверка условия на переполнение
		 
		if (LengthFtype(e)) last=AddFtype(e,readInt());
		else {e = CreateFtype(readInt()); place =0; last=e;}// если длина = 0, то вызвыается ф-я создающая первый элем, иначе ф-я создающая последующие э-ты
		
		else std::cout<<"Очередь переполнена! Нельзя добавить элемет.\n";
		}
		if (number ==9) PrintFtype(e,place);
		if (number ==10) {printf(ANSI_COLOR_RESET);return e;}
		if (number >10 || number<=0) std::cout<< "Ошибка. Неверно выбран номер действия"<< '\n';
	}
	else std::cout << "Вы не начали работу с очередью. Пункт 1.\n";
}
} // Меню очереди. Возвращает созданную очередь

int equalsFtype(Ftype*a,Ftype*b){
	if (LengthFtype(a)!=LengthFtype(b)) return 0;
	else
	while(a != NULL){
		if (a->data != b->data) return 0;
		a = a->next;
		b = b->next;
	}
	return 1;
} // Сравнивает 2 очереди.Если очереди равны, возвращает 1, если неравны возвращает 0

struct mnoshestvo{
	Ftype* data;
	struct mnoshestvo* next;
	struct mnoshestvo* prev;
};  // создали структуру множесва с указателями на след. и прев. элемент
typedef struct mnoshestvo Stype; // переназвали множество на тип Stype

Stype* CreateStype(Ftype* data){
	Stype *a;
	a = (Stype*)malloc(sizeof(Stype));
	if (a == NULL) {std::cout<<"Ошибка. Память переполненна.\n"; exit(1);}
	else {
	a->data = data;
	a->next = NULL;
	a->prev = NULL;
	}
	return a;
} // создаем первый элемент в множестве

Stype* AddStype(Stype* a,Ftype* d){
	while(a->next != NULL){
		a = a->next;
	}
	Stype* CreatedStype = (Stype*)malloc(sizeof(Stype));
	if (CreatedStype == NULL) { std::cout<<"Ошибка. Память переполненна.\n"; exit(1);}
	else{
	CreatedStype->next = NULL;
	CreatedStype->data = d;
	CreatedStype->prev = a;
	a->next = CreatedStype;
	}
	return a->next;
} // создаем последующие элементы в множестве

void PrintStype(Stype* a,Stype* b){
	int i = 1,num=0;
	printf("Вы хотите вывести множество в обычном порядке или в обратном?\nВведите 1- если в обычном, 2- если в обратном: ");
	scanf("%d",&num);
	if (num == 1){
		printf("Множество:\n");
		while(a != NULL){
		printf("Элемент[%d] ",i);
		PrintlnFtype(a->data);
		a=a->next;
		i++;
		}
	}
	if (num == 2){
		printf("Множество:\n");
		while(b != NULL){
		printf("Элемент[%d] ",i);
		PrintlnFtype(b->data);
		b=b->prev;
		i++;
		}
	}
	printf("\n");
} // вывести множество в прямом или обратном порядке

int LengthStype(Stype* uk){
	int len = 0;
	if (uk == NULL) return 0;
	else{
		while(uk != NULL){
		uk = uk->next;
		len++;
		}
	return len;
	}
} // возвращает длину множества

void DeleteAllStype(Stype* uk){
	Stype* a = uk;
	Stype* buffer = uk;
	do{
		buffer = a->next;
		free(a);
		a = buffer;
	}while(a != NULL);
} // удаляет все элементы очереди, при этом очищая память

int equalsStype(Stype*a,Ftype*b){
	while(a != NULL){
		if (equalsFtype(a->data,b)) return 1;
		a=a->next;
	}
	return 0;
} // Сравнивает множества и одну очередь.Если очередь есть в множестве, возвращает 1, если нет возвращает 0

Stype* DeleteFirstStype(Stype* e){
	Stype* buf = e->next;
	free(e);
	e = buf;
	e->prev = NULL;
	return e;
} // удаляет первый элемент множества, при этом очищает память

Stype* DeleteCurrentStype(Stype* e,Stype* last,Ftype* b){
	Stype* head = e;
	if (equalsFtype(e->data,b)) return DeleteFirstStype(e);
	if (equalsFtype(last->data,b)){
		last->prev->next = NULL;
		free(last);
		return e;
	}
	while (e != NULL){
		if (equalsFtype(e->data,b)){
			Stype* prev = e->prev;
			Stype* next = e->next;
			e->next->prev = prev;
			e->prev->next = next;
			free(e);
			return head;
		}
		e=e->next;
	}
	return head;
}

Stype* MenuStype(){
	int number=-1;
	int mode =0;
	Ftype* REMEBMER = 0; // специальная переменная нужная для 6ого пункта
	Stype* e = NULL; // указатель на начало очереди
	Stype* last = NULL; // указатель на конец очереди
	while(1){
	printf("Структура данных: множество.\n");
	printf("Доступные операции:\n");
	printf("1. Начать работу с множеством\n");
	printf("2. Сделать множество пустым\n");
	printf("3. Проверить пусто ли множество\n");
	printf("4. Удалить выбранную очередь из множества\n");
	printf("5. Взять какую-либо очередь из множества\n");
	printf("6. Добавить очередь в множество\n");
	printf("7. Проверка принадлежит ли очередь множеству\n");
	printf("8. Распечатать множество\n");
	printf("9. Закончить работу с множеством\n\n");
	printf("Выберите пункт меню:\n");
	
	scanf("%d",&number);
	system("cls"); // очистить консоль
	
	if (number == 1 && mode == 1) std::cout<<"Вы уже начали работу с множеством.\n";
	if (number == 1) mode = 1;
	if (mode == 1){
		if (number == 2) {
			if (LengthStype(e)){
			DeleteAllStype(e);
			last = NULL;
			e = NULL;
			}
			else std::cout<<"Множество пусто.\n" ;
		}
		if (number == 3) LengthStype(e)?std::cout<<"Множество НЕ пусто\n":std::cout<<"Множество ПУСТО\n";
		if (number == 4) {
			if (LengthStype(e)) e=DeleteCurrentStype(e,last,MenuFtype());
			else std::cout<<"Множество пусто.\n" ;
		}
		if (number == 5){
			if (LengthStype(e)){
				REMEBMER = e->data;
				std::cout<<"Значение взятого множества равно = " ;
				PrintlnFtype(REMEBMER);
				if (LengthStype(e) > 1)
				e = DeleteFirstStype(e);
				else {
					DeleteAllStype(e);
					last = NULL;
					e = NULL;
				}
			}
			else std::cout<<"Множество пусто.\n" ;
		}
		if (number == 6){
			if (LengthStype(e)){
			Ftype* read = MenuFtype();
			if (equalsStype(e,read)) std::cout<<"Ошибка. Данное очередь уже есть в множестве.\n";
			else last = AddStype(e,read);
			}
			else{
			e=CreateStype(MenuFtype());
			last=e;
			}
		}
		if (number == 7) {
			if(LengthStype(e))
				equalsStype(e,MenuFtype())?std::cout<<"Данная очередь ЕСТЬ в множестве.\n\n":std::cout<<"Данной очереди НЕТ в множестве.\n\n";
			else std::cout<<"Множество пусто.\n" ;
		}
		if (number == 8) PrintStype(e,last);
		if (number == 9) return e;
		if (number >9 || number<=0) std::cout<< "Ошибка. Неверно выбран номер действия"<< '\n';
	}
	else std::cout << "Вы не начали работу с множества. Пункт 1.\n";
}
} // Меню множества.
	
int main(){
	setlocale(LC_ALL, "Russian"); // Включение русского языка в проект
	
	MenuStype();
	
	return 0;
}
