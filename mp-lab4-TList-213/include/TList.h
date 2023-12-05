#include "TListNode.h"
#pragma once
using namespace std;
template<class T>
class TList
{
	friend class ListNode;
protected:
	TListNode<T>* begin;
	TListNode<T>* end;
	int count;
public:
	TList();          //конструктор инициализации и по умолчанию
	TList(const TList<T>& p);
	TList(TList<T>&& p);
	void PushBegin(TListNode<T>* a);
	void PushEnd(TListNode<T>* a);
	void DeleteBegin();
	void DeleteEnd();
	~TList();
	int GetCount();
	TListNode<T>* GetBegin();
	TListNode<T>* GetEnd();
	void Clear();
	void CountP();
	void CountM();
	void DelFirst();
	void DelLast();
	TList<T>& operator=(const TList<T>& p);
	TList<T>& operator=(TList<T>&& p);

};

template<class T>
inline TList<T>::TList()
{
	begin = nullptr;
	end = nullptr;
	count = 0;
}

template<class T>
inline TList<T>::TList(const TList<T>& a)//?????????????????????????????????????????????
{
	if (a.begin != nullptr) {
		if (this->begin != 0)
		{
			TListNode<T>* i = this->begin;
			TListNode<T>* p = 0;
			while (i != 0)
			{
				p = i;
				i = i->GetNext();
				delete p;
			}

			this->begin = 0;
			this->end = 0;
			count = 0;
		}

		count = a.count;

		TListNode<T>* i = a.begin;
		TListNode<T>* j = this->begin;
		TListNode<T>* p = 0;
		while (i != 0)
		{
			j = new TListNode<T>(*i);
			j->SetNext(0);
			if (p != 0)
			{
				p->SetNext(j);
				j->SetPrev(p);
			}
			p = j;

			if (begin == 0)
			{
				begin = j;
			}

			end = j;

			i = i->GetNext();
		}
	}
	else
	{
		begin = nullptr;
		end = nullptr;
		count = 0;
	}
}

template<class T>
inline TList<T>::TList(TList<T>&& p)
{
	if ((data == p.data) && (p.end == end) && (count == p.count))
		data = p.data;
	next = p.next;
	count = p.count;
	p.data = nullptr;
	end = nullptr;
	count = 0;
}

template<class T>
inline void TList<T>::PushBegin(TListNode<T>* a)
{
	a = new TListNode<T>((TListNode<T>*)begin, (TListNode<T>*)end, (T*)a);
	begin = a;
}

template<class T>
inline void TList<T>::PushEnd(TListNode<T>* a)
{
	a = new TListNode<T>((TListNode<T>*)begin, (TListNode<T>*)end, (T*)a);
	end = a;
}

template<class T>
inline void TList<T>::DeleteBegin()
{
	TListNode<T>* a = begin;
	if (begin == nullptr) throw("empty begin");
	end->SetNext(begin->GetNext());
	begin = begin->GetNext();
	begin->SetPrev(end);
	delete a;
}

template<class T>
inline void TList<T>::DeleteEnd()
{
	TListNode<T>* a = end;
	if (end == nullptr) throw("empty end");
	begin->SetPrev(end->GetPrev());
	end = end->GetPrev();
	end->SetNext(begin);
	delete a;
	count--;
}

template<class T>
inline TList<T>::~TList()
{
	Clear();
}

template<class T>
int inline TList<T>::GetCount()
{
	return count;
}

template<class T>
inline TListNode<T>* TList<T>::GetBegin()
{
	return begin;
}

template<class T>
inline TListNode<T>* TList<T>::GetEnd()
{
	return end;
}

template<class T>
inline void TList<T>::Clear()
{
	do 
	{
		DelFirst();
	} while (begin != nullptr);
	do
	{
		DelLast();
	} while (end != nullptr);
	count = 0;
}

template<class T>
inline void TList<T>::CountP()
{
	count++;
}

template<class T>
inline void TList<T>::CountM()
{
	count--;
}

template<class T>
inline TList<T>& TList<T>::operator=(const TList<T>& p)
{
	return TList<T>::TList(p);
}

template<class T>
inline TList<T>& TList<T>::operator=(TList<T>&& p)
{
	if (p == this)
		return this;
	TList<T>::TList(p);
	return *this;
}
template<class T>
inline void TList<T>::DelFirst()
{
	if (begin != nullptr) 
	{
		TListNode<T>* i = this->begin;
		begin = begin->GetNext();
		count--;
		delete i;
	}
}

template<class T>
inline void TList<T>::DelLast()
{
	if (end != nullptr)
	{
		TListNode<T>* i = this->end;
		end = begin->GetPrev();
		count--;
		delete i;
	}
}