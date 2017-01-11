#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QObject>
#include "Element.h"

namespace Json
{

class Document : public QObject
{
	Q_OBJECT
	
	friend class Parser;
	
public:
	Element &root() { return *(__root); }
	~Document();
	
signals:
	
public slots:
	
private:
	explicit Document(QObject *parent = 0);

	Element * __root;
};

}

#endif // DOCUMENT_H
