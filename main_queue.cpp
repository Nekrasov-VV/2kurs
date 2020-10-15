#include"queue.h"
#include"my.h" // тест для класса , определенного в этом afqkt

int main(){
	srand(time(NULL));
	Queue<Student>q(5);//очередь целых чисел создается вызовом Queue<>
	int k=3;
	do{
	   ;
	}
	while(q.Push(++Student(++k)));//заполняем очередь студентами
	pr(q);
	Student u;
	q.Pop(u); //обслуживаем голову
	q.Push(Student(3)); //очередь подвинулась на 1 позицию
	Ppr(q);
    	return 0;
}

