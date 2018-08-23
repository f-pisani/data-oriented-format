#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include <iostream>
#include <functional>
#include <stack>
#include <unordered_map>

#include "Value.hpp"

namespace DOF
{
	enum class Symbol : char {

	};

	class Object
	{
		DOF::Symbol GetSymbol(char c);

		std::unordered_map<std::string, DOF::int_v> int_;
		std::unordered_map<std::string, DOF::real_v> real_;
		std::unordered_map<std::string, DOF::bool_v> bool_;
		std::unordered_map<std::string, DOF::string_v> string_;
		std::unordered_map<std::string, DOF::Object*> object_;

		public:
			Object();
			Object(const DOF::Object& obj);
			~Object();
			inline void Set(std::string key, DOF::int_v data){ int_[key] = data; }
			inline void Set(std::string key, DOF::real_v data){ real_[key] = data; }
			inline void Set(std::string key, DOF::bool_v data){ bool_[key] = data; }
			inline void Set(std::string key, DOF::string_v data){ string_[key] = data; }
			inline void Set(std::string key, DOF::Object* data){ object_[key] = data; }

			inline DOF::int_v GetInt(std::string key){ return int_[key]; }
			inline DOF::real_v GetReal(std::string key){ return real_[key]; }
			inline DOF::bool_v GetBool(std::string key){ return bool_[key]; }
			inline DOF::string_v GetString(std::string key){ return string_[key]; }
			DOF::Object GetObject(std::string key);

			std::string Serialize(int deep=0);
			void Deserialize(std::string buffer);
	};
}

#endif // OBJECT_HPP_INCLUDED
