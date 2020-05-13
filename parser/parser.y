%{
    #include "json.hpp"
    #include <iostream>
    JsonObject* finished;

    extern int yylex();
    void yyerror(const char *s) {std::cout << "Error! " << s << std::endl; }
%}

%union {
    JsonBool* JBool;
    JsonString* JString;
    JsonObject* JObject;
    JsonPair*   JPair;
    JsonNumber* JNum;
    JsonArray*  Jarray;
    JsonValue*  JVal;
    ValueList*   JValList;
    std::string* string;
    int token;
}

%token <String> TNUMBER TIDENTIFIER TSTRING
%token <token> TLCURL TRCURL TLBRACKET TRBRACKET TCOLON TCOMMA TQUOTE
%token <token> TTRUE TFALSE TNULL

//%type <JBool> bool
//%type <JString> string array
%type <JObject> json
%type <JValList> members
%type <JPair> pair
%type <JVal> elements value object number bool string array
//%type <JNum> number


%%

json: object {finished = $<JObject>1;}
    ;

object: TLCURL members TRCURL {$$ = new JsonObject($2);}
      | TLCURL TRCURL {$$ = new JsonObject();}
      ;

members: /*Blank*/ { $$ = new ValueList();}
       | pair { $$ = new ValueList(); $$->push_back($1);}
       | members TCOMMA pair {$1->push_back($3);}
       ;

pair: string TCOLON value {$$ = new JsonPair($<JString>1, $3); }
    ;

value: number | string | bool | array | object ;

number: TNUMBER { $$ = new JsonNumber();}
      ;

array: TLBRACKET elements TRBRACKET {$$ = new JsonString("Not Implemented!");} 
     | TLBRACKET TRBRACKET {$$ = new JsonString("Not Implemented!");}
     ;

elements: 
        | value
        | elements TCOMMA value ;

string: TSTRING { $$ = new JsonString("Not Implemented!");} /*  */
      | TQUOTE TQUOTE {$$ = new JsonString("");}
      ;


bool: TTRUE     { $$ = new JsonBool(1);}
    | TFALSE    { $$ = new JsonBool(2);}
    | TNULL     { $$ = new JsonBool(3);}
    ;

%%

void scan(const char* str)
{
    yy_switch_to_buffer(yy_scan_string(str));
}