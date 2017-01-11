#ifndef VALUE_H
#define VALUE_H

#include <QObject>
#include <QVariant>
#include <QVector>

namespace Json
{

class Value : public QObject
{
	Q_OBJECT
	
	friend class Parser;
	friend class Element;
	
public:
	explicit Value(QObject *parent = 0);
	explicit Value(const Value &other) : QObject() { __data = other.__data; }
	~Value();
	
	void set(QVariant data, bool append = false);
	const QVariant &get() const { return __data.at(0); }
	QVariant &operator [] (int index);
	const QVariant &at(const int index) const;
	int count() const { return __data.count(); }
	
signals:
	
public slots:
private:
	QVector<QVariant>__data;
};


}

Q_DECLARE_METATYPE(Json::Value)

#endif // VALUE_H
