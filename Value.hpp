#ifndef VALUE_HPP_INCLUDED
#define VALUE_HPP_INCLUDED

#include <iostream>
#include <sstream>

namespace DOF
{
	template <typename Type>
	class Value
	{
		public:
			Value();
			Value(Type value);
			operator Type();
			virtual ~Value();
			Value& operator=(Type data);
			Value& operator+=(Type data);
			Value& operator-=(Type data);
			Value& operator*=(Type data);
			Value& operator/=(Type data);
			Value& operator%=(Type data);

			Value operator+(Type data);
			Value operator-(Type data);
			Value operator*(Type data);
			Value operator/(Type data);
			Value operator%(Type data);

			Value& operator++();
			Value& operator--();
			Value operator++(int);
			Value operator--(int);

			bool operator==(Type data);
			bool operator!=(Type data);
			bool operator<=(Type data);
			bool operator>=(Type data);
			bool operator<(Type data);
			bool operator>(Type data);

			inline void Set(Type data){ data_ = data; }
			inline Type Get(){ return data_; }
			std::string Str();

		protected:
			Type data_;
	};

	using int_v = Value<int>;
	using real_v = Value<float>;
	using bool_v = Value<bool>;
	using string_v = Value<std::string>;
}

/***************************************************************
* PUBLIC TEMPLATE METHODS
***************************************************************/
template <typename Type>
DOF::Value<Type>::Value() :
	data_()
{

}

template <typename Type>
DOF::Value<Type>::Value(Type value) :
	data_(value)
{

}

template <typename Type>
DOF::Value<Type>::operator Type()
{
	return data_;
}

template <typename Type>
DOF::Value<Type>::~Value()
{

}


/***************************************************************
* PUBLIC TEMPLATE METHODS OPERATOR
***************************************************************/
template <typename Type>
DOF::Value<Type>& DOF::Value<Type>::operator=(Type data)
{
	data_ = data;
	return *this;
}

template <typename Type>
DOF::Value<Type>& DOF::Value<Type>::operator+=(Type data)
{
	data_ += data;
	return *this;
}

template <typename Type>
DOF::Value<Type>& DOF::Value<Type>::operator-=(Type data)
{
	data_ -= data;
	return *this;
}

template <typename Type>
DOF::Value<Type>& DOF::Value<Type>::operator*=(Type data)
{
	data_ *= data;
	return *this;
}

template <typename Type>
DOF::Value<Type>& DOF::Value<Type>::operator/=(Type data)
{
	data_ /= data;
	return *this;
}

template <typename Type>
DOF::Value<Type>& DOF::Value<Type>::operator%=(Type data)
{
	data_ %= data;
	return *this;
}

template <typename Type>
DOF::Value<Type>& DOF::Value<Type>::operator++()
{
	++data_;
	return *this;
}

template <typename Type>
DOF::Value<Type>& DOF::Value<Type>::operator--()
{
	--data_;
	return *this;
}

template <typename Type>
DOF::Value<Type> DOF::Value<Type>::operator++(int)
{
	data_++;
	return *this;
}

template <typename Type>
DOF::Value<Type> DOF::Value<Type>::operator--(int)
{
	data_--;
	return *this;
}

template <typename Type>
DOF::Value<Type> DOF::Value<Type>::operator+(Type data)
{
	return DOF::Value<Type>(data_+data);
}

template <typename Type>
DOF::Value<Type> DOF::Value<Type>::operator-(Type data)
{
	return DOF::Value<Type>(data_-data);
}

template <typename Type>
DOF::Value<Type> DOF::Value<Type>::operator*(Type data)
{
	return DOF::Value<Type>(data_*data);
}

template <typename Type>
DOF::Value<Type> DOF::Value<Type>::operator/(Type data)
{
	return DOF::Value<Type>(data_/data);
}

template <typename Type>
DOF::Value<Type> DOF::Value<Type>::operator%(Type data)
{
	return DOF::Value<Type>(data_%data);
}

template <typename Type>
bool DOF::Value<Type>::operator==(Type data)
{
	return (data_==data);
}

template <typename Type>
bool DOF::Value<Type>::operator!=(Type data)
{
	return (data_!=data);
}

template <typename Type>
bool DOF::Value<Type>::operator<=(Type data)
{
	return (data_<=data);
}

template <typename Type>
bool DOF::Value<Type>::operator>=(Type data)
{
	return (data_>=data);
}

template <typename Type>
bool DOF::Value<Type>::operator<(Type data)
{
	return (data_<data);
}

template <typename Type>
bool DOF::Value<Type>::operator>(Type data)
{
	return (data_>data);
}

template <typename Type>
std::string DOF::Value<Type>::Str()
{
	std::stringstream ss;
	ss << data_;

	return ss.str();
}

#endif // VALUE_HPP_INCLUDED

