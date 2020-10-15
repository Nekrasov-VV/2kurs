#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
template<class Type=int>
class Stack {
		Type *body; //массив для хранения объектов в стеке
		int Maxsize,top;//глубина стека и вершина, индекс вершины указывает на свободное место в стеке
		public:
		Stack(int);
		~Stack();
		int Push(const Type &);//добавление элемента
		int Pop(Type &); //извлечение элемента
		Stack(const Stack<Type> &);
		Stack<Type> & operator =(const Stack<Type> &);
};

template<class Type>
Stack<Type>:: Stack(int n){
		Maxsize=n;//маесимально возможное количество элементов в стеке
		top=0;//позиция вершины пустого сттека
		body=new Type[n];//массив для хранения элементов стека
}
template<class Type>
Stack<Type>:: ~Stack(){
		delete []body;
}
template<class Type>
int Stack<Type>::Push(const Type &v){//возвращает истину, если удалось положить в стек и ложь иначе
	return top==Maxsize?0:(body[top]=v,++top);
}
template<class Type>
int Stack<Type>::Pop(Type &v){//возвращает истину, если удалось извлечь из стека и ложь иначе
	return top?(v=body[top-1],top--):0;
}
template<class Type> 
Stack<Type>:: Stack(const Stack<Type> &v){
		Maxsize=v.Maxsize;
		top=v.top;
		body=new Type[Maxsize];
		for (int i=0;i<top;i++)
			body[i]=v.body[i];
}

template<class Type> Stack<Type> &
Stack<Type>:: operator=(const Stack<Type> &v){
		if(this==&v)
			return *this;
		delete []body;
		Maxsize=v.Maxsize;
		top=v.top;
		body=new Type[Maxsize];
		for (int i=0;i<top;i++)
			body[i]=v.body[i];
		return *this;
}
template<class Type> void
	Pr(Stack<Type> v){ //печать с сохранением стека
		Type u;
		while(v.Pop(u))
			cout<<" "<<u;
	cout<<"\n";
}
template<class Type> void
	invert(Stack<Type> &v){//переворо стека
		Type u;
		Stack<Type> r(v); //сохраняем стек
		while(v.Pop(u)) //опустошаем
			;
		while(r.Pop(u)) // пока есть элементы в копии стека, извлекаем и возвращаем их в исходный
			v.Push(u);
	}

