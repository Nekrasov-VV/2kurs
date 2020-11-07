#include"list.h" 

List List::operator +(const List &m){
	List tmp(*this);
	for(auto it=m.Begin();it!=m.End();++it){
		tmp.Ins(*it);
		tmp.GoToNext();
	}
	return tmp;
}
