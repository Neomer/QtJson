#ifndef PARSER_H
#define PARSER_H

#include <QObject>
#include <Document.h>

namespace Json
{

class Parser : public QObject
{
	Q_OBJECT
public:
	explicit Parser(QObject *parent = 0);
	
	Document *createDocument();
	
	QByteArray toJSONString(Document *doc);
	QByteArray toBytea(Document *doc);
	
	
signals:
	
public slots:
	
private:
	QByteArray toJsonArray(const Element *e, bool rec = false);
	QByteArray toJsonObject(const Element *e, bool rec = false);
	QString formatValue(const QVariant &value);
	
	struct JsonHead
	{
		
	};
	
};

}

#endif // PARSER_H
