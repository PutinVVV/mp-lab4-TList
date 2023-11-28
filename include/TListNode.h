
#pragma once
	using namespace std;
	template<class T>
	class TListNode
	{
		friend class List;
	protected:
		T* data;
		TListNode<T>* next;
		TListNode<T>* prev;
	public:
		TListNode();          //конструктор инициализации и по умолчанию
		TListNode(TListNode<T>* n,TListNode<T>* p,T* d);
		~TListNode();       //деструктор
		TListNode(const TListNode<T>& p);      //конструктор копирования 
		TListNode(TListNode<T>&& p);
		TListNode<T>* GetNext();
		TListNode<T>* GetPrev();
		T* GetData();
		void SetNext(TListNode<T>* n);
		void SetPrev(TListNode<T>* p);
		void SetData(T* A);
		TListNode& operator=(const TListNode& p);
	};

	template<class T>
	inline TListNode<T>::TListNode()
	{
		data = nullptr;
		next = nullptr;
		prev = nullptr;
	}

	template<class T>
	inline TListNode<T>::TListNode(TListNode<T>* n, TListNode<T>* p, T* d)
	{
		data = d;
		prev = p;
		next = n;
	}

	template<class T>
	inline TListNode<T>::~TListNode()
	{
		next = 0;
		prev = 0;
		delete[]data;
	}

	template<class T>
	inline TListNode<T>::TListNode(const TListNode<T>& p)
	{
		next = p.next;
		data = p.data;
		prev = p.prev;
	}

	template<class T>
	inline TListNode<T>::TListNode(TListNode<T>&& p)
	{
		next = p.next;
		data = p.data;
		prev = p.prev;
		p.data = 0;
		p.next = 0;
		p.prev = 0;
	}

	template<class T>
	inline TListNode<T>* TListNode<T>::GetNext()
	{
		if (next = nullptr) throw("nullptr next");
		return next;
	}

	template<class T>
	inline TListNode<T>* TListNode<T>::GetPrev()
	{
		return prev;
	}

	template<class T>
	inline T* TListNode<T>::GetData()
	{
		return data;
	}

	template<class T>
	inline void TListNode<T>::SetNext(TListNode<T>* n)
	{
		next = n;
	}

	template<class T>
	inline void TListNode<T>::SetPrev(TListNode<T>* p)
	{
		prev = p;
	}

	template<class T>
	inline void TListNode<T>::SetData(T* p)
	{
		data = p;
	}

	template<class T>
	inline TListNode<T>& TListNode<T>::operator=(const TListNode& p)
	{
		prev = p.prev;
		next = p.prev;
		data = p.data;
		return*this;
	}
