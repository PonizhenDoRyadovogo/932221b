#pragma once
class Array
{
public:
	Array(const int size = 10, const int value = 0);
	Array(const Array& other);
	~Array();
	void Print()const;
	const int& operator [](const int index) const;
	int& operator [](const int index);
	int size() const;
	Array &operator = (const Array& other);
	Array operator +(const Array& other)const;
	void swap(Array& other);
	Array& operator +=(const Array& other);
private:
	int* m_array = nullptr;
	int m_size = 0;
};

