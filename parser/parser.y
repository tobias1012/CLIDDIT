%{
    extern int yylex();
    void yyerror(const char *s) {;}
%}

%token TNULL
%token TTRUE TFALSE
%token TNUMBER TIDENTIFIER
%token TLCURL TRCURL TLBRACKET TRBRACKET TCOLON TCOMMA TQUOTE

%union {
    int token;
}

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

string: TQUOTE TIDENTIFIER TQUOTE ;

bool: TTRUE
    | TFALSE
    | TNULL   ;

%%