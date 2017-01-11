#include "Document.h"

using namespace Json;

Document::~Document()
{
	delete __root;
}

Document::Document(QObject *parent) : QObject(parent)
{
	
}

