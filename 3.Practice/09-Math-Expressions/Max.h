#pragma once
#include <iostream>
#include <vector>

#include "Constant.h"
#include "MathExpression.h"

template<typename T>
class Max : public MathExpression<T>
{
public:
	Max();

	virtual MathExpression<T>* clone() const override;

	virtual T value() const override;

	virtual void addExpression(MathExpression<T>* expression);
private:
	std::vector<MathExpression<T>*> expressions;
};

template<typename T>
inline Max<T>::Max()
{
}

template<typename T>
inline MathExpression<T>* Max<T>::clone() const
{
	return new Max<T>(*this);
}

template<typename T>
inline T Max<T>::value() const
{
	T max = 0;
	for (size_t i = 0; i < this->expressions.size(); i++)
	{
	 	if (this->expressions[i]->value() > max)
	 	{
	 		max = this->expressions[i]->value();
	 	}
	}

	return max;
}

template<typename T>
inline void Max<T>::addExpression(MathExpression<T>* expression)
{
	if (this->expressions.size() >= MAX_LENGTH)
	{
		std::cout << "Container is full!\n";
		return;
	}

	expressions.push_back(expression);
}
