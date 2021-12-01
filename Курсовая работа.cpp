// ��������� �������� ������ ����
// ��������� l2
// ������� l1
#include <iostream>
#include <stdio.h> // ������� ������������ ����� - ������
#include <stdlib.h> // ������� malloc
struct ochered{
	int data;
	struct ochered* next;
}; //  ������� ��������� ������� � ���������� �� ����. �������

typedef struct ochered Ftype; // ����������� ������� �� ��� Ftype

Ftype* CreateFtype(int data){
	Ftype *a;
	a = (Ftype*)malloc(sizeof(Ftype));
	a->data = data;
	a->next = NULL;
	return a;
} // ������� ������ ������� �������

Ftype* AddFtype(Ftype* a,int data){
	while(a->next != NULL){
		a = a->next;
	}
	Ftype* CreatedFtype = (Ftype*)malloc(sizeof(Ftype));
	CreatedFtype->next = NULL;
	CreatedFtype->data = data;
	a->next = CreatedFtype;
	return a->next;
} // ������� ����������� �������� �������. ������������� ���������� ����� ���������� �������� �������.

void PrintFtype(Ftype* uk,int place){
	Ftype* a = uk;
	int i=1+place;
	printf("�������:\n");
	while(a != NULL){
		printf("�������[%d] %d\n",i,a->data);
		a = a->next;
		i++;
}
printf("\n");
} // ����� ����� ����� ������� � ������� � �������

void PrintlnFtype(Ftype* uk){
	Ftype* a = uk;
	while(a != NULL){
		printf("%d ",a->data);
		a = a->next;
}
printf("\n");
} // ����� ����� ����� ������� � ������� � �������

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
} // ���������� ����� �������

void DeleteAllFtype(Ftype* uk){
	Ftype* a = uk;
	Ftype* buffer = uk;
	do{
		buffer = a->next;
		free(a);
		a = buffer;
	}while(a != NULL);
} // ������� ��� �������� �������, ��� ���� ������ ������

Ftype* DeleteFirstFtype(Ftype* e){
	Ftype* buf = e->next;
	free(e);
	e = buf;
	return e;
} // ������� ������ ������� �������, ��� ���� ������� ������

int readInt(){
	int num =0;
	std::cout<<"������� ����� �����: ";
	scanf("%d",&num);
	return num;
} // ������ ������ ����� �����. ���������� ���

Ftype* MenuFtype(){
	int number=-1;
	int mode =0;
	int REMEBMER = 0; // ����������� ���������� ������ ��� 6��� ������
	int place = 0;
	int MAX_Ftype = 5; // ������������ ���������� ��������� � �������
	Ftype* e = NULL; // ��������� �� ������ �������
	Ftype* last = NULL; // ��������� �� ����� �������
	while(1){
	printf("��������� ������: �������. ������������ ����� = %d\n",MAX_Ftype);
	printf("��������� ��������:\n");
	printf("1. ������ ������ � ��������\n");
	printf("2. ������� ������� ������\n");
	printf("3. ��������� ����� �� �������\n");
	printf("4. ������� �������� �������� � ������ �������\n");
	printf("5. ������� ������ �������\n");
	printf("6. ����� ������� �� ������ �������\n");
	printf("7. �������� �������� � ������ �������\n");
	printf("8. �������� ������� � ����� �������\n");
	printf("9. ����������� �������\n");
	printf("10. ��������� ������ � ��������\n\n");
	printf("�������� ����� ����:\n");
	
	scanf("%d",&number);
	system("cls"); // �������� �������
	
	if (number == 1 && mode == 1) std::cout<<"�� ��� ������ ������ � ��������.\n";
	if (number == 1) mode = 1;
	if (mode ==1){
		if (number ==2 && LengthFtype(e)>0){
				DeleteAllFtype(e);
				e = NULL;
				last = NULL;
		}
		if (number ==3) LengthFtype(e)?std::cout<<"������� �� �����.\n":std::cout<<"������� �����.\n";
		if (LengthFtype(e)>0){
		if (number ==4) std::cout<<"�������� �������� � ������ = "<<e->data<<"\n";
		if (number ==5) {e=DeleteFirstFtype(e);if(LengthFtype(e))place++;};
		if (number ==6){
			REMEBMER = e->data;
			std::cout<<"�������� ������� �������� �������� = "<< REMEBMER <<"\n";
			e = DeleteFirstFtype(e);
			place++;
		}
		if (number ==7) e->data = readInt();
		}
		else if (number>=4 && number<=7) std::cout<< "������. ������� �����.\n";
		if (number ==8) {

		if (place+LengthFtype(e)<MAX_Ftype) // �������� ������� �� ������������
		 
		if (LengthFtype(e)) last=AddFtype(e,readInt());
		else {e = CreateFtype(readInt()); place =0; }// ���� ����� = 0, �� ���������� �-� ��������� ������ ����, ����� �-� ��������� ����������� �-��
		
		else std::cout<<"������� �����������! ������ �������� ������.\n";
		}
		if (number ==9) PrintFtype(e,place);
		if (number ==10) return e;
	}
	else std::cout << "�� �� ������ ������ � ��������. ����� 1.\n";
}
} // ���� �������

