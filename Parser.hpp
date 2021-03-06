#ifndef PARSER
# define PARSER

# include "Token.hpp"
# include "Software.hpp"
# include "InstructionInfo.hpp"
# include <vector>
# include <string>
# include <map>
# include "OperandFactory.hpp"
# include "ParserError.hpp"

class Parser
{
	public:
		Parser(void);
		Parser(const Parser &obj);
		Parser &operator=(const Parser &p);
		virtual ~Parser(void);
		void		setTokenLst(const std::vector<Token> &lstToken);
		void		parse(void);
		bool		hasError(void) const;
		Software	&getSoftware(void);
		static std::map<Token::Data, Instruction::InsName>	create_map(void);
		static std::map<Token::Data, eOperandType>	create_map_op(void);
	private:
		static const std::map<Token::Data, Instruction::InsName>	_tokenDataToIns;
		static const std::map<Token::Data, eOperandType>			_tokenDataToOp;

		std::vector<Token>	_tokenLst;
		std::vector<Token>::iterator	_currentPos;
		Software			_prog;
		OperandFactory		_factory;
		bool				_hasError = false;
		int					_lastLineError = -1;

		IOperand const	*_getOpIns(int line);
		void			_processIns(Token const &tok);
		void			_processFirstToken(void);
};
#endif

