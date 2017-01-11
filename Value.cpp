#include "Value.h"

using namespace Json;

Value::Value(QObject *parent) : QObject(parent)
{
	
}

Value::~Value()
{
	
}

void Value::set(QVariant data, bool append) 
{
	if ((append)||(__data.count() == 0))
	{
		__data.append(data);
	}
	else
	{
		__data[0] = data; 
	}
}

QVariant &Value::operator [](int index)
{
	Q_ASSERT(index < __data.count());
	Q_ASSERT(index >= 0);
	
	return __data[index];
}

const QVariant &Value::at(const int index) const
{
	Q_ASSERT(index < __data.count());
	Q_ASSERT(index >= 0);
	
	return __data.at(index);
}

