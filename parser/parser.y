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
    PairList*   JPairList;
    ValueList*  JValList;
    std::string* string;
    int token;
}

%token <string> TNUMBER TIDENTIFIER TSTRING
%token <token> TLCURL TRCURL TLBRACKET TRBRACKET TCOLON TCOMMA TQUOTE
%token <token> TTRUE TFALSE TNULL

%type <JObject> json
%type <JValList> elements
%type <JPairList> members 
%type <JPair> pair
%type <JVal> value object number bool string array



%%

json: object {finished = $<JObject>1;}
    ;

object: TLCURL members TRCURL {$$ = new JsonObject($2);}
      | TLCURL TRCURL {$$ = new JsonObject();}
      ;

members: /*Blank*/ { $$ = new PairList();}
       | pair { $$ = new PairList(); $$->push_back($1);}
       | members TCOMMA pair {$1->push_back($3);}
       ;

pair: string TCOLON value {$$ = new JsonPair($<JString>1, $3); }
    ;

value: number | string | bool | array | object ;

number: TNUMBER { $$ = new JsonNumber();}
      ;

array: TLBRACKET elements TRBRACKET {$$ = new JsonArray($2);} 
     | TLBRACKET TRBRACKET {$$ = new JsonArray();}
     ;

elements: /* Blank */  {$$ = new ValueList();}
        | value     { $$ = new ValueList(); $$->push_back($1);}
        | elements TCOMMA value {$1->push_back($3);}
        ;

string: TSTRING { $$ = new JsonString($1);}
      | TQUOTE TQUOTE {$$ = new JsonString();}
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