#include <QCoreApplication>
#include "Parser.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Json::Parser * p = new Json::Parser(&a);
	Json::Document * d = p->createDocument();	

	d->root()["qwqw"]["3443"] = 34;
	d->root()["334"] = true;
	d->root()["array"] = 4;
	d->root()["array"] += 5;
	d->root()["array"] += 6;
	d->root()["array"] += "4556";
	
	return a.exec();
}

