%{
    #include "json.hpp"

    extern int yylex();
    void yyerror(const char *s) {;}
%}

%union {
    JsonBool* Bool;
    JsonString* String;
    int token;
}

%token TNULL
%token TTRUE TFALSE
%token TNUMBER TIDENTIFIER
%token TLCURL TRCURL TLBRACKET TRBRACKET TCOLON TCOMMA TQUOTE

%type <Bool> bool
%type <String> string

%%

json: object ; 

object: TLCURL members TRCURL ;

members: pair
        | members TCOMMA pair;

pair: string TCOLON value;

value: TNUMBER | string | bool | array | object;

array: TLBRACKET elements TRBRACKET     ;

elements: value
        | elements TCOMMA value;

string: TQUOTE TIDENTIFIER TQUOTE { $$ = new JsonString("Not Implemented!"); } /*  */
      ;

bool: TTRUE     { $$ = new JsonBool(true);}
    | TFALSE    { $$ = new JsonBool(false);}
    | TNULL     { $$ = new JsonBool(NULL);}
    ;

%%