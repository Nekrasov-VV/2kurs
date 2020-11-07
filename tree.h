#include <iostream> //шаблон бинарного дерева поиска, рекурсия
using namespace std;
template<class T=int, class Type=int>
class Tree{
	T v;Type key;
	Tree *left,*right;
	public:
	Tree(const T&,const Type&);
	~Tree();
	void pr();
	void Ins(const T&,const Type&);
};
template<class T, class Type>
Tree<T,Type>::Tree(const T&v,const Type&key){
	this->v=v;
	this->key=key;
	left=right=nullptr;
}
template<class T, class Type>
Tree<T,Type>::~Tree(){
	delete left;
	delete right;
}
template<class T, class Type>
void Tree<T,Type>::pr(){ //обход дерева поиска слева направо
	if(left)
		left->pr();
	cout<<v<<" key "<<key<<"\n";
	if(right)
		right->pr();
}
template<class T, class Type> 
void Tree<T,Type>::Ins(const T&v,const Type&key){ //добавление элемента в дерво поиска
	if(left&&key<this->key){
		left->Ins(v,key);
		return;
	}
	if(right&&key>=this->key){
		right->Ins(v,key);
		return;
	}
	Tree *t=new Tree(v,key);
	if(key<this->key)
		left=t;
	else
		right=t;
}
