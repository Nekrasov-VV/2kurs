#include"list.h" 

int main(){
	srand(time(NULL));
        List m;
	int n=9;
	for(int i=1;i<n;i++) {
		m.Ins(rand()%11); //загружаем в список объекты
		m.GoToNext();//сдвигаемся по списку, чтобы сохранить порядок элементов (иначе порядок изменится на противоположный)
	}
	cout<<"begin\n"<<m;
	m.GoToBegin();m.GoToNext();m.GoToNext();//подготовка к циклическому сдвигу
	m.foo();
	cout<<"cyle-2\n"<<m;
	m.sort();
	cout<<"sort\n"<<m;
	return 0;
}