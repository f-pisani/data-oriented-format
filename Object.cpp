#include "Object.hpp"

DOF::Object::Object() :
	int_(), real_(), bool_(), string_(), object_()
{

}

DOF::Object::Object(const DOF::Object& obj) :
	int_(obj.int_), real_(obj.real_), bool_(obj.bool_), string_(obj.string_), object_(obj.object_)
{
	int_ = obj.int_;
	real_ = obj.real_;
	bool_ = obj.bool_;
	string_ = obj.string_;
	object_ = obj.object_;
}

DOF::Object::~Object()
{

}

DOF::Object DOF::Object::GetObject(std::string key)
{
	if(object_.count(key))
		return *object_[key];
	else
		return DOF::Object();
}

std::string DOF::Object::Serialize(int deep)
{
	// Indenting
	std::function<void(std::string&,int)> bufferIndenting(
	[](std::string& str, int tab){
		for(int i=0; i<tab; ++i)
			str += "\t";
	});

	std::string buffer("{\r\n");
    for(auto it : int_)
	{
		bufferIndenting(buffer, deep);
		std::string key(it.first);
		std::string data(it.second.Str());
		buffer += std::string("\"" + key + "\" : " + data + "\r\n");
	}

    for(auto it : real_)
	{
		bufferIndenting(buffer, deep);
		std::string key(it.first);
		std::string data(it.second.Str());
		buffer += std::string("\"" + key + "\" : " + data + "\r\n");
	}

    for(auto it : bool_)
	{
		bufferIndenting(buffer, deep);
		std::string key(it.first);
		std::string data(it.second.Str());
		if(it.second.Get())
			buffer += std::string("\"" + key + "\" : true\r\n");
		else
			buffer += std::string("\"" + key + "\" : false\r\n");
	}

    for(auto it : string_)
	{
		bufferIndenting(buffer, deep);
		std::string key(it.first);
		std::string data(it.second.Str());
		buffer += std::string("\"" + key + "\" : \"" + data + "\"\r\n");
	}

    for(auto it : object_)
	{
		bufferIndenting(buffer, deep);
		bufferIndenting(buffer, deep);
		std::string key(it.first);
		std::string data(it.second->Serialize(deep+1));
		buffer += std::string("\"" + key + "\" : " + data + "\r\n");
	}

	bufferIndenting(buffer, deep);
	buffer += "}\r\n";

	return buffer;
}

void DOF::Object::Deserialize(std::string buffer)
{

	bool lookingForSymbols(true);
	bool lookingForName(false);
	bool lookingForValue(false);
	for(size_t i=0; i<buffer.size(); ++i)
	{

	}
}

DOF::Symbol DOF::Object::GetSymbol(char c)
{

}
