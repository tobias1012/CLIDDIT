%{
    extern int yylex();
    void yyerror(const char *s) {;}
%}

%token TNULL
%token TTRUE TFALSE
%token TNUMBER TIDENTIFIER
%token TLCURL TRCURL TLBRACKET TRBRACKET TCOLON TCOMMA

%union {
    int token;
}

%%

value: TNUMBER ;

%%