%{
    #include "parse.yy.hpp"
%}

%option noinput nounput noyywrap

%%

"null"          {return TNULL;}
"true"          {return TTRUE;}
"false"         {return TFALSE;}
[0-9]+\.[0-9]+  {return TNUMBER;}
[0-9]+          {return TNUMBER;}
[a-zA-Z0-9]+    {return TIDENTIFIER;}
    /*Structural Chars*/
"{"             {return TLCURL;}
"}"             {return TRCURL;}
"["             {return TLBRACKET;}
"]"             {return TRBRACKET;}
":"             {return TCOLON;}
","             {return TCOMMA;}
"\""            {return TQUOTE;}
[ \t\n]         { /*Ignore Whitespaces*/}
.               {yyerror("Token not recognized!"); }

%%