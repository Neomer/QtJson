#include "Element.h"

using namespace Json;

Element::Element(QObject *parent) : 
	QObject(parent)
{
	
}

Element::~Element()
{
	foreach (Element * e, __elements) 
	{
		delete e;
	}
}

Element::Element(const Element &other) :
	QObject()
{
	 __key = other.__key;
	 __keys = other.__keys;
	 __elements = other.__elements;
	 __value.__data = QVector<QVariant>(other.__value.__data);
}

Element &Element::operator [](int key) 
{ 
	Q_UNUSED(key); 
	
	if (key < __elements.count())
	{
		return *(__elements.at(key));
	}
	else
	{
		Element * e = new Element(this);
		__elements.append(e);
		__keys.append(QString());
		return *e;		
	}
}

void Element::operator =(const QString &value) 
{
	__value.set(QVariant::fromValue(value)); 
}

void Element::operator =(const bool value)
{
	__value.set(QVariant::fromValue(value));
}

void Element::operator +=(const int value)
{
	__value.set(QVariant::fromValue(value), true);
}

void Element::operator +=(const char *value)
{
	__value.set(QVariant::fromValue(QString(value)), true);
}

void Element::operator +=(const double value)
{
	__value.set(QVariant::fromValue(value), true);
}

void Element::operator =(const int value) 
{
	__value.set(QVariant::fromValue(value)); 
}

void Element::operator =(const Element &value) 
{
	__value.set(QVariant::fromValue(value));
}

Element &Element::operator [](QString key)  
{ 
	Q_UNUSED(key); 
	Q_ASSERT(!key.isEmpty());
	
	int idx;
	for (idx = 0; idx < __keys.count(); idx++)
	{
		if ((__keys.at(idx) == key)&&(!__keys.at(idx).isEmpty()))
			break;
	}
	
	if (idx < __keys.count())
	{
		return *(__elements.at(idx));
	}
	else
	{
		Element * e = new Element(this);
		__keys.append(key);
		__elements.append(e);
		return *e;		
	}
}

Element &Element::operator [](const char *key)
{
	Q_UNUSED(key);
	Q_ASSERT(strcmp(key, ""));
	
	int idx;
	for (idx = 0; idx < __keys.count(); idx++)
	{
		if ((__keys.at(idx) == key)&&(!__keys.at(idx).isEmpty()))
			break;
	}
	
	if (idx < __keys.count())
	{
		return *(__elements.at(idx));
	}
	else
	{
		Element * e = new Element(this);
		__keys.append(key);
		__elements.append(e);
		return *e;		
	}
}

