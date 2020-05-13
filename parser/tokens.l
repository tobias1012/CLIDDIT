%{
    #include "parse.yy.hpp"
    #include <string>
    #define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
%}

%option noinput nounput noyywrap

%%
 
"null"          {return TNULL;}
"true"          {return TTRUE;}
"false"         {return TFALSE;}
[0-9]+"."[0-9]+ {SAVE_TOKEN; return TNUMBER;}
[0-9]+          {SAVE_TOKEN; return TNUMBER;}
\"(\\.|[^\"])*\"      {SAVE_TOKEN; return TSTRING;}
    /*Structural Chars*/
"{"             {return TLCURL;}
"}"             {return TRCURL;}
"["             {return TLBRACKET;}
"]"             {return TRBRACKET;}
":"             {return TCOLON;}
","             {return TCOMMA;}
    /*"\""            {return TQUOTE;}*/
[ \t\n]         { /*Ignore Whitespaces*/}
.               {yyerror(yylval.string->c_str()); }

%% 