int equalsFtype(Ftype*a,Ftype*b){
	if (LengthFtype(a)!=LengthFtype(b)) return 0;
	else
	while(a != NULL){
		if (a->data != b->data) return 0;
		a = a->next;
		b = b->next;
	}
	return 1;
} // ���������� 2 �������.���� ������� �����, ���������� 1, ���� ������� ���������� 0

struct mnoshestvo{
	Ftype* data;
	struct mnoshestvo* next;
	struct mnoshestvo* prev;
};  // ������� ��������� �������� � ����������� �� ����. � ����. �������
typedef struct mnoshestvo Stype; // ����������� ��������� �� ��� Stype

Stype* CreateStype(Ftype* data){
	Stype *a;
	a = (Stype*)malloc(sizeof(Stype));
	a->data = data;
	a->next = NULL;
	a->prev = NULL;
	return a;
} // ������� ������ ������� � ���������

Stype* AddStype(Stype* a,Ftype* d){
	while(a->next != NULL){
		a = a->next;
	}
	Stype* CreatedStype = (Stype*)malloc(sizeof(Stype));
	CreatedStype->next = NULL;
	CreatedStype->data = d;
	CreatedStype->prev = a;
	a->next = CreatedStype;
	return a->next;
} // ������� ����������� �������� � ���������

void PrintStype(Stype* a,Stype* b){
	int i = 1,num=0;
	printf("�� ������ ������� ��������� � ������� ������� ��� � ��������?\n������� 1- ���� � �������, 2- ���� � ��������: ");
	scanf("%d",&num);
	if (num == 1){
		printf("���������:\n");
		while(a != NULL){
		printf("�������[%d] ",i);
		PrintlnFtype(a->data);
		a=a->next;
		i++;
		}
	}
	if (num == 2){
		printf("���������:\n");
		while(b != NULL){
		printf("�������[%d] ",i);
		PrintlnFtype(b->data);
		b=b->prev;
		i++;
		}
	}
} // ������� ��������� � ������ ��� �������� �������

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
} // ���������� ����� ���������

void DeleteAllStype(Stype* uk){
	Stype* a = uk;
	Stype* buffer = uk;
	do{
		buffer = a->next;
		free(a);
		a = buffer;
	}while(a != NULL);
} // ������� ��� �������� �������, ��� ���� ������ ������

void MenuStype(){
	int number=-1;
	int mode =0;
	int REMEBMER = 0; // ����������� ���������� ������ ��� 6��� ������
	Stype* e = NULL; // ��������� �� ������ �������
	Stype* last = NULL; // ��������� �� ����� �������
	while(1){
	printf("��������� ������: ���������.");
	printf("��������� ��������:\n");
	printf("1. ������ ������ � ����������\n");
	printf("2. ������� ��������� ������\n");
	printf("3. ��������� ����� �� ���������\n");
	printf("4. ������� ��������� ������� �� ���������\n");
	printf("5. ����� �����-���� ������� �� ���������\n");
	printf("6. �������� ������� � ���������\n");
	printf("7. �������� ����������� �� ������� ���������\n");
	printf("8. ����������� ���������\n");
	printf("9. ��������� ������ � ����������\n\n");
	printf("�������� ����� ����:\n");
	
	scanf("%d",&number);
	system("cls"); // �������� �������
	
	if (number == 1 && mode == 1) std::cout<<"�� ��� ������ ������ � ����������.\n";
	if (number == 1) mode = 1;
	if (mode == 1){
		if (number == 2) {
			DeleteAllStype(e);
			last = NULL;
			e = NULL;
		}
		if (number == 3) LengthStype(e)?std::cout<<"��������� �� �����\n":std::cout<<"��������� �����\n";
		if (number == 4);
		if (number == 5);
		if (number == 6){
			if (LengthStype(e)) last = AddStype(e,MenuFtype());
			else{
			e=CreateStype(MenuFtype());
			last=e;
			}
		}
		if (number == 7);
		if (number == 8) PrintStype(e,last);
		if (number == 9) break;
	}
}
}
	
int main(){
	setlocale(LC_ALL, "Russian"); // ��������� �������� ����� � ������
	
	MenuStype();
	
	return 0;
}
/*
Stype* start;
	Stype* last;
	Ftype* uk;
	uk = MenuFtype();
	start = CreateStype(uk);
	last = AddStype(start,MenuFtype());
	PrintStype(start,last);
*/

