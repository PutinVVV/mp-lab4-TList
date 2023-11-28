#pragma once
#include "TListNode.h"
#include "TListIterator.h"
using namespace std;
template<class T>
class TList
{
protected:
	TListNode<T>* begin;
	TListNode<T>* end;
	int count;
public:
	TList();          //конструктор инициализации и по умолчанию
	~TList();       //деструктор
	TList(const TList<T>& p);      //конструктор копирования 
	TList(TList<T>&& p);
	void Clear();
	void InsFirst(T d); //Вставка элемента
	void InsLast(T d); //Вставка элемента
	void Ins(TListNode<T>* e, T d); //Вставка элемента
	bool IsFull(void) const; // контроль полноты
	bool IsEmpty(void) const; // контроль пустоты
	void DelFirst();
	void DelLast();
	void Del(TListNode<T>* e);
	int GetCount();

};

template<class T>
inline TList<T>::TList()
{
  begin = 0;
  end = 0;
  count = 0;
}

template <class T>
TList<T>::TList(TList<T>& p)
{
  count = p.count;
  TListNode<T>* i = p.begin;
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

template <class T>
TList<T>::~TList()
{
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
}

template <class T>
TList<T>& TList<T>::operator =(TList<T>& p)
{
  if (this == &p)
    return *this;

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

  count = p.count;

  TListNode<T>* i = p.begin;
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

  return *this;
}

template<class T>
inline void TList<T>::InsFirst(T d)
{
  TListNode<T>* temp = new TListNode<T>(d);
  temp->SetNext(begin);
  begin = temp;
  count++;
}

template<class T>
inline void TList<T>::InsLast(T d)
{
  TListNode<T>* temp = new TListNode<T>(d);
  temp->SetNext(end);
  end = temp;
  count++;
}

template<class T>
inline void TList<T>::Ins(TListNode<T>* e, T d)
{
  TListNode<T>* temp = new TListNode<T>(d);
  temp->SetNext(e->GetNext());
  temp->SetPrev(e);
  e->GetNext()->SetPrev(temp);
  e->SetNext(temp);
  count++;
}

template<class T>
inline bool TList<T>::IsFull(void) const
{
  try
  {
    TListNode<T>* temp = new TListNode<T>(1);
    delete temp;

    return false;
  }
  catch (...)
  {
    return true;
  }
}

template<class T>
inline bool TList<T>::IsEmpty(void) const
{
  return count == 0;
}


template<class T>
inline TListNode<T>* TList<T>::GetFirst()
{
  return begin;
}

template<class T>
inline TListNode<T>* TList<T>::GetLast()
{
  return end;
}

template<class T>
inline void TList<T>::DelFirst()
{
  TListNode<T>* i = this->begin;
  begin = begin->GetNext();
  count--;
  delete i;
}

template<class T>
inline void TList<T>::DelLast()
{
  TListNode<T>* i = this->end;
  end = begin->GetPrev();
  count--;
  delete i;
}

template<class T>
inline void TList<T>::Del(TListNode<T>* e)
{
  e->GetPrev()->SetNext(e->GetNext());
  e->GetNext()->SetPrev(e->GetPrev());

  count--;
  delete e;
}

template<class T>
inline int TList<T>::GetCount()
{
  return count;
}

