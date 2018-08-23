#ifndef LEXER_HPP_INCLUDED
#define LEXER_HPP_INCLUDED

#include <iostream>

namespace DOF
{
	enum class Token : char
	{
		LBRACKET_OBJECT = '{',
		RBRACKET_OBJECT = '}',
		LBRACKET_ARRAY = '[',
		RBRACKET_ARRAY = ']',
		COMMA_ARRAY = ',',
		QUOTATION_MARK = '"',
		COLON = ':',
		NONE = 0
	};

	class Lexer
	{
		public:
			Lexer();
			~Lexer();

		private:
			static Token accept(char c);
	};
}

#endif // LEXER_HPP_INCLUDED
