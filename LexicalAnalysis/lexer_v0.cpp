	#include <iostream>
	#include <vector>
	#include <cctype>

	enum class TokenType {
	    INTEGER,
	    PLUS,
	    MINUS,
	    MULTIPLY,
	    DIVIDE,
	    LPAREN,
	    RPAREN,
	    END_OF_INPUT
	};

	struct Token {
	    TokenType type;
	    std::string value;
	};

	class Lexer {
	public:
	    Lexer(const std::string& input) : input(input), currentPos(0) {}

	    Token getNextToken() {
		while (currentPos < input.length()) {
		    char currentChar = input[currentPos];

		    if (isspace(currentChar)) {
		        // Skip whitespace
		        currentPos++;
		        continue;
		    }

		    if (isdigit(currentChar)) {
		        // Parse integers
		        return parseInteger();
		    }

		    switch (currentChar) {
		        case '+':
		            currentPos++;
		            return Token{TokenType::PLUS, "+"};
		        case '-':
		            currentPos++;
		            return Token{TokenType::MINUS, "-"};
		        case '*':
		            currentPos++;
		            return Token{TokenType::MULTIPLY, "*"};
		        case '/':
		            currentPos++;
		            return Token{TokenType::DIVIDE, "/"};
		        case '(':
		            currentPos++;
		            return Token{TokenType::LPAREN, "("};
		        case ')':
		            currentPos++;
		            return Token{TokenType::RPAREN, ")"};
		        default:
		            std::cerr << "Error: Invalid character '" << currentChar << "' at position " << currentPos << std::endl;
		            exit(EXIT_FAILURE);
		    }
		}

		// Return token indicating end of input
		return Token{TokenType::END_OF_INPUT, ""};
	    }

	private:
	    Token parseInteger() {
		std::string value;
		while (currentPos < input.length() && isdigit(input[currentPos])) {
		    value += input[currentPos];
		    currentPos++;
		}
		return Token{TokenType::INTEGER, value};
	    }

	    std::string input;
	    std::size_t currentPos;
	};

	int main() {
	    std::string inputExpression = "3 + 4 * ( 2 - 1 ) / 5";

	    Lexer lexer(inputExpression);

	    Token token = lexer.getNextToken();
	    while (token.type != TokenType::END_OF_INPUT) {
		std::cout << "Type: " << static_cast<int>(token.type) << ", Value: " << token.value << std::endl;
		token = lexer.getNextToken();
	    }

	    return 0;
	}
