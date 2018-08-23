#include "Lexer.hpp"

DOF::Lexer::Lexer()
{
	std::cout << static_cast<char>(accept('a')) << std::endl;
}

DOF::Lexer::~Lexer()
{
}

DOF::Token DOF::Lexer::accept(char c)
{
	DOF::Token tk = DOF::Token::NONE;
	switch(c)
	{
		case '{': tk = DOF::Token::LBRACKET_OBJECT; break;
		case '}': tk = DOF::Token::RBRACKET_OBJECT; break;
		case '[': tk = DOF::Token::LBRACKET_ARRAY; break;
		case ']': tk = DOF::Token::RBRACKET_ARRAY; break;
		case ',': tk = DOF::Token::COMMA_ARRAY; break;
		case '"': tk = DOF::Token::QUOTATION_MARK; break;
		case ':': tk = DOF::Token::COLON; break;
		default: ;
	}

	return tk;
}
