#include <iostream>

#include "Object.hpp"
#include "Value.hpp"
#include "Lexer.hpp"

int main()
{
	DOF::Lexer lexer;
	DOF::Object obj;
	DOF::Object obj2;
	DOF::Object obj3;

	obj3.Set("INT", DOF::int_v(3));
	obj3.Set("REAL", DOF::real_v(3.424242f));
	obj3.Set("BOOL", DOF::bool_v(true));
	obj3.Set("STRING", DOF::string_v("MY STRING 3"));
	obj2.Set("INT", DOF::int_v(2));
	obj2.Set("REAL", DOF::real_v(2.424242f));
	obj2.Set("BOOL", DOF::bool_v(false));
	obj2.Set("STRING", DOF::string_v("MY STRING 2"));
    obj2.Set("OBJECT 2", &obj3);
	obj.Set("INT", DOF::int_v(1));
	obj.Set("REAL", DOF::real_v(1.424242f));
	obj.Set("BOOL", DOF::bool_v(true));
	obj.Set("STRING", DOF::string_v("MY STRING 1"));
    obj.Set("OBJECT 1", &obj2);


	std::cout << obj.Serialize() << std::endl;
	std::cout << obj.GetObject("OBJECT 1").GetObject("OBJECT 2").GetInt("INT") << std::endl;
    return 0;
}
