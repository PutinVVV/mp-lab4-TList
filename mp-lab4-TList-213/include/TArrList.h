#pragma once
using namespace std;
template<class T>
class TArrList
{
protected:
	double* data;
	int* index;
	int count;
	int size;
	int begin;
public:
	TArrList(int _s = 1);
	TArrList(const TArrList&& p);
	~TArrList();
	void PushBegin(double a);
	void PushEnd(double a);
	void PushAfter(int i, double a);
	void DelBegin();
	void DelEnd();
	void Del(int i);
	double GetBegin();
	double GetEnd();
	double Get(int i);

};

template<class T>
TArrList<T>::TArrList(int _s) {
  size = _s;
  data = new double[size];
  index = new int[size];
  count = 0;
  begin = 0;
}

template<class T>
TArrList<T>::TArrList(const TArrList&& p) {
  size = p.size;
  data = new double[size];
  index = new int[size];
  count = p.count;
  begin = p.begin;
  for (int i = 0; i < count; i++) {
    data[i] = p.data[i];
    index[i] = p.index[i];
  }
}

template<class T>
TArrList<T>::~TArrList() {
  delete[] data;
  delete[] index;
}

template<class T>
void TArrList<T>::PushBegin(double a) {
  if (count >= size) {
    int newSize = size * 2;
    double* newData = new double[newSize];
    int* newIndex = new int[newSize];
    for (int i = 0; i < count; i++) {
      newData[i] = data[i];
      newIndex[i] = index[i];
    }
    delete[] data;
    delete[] index;
    data = newData;
    index = newIndex;
    size = newSize;
  }
  begin = (begin - 1 + size) % size;
  data[begin] = a;
  index[begin] = count;
  count++;
}

template<class T>
void TArrList<T>::PushEnd(double a) {
  if (count >= size) {
    int newSize = size * 2;
    double* newData = new double[newSize];
    int* newIndex = new int[newSize];
    for (int i = 0; i < count; i++) {
      newData[i] = data[i];
      newIndex[i] = index[i];
    }
    delete[] data;
    delete[] index;
    data = newData;
    index = newIndex;
    size = newSize;
  }
  data[(begin + count) % size] = a;
  index[(begin + count) % size] = count;
  count++;
}

template<class T>
void TArrList<T>::PushAfter(int i, double a) {
  if (i <= count) {
    if (count >= size) {
      int newSize = size * 2;
      double* newData = new double[newSize];
      int* newIndex = new int[newSize];
      for (int j = 0; j < count; j++) {
        newData[j] = data[j];
        newIndex[j] = index[j];
      }
      delete[] data;
      delete[] index;
      data = newData;
      index = newIndex;
      size = newSize;
    }
    int insertIndex = (begin + index[i]) % size;
    for (int j = count; j > i; j--) {
      data[(begin + index[j - 1] + 1) % size] = data[(begin + index[j - 1]) % size];
      index[j] = index[j - 1] + 1;
    }
    data[insertIndex] = a;
    index[i] = insertIndex;
    count++;
  }
}

template<class T>
void TArrList<T>::DelBegin() {
  if (count > 0) {
    begin = (begin + 1) % size;
    count--;
  }
  else throw  ("error");
}

template<class T>
void TArrList<T>::DelEnd() {
  if (count > 0) {
    count--;
  }
  else throw  ("error");
}

template<class T>
void TArrList<T>::Del(int i) {
  if (i >= 0 && i < count) {
    int deleteIndex = (begin + index[i]) % size;
    for (int j = i; j < count - 1; j++) {
      data[(begin + index[j] + 1) % size] = data[(begin + index[j + 1]) % size];
      index[j] = index[j + 1] - 1;
    }
    count--;
  }
  else throw  ("error");
}

template<class T>
double TArrList<T>::GetBegin() {
  return data[begin];
}

template<class T>
double TArrList<T>::GetEnd() {
  return data[(begin + count - 1) % size];
}

template<class T>
double TArrList<T>::Get(int i) {
  if (i >= 0 && i < count) {
    return data[(begin + index[i]) % size];
  }
  throw("error");
}