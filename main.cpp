#include"my.h"
int main(){ 
	srand(time(NULL));//для генерации различных (от вызова к вызову) случайных чисел
	Student a,b; 
	printf("a= ");
	a.pr(); 
	printf("b= ");
	b.pr();
	cout<<b+a++;//у а используется старая группа
	cout<<a;//если возможно, a перейдет на следующий курс
	cout<<Student()+a+Student()+ ++b;//сумму с безымянным объектом можно вставить в поток
	return 0;
}
