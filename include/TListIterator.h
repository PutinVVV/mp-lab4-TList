#include "TList.h"
#include "TListNode.h"
using namespace std;
template<class T>
class TListIterator
{
protected:
	TList<T> list;
	TListNode<T>* cur;
public:
	TListIterator();
	TListIterator(TList<T>& l, TListNode<T>* p);
	TListIterator(const TListIterator<T>& p);
	TListIterator(TListIterator<T>&& p);
	~TListIterator();
	TListIterator<T>& operator=(const TListIterator<T>& p);
	TListIterator<T>& operator=(TListIterator<T>&& p);
	TListIterator<T>& operator++();
	TListIterator<T>& operator--();
	bool operator==(const TListIterator<T>& p);
	bool operator!=(const TListIterator<T>& p);
	void PushAfter(T* a);
	void PushBefore(T* a);
	TListIterator<T> GetBegin();
	TListIterator<T> GetEnd();

};

template<class T>
inline TListIterator<T>::TListIterator()
{
	 TList<T> q;
	 list =q;
	 cur = nullptr;
}

template<class T>
inline TListIterator<T>::TListIterator(TList<T>& l, TListNode<T>* p)
{
	list = l;
	cur = p;
}

template<class T>
inline TListIterator<T>::TListIterator(const TListIterator<T>& p)
{
  list = p.list;
	cur = p.cur;
}

template<class T>
inline TListIterator<T>::TListIterator(TListIterator<T>&& p)
{
	list = p.list;
	cur = p.cur;
	p.cur = nullptr;
}

template<class T>
inline TListIterator<T>::~TListIterator()
{
	cur = nullptr;
}

template<class T>
inline TListIterator<T>& TListIterator<T>::operator=(const TListIterator<T>& p)
{
	if (this != &p)
	{
		list = p.list;
		cur = p.cur;
		return *this;
	}
	else return *this;
}

template<class T>
inline TListIterator<T>& TListIterator<T>::operator=(TListIterator<T>&& p)
{
	list = p.list;
	cur = p.cur;
	p.cur = nullptr;
	return *this;
}

template<class T>
inline TListIterator<T>& TListIterator<T>::operator++()
{
	cur = cur->GetNext();
	if (cur == end)
		cur = nullptr;
	return *this;
}

template<class T>
inline TListIterator<T>& TListIterator<T>::operator--()
{
	cur = cur->GetPrev();
	if (cur == end)
		cur = begin;
	return *this;
}

template<class T>
inline bool TListIterator<T>::operator==(const TListIterator<T>& p)
{
	if ((p.cur == cur) && (p.list == list))
		return true;
	return false;
}

template<class T>
inline bool TListIterator<T>::operator!=(const TListIterator<T>& p)
{
	if ((p.cur != cur) && (p.list != list))
		return true;
	return false;
}

template<class T>
inline void TListIterator<T>::PushAfter(T* a)
{
	if (a == nullptr) throw("nullptr pushing");
	TListNode<T>* cat = new TListNode<T>(cur->GetNext(), cur, a);
	cur->SetNext(cat);
	cur->GetNext()->SetPrev(cat);
}

template<class T>
inline void TListIterator<T>::PushBefore(T* a)
{
	if (a == nullptr) throw("nullptr pushing");
	TListNode<T>* cat = new TListNode<T>(cur->GetPrev(), cur, a);
	cur->SetPrev(cat);
	cur->GetPrev()->SetNext(cat);
}

template<class T>
inline TListIterator<T> TListIterator<T>::GetBegin()
{
	return TListIterator<T>(*this, begin);
}

template<class T>
inline TListIterator<T> TListIterator<T>::GetEnd()
{
	return TListIterator<T>(*this, end);
}
