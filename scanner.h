//
// Created by th3oth3rjak3 on 5/19/25.
//

#ifndef SCANNER_H
#define SCANNER_H

typedef enum {
    // Single-character tokens.
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
    TOKEN_LEFT_BRACE,
    TOKEN_RIGHT_BRACE,
    TOKEN_COMMA,
    TOKEN_DOT,
    TOKEN_MINUS,
    TOKEN_PLUS,
    TOKEN_SEMICOLON,
    TOKEN_SLASH,
    TOKEN_STAR,
    // One or two character tokens.
    TOKEN_BANG,
    TOKEN_BANG_EQUAL,
    TOKEN_EQUAL,
    TOKEN_EQUAL_EQUAL,
    TOKEN_GREATER,
    TOKEN_GREATER_EQUAL,
    TOKEN_LESS,
    TOKEN_LESS_EQUAL,
    // Literals.
    TOKEN_IDENTIFIER,
    TOKEN_STRING,
    TOKEN_NUMBER,
    // Keywords.
    TOKEN_AND,
    TOKEN_CLASS,
    TOKEN_ELSE,
    TOKEN_FALSE,
    TOKEN_FOR,
    TOKEN_FUN,
    TOKEN_IF,
    TOKEN_NIL,
    TOKEN_OR,
    TOKEN_PRINT,
    TOKEN_RETURN,
    TOKEN_SUPER,
    TOKEN_THIS,
    TOKEN_TRUE,
    TOKEN_VAR,
    TOKEN_WHILE,

    TOKEN_ERROR,
    TOKEN_EOF
} TokenType;

/**
 * @brief A token from the source code to be interpreted.
 */
typedef struct {
    /**
     * @brief The specific type of token.
     */
    TokenType type;
    /**
     * @brief The pointer to the start of the lexeme.
     */
    const char *start;
    /**
     * @brief The length of the token lexeme.
     */
    int length;
    /**
     * @brief The line of source code the token was found on.
     */
    int line;
} Token;

/**
 * @brief Create a new scanner with a reference to the source code.
 * @param source The source code that will be interpreted.
 */
void initScanner(const char *source);

/**
 * @brief Scan until the next token is read.
 * @return The next scanned token.
 */
Token scanToken();

#endif //SCANNER_H
