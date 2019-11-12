#include"MapObject.h"

MapObject::MapObject(TiXmlElement *node, string name)
{
	this->ReadXML(node, name);
}
MapObject::~MapObject()
{

}
RECT MapObject::getBound()
{
	RECT r;
	r.left = this->x;
	r.right = this->x + this->width;
	r.top = this->y;
	r.bottom = this->y + this->height;
	return r;
}
void MapObject::ReadXML(TiXmlElement *node, string name)
{
	this->name = name;
	node->QueryIntAttribute("id", &id);
	node->QueryFloatAttribute("x", &x);
	node->QueryFloatAttribute("y", &y);
	node->QueryFloatAttribute("width", &width);
	node->QueryFloatAttribute("height", &height);
}