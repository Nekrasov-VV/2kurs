#include"my.h"
#define N 111111
int main(){ 
	srand(time(NULL));//для генерации различных (от вызова к вызову) случайных чисел
	Student a(3),b(15);
	Student *mass[N],f(0);
	for(int i=0;i<N;i++)
		mass[i]=new Student(3+rand()%22);
	cout<<"0-i= "<<*mass[0]<<"posl= "<<*mass[N-1]; 
	f=*mass[0];
	clock_t t1=clock();
	for(int i=1;i<N;i++)
		f=f+*mass[i];
	clock_t t2=clock();
	cout<<"time="<<t2-t1<<"\nsumma="<<f;
	for(int i=0;i<N;i++)
		delete mass[i];

	printf("a= ");
	a.pr(); 
	printf("b= ");
	b.pr();
	Student c(0);
	c=a+b;
	cout<<"a+b= "<<c;
	cout<<"b+a++= "<<b+a++;//у а используется старая группа
	cout<<"a= "<<a;//если возможно, a перейдет на следующий курс
	cout<<"Student(5)+a+Student(9)+ ++b= "<<Student(5)+a+Student(9)+ b++;//сумму с безымянным объектом можно вставить в поток
	return 0;
}
