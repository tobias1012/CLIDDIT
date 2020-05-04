#pragma once

namespace Tokenizer
{

    

    class Token
    {
    public:
        enum TokenTypes
        {
            lBracket,
            rBracket,
            lCurly,
            rCurly,
            colon,
            comma,
            dot,
            boolean,
            null,
            number,
            string
        };

    };

};