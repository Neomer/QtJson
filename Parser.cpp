#include "Parser.h"

using namespace Json;

Parser::Parser(QObject *parent) : QObject(parent)
{
	
}

Document *Parser::createDocument() 
{ 
	Document * d = new Document(this); 
	d->__root = new Element(this); 
	return d; 
}

QByteArray Parser::toJSONString(Document *doc)
{
	Q_ASSERT(doc != 0);
	
	QByteArray ret;
	
	if (doc->root().__value.count())
	{
		ret.append(QString("[%1]").arg(
					   QString(toJsonArray((doc->__root), true))));		
	}
	else
	{
		ret.append(QString("{%1}").arg(
					   QString(toJsonObject((doc->__root), true))));		
	}
	return ret;
}

QByteArray Parser::toBytea(Document *doc)
{
	Q_ASSERT(doc != 0);
	
	QByteArray ret;
	
	return ret;	
}

QByteArray Parser::toJsonArray(const Element *element, bool rec)
{
	QByteArray ret;

	if (rec)
	{
		if (element->__elements.count())
		{
			for (int idx = 0; idx < element->__elements.count(); idx++)
			{
				Element * e = element->__elements.at(idx);
				
				ret.append(QString("\"%1\": {%2},").arg(
							   e->__keys.at(idx),
							   QString(toJsonObject(e))));
			}
		}
	}
	
	for (int v = 0; v < element->__value.__data.count(); v++)
	{
		QVariant value = element->__value.__data.at(v);
		ret.append(formatValue(value));
		if (element->__value.__data.count() - v > 1)
		{
			ret.append(",");
		}
	}
	return ret;
}

QByteArray Parser::toJsonObject(const Element *element, bool rec)
{
	Q_UNUSED(rec);
	
	QByteArray ret;

	for (int i = 0; i < element->__elements.count(); i++)
	{
		Element * e = element->__elements.at(i);
		QString k = element->__keys.at(i);
		
		ret.append(QString("\"%1\": ").arg(k));
		if (e->__value.count() == 1)
		{
			ret.append(QString("%2,").arg(
						   formatValue(e->__value.at(0))));
		}	
		else if ((e->__value.count() > 1)&&(rec))
		{
			ret.append(QString("[%2],").arg(
						   QString(toJsonArray(e))));
		}
		if (e->__elements.count() > 0)
		{
			ret.append(QString("{%2},").arg(
						   QString(toJsonObject(e))));
		}
	}

	return ret.left(ret.length() - 1);
}

QString Parser::formatValue(const QVariant &value)
{
	switch (value.type())
	{
		case QVariant::Double : case QVariant::Int : case QVariant::UInt : case QVariant::Bool :
			return QString("%1").arg(value.toString());
			break;

		case QVariant::String:
			return QString("\"%1\"").arg(value.toString());
			break;
			
		default:
			qDebug("Unsupported format! %d", value.type());
			return "null";
			break;
	}
}

