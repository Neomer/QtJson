#ifndef ELEMENT_H
#define ELEMENT_H

#include <QObject>
#include <Value.h>
#include <QVector>

namespace Json
{

struct Key
{
	int key_int;
	QString key_string;
};


class Element : public QObject
{

	Q_OBJECT
	
	friend class Parser;
	
public:
	explicit Element(QObject *parent = 0);
	explicit Element(const Element &other);
	~Element();
	
	
	const Key &key() const { return __key; }
	const QVariant &value() const { return __value.get(); }
	
	int toInt() const { return __value.get().toInt(); }
	QString toString() const { return __value.get().toString(); }
	const char * toCharArray() const { return __value.get().toString().toLatin1().constData(); }
	
	Element &operator [] (QString key);
	Element &operator [] (const char *key);
	Element &operator [] (int key);
	
	QVariant &operator() (int index) { return __value[index]; }
	
	void operator = (const int value);
	void operator = (const QString &value);
	void operator = (const double value);
	void operator = (const bool value);
	
	void operator = (const Element &value);
	
	void operator += (const int value);
	void operator += (const char *value);
	void operator += (const double value);
	
	operator int()     { return __value.get().toInt();    }
	operator QString() { return __value.get().toString(); }
	operator bool()    { return __value.get().toBool();   }
	
	int count() { return __elements.count(); }
	
signals:
	
public slots:
	
private:
	Key __key;
	Value __value;
	QVector<Element *> __elements;
	QVector<QString> __keys;
};

}

Q_DECLARE_METATYPE(Json::Element)

#endif // ELEMENT_H
