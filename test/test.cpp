#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../src/parser.hpp"


TEST_CASE( "Source component can read input" ) {

    Source source;
    char* sample_input = "5+5+5+5";

    REQUIRE( source.read_source(sample_input) == 1 );
    REQUIRE( source.next_char() == 53 );
    REQUIRE( source.next_char() == 43 );
}

TEST_CASE( "Lexer component can parse tokens" ) {

    Source source;
    Lexer lexer = Lexer(&source);
    char* sample_input = "5+5+5+5";
    source.read_source(sample_input);

    REQUIRE( lexer.start() == 1 );
    REQUIRE( lexer.get_token() == 100 );    //100 is the constant indicator for a number
    REQUIRE( lexer.get_lexeme() == 5 );     //the double 5 is the first lexeme
    REQUIRE( lexer.next_token() == 43 );    //43 is the ASCII value for the next token
    REQUIRE( lexer.identify() == 100 );     //Expect an unidentified term to always be a number(assuming no garbage)
}

TEST_CASE( "Parser component can parse tokens" ) {

    Source source;
    Lexer lexer = Lexer(&source);
    Parser parser = Parser(&lexer);
    char* sample_input = "5+5+5+5";
    source.read_source(sample_input);
    lexer.start();

    // These tests are not yet finished
    REQUIRE( parser.expr() != NULL );
}
