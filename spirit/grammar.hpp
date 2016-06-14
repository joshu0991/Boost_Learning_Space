#define BOOST_SPIRIT_USE_PHOENIX_V3
#include <string>
#include <iterator>
#include <iostream>

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

namespace test
{

    void stuff (const char c, std::string& s)
    {
        s.append(&c);
    }

    bool getString(std::string* val)
    {
        namespace bs = boost::spirit;
        bool success = true;
        std::string test;

        bs::qi::parse(val->begin(), val->end(),
            bs::qi::lit("test_") >> 
                +bs::qi::char_(L'0',L'9')[boost::phoenix::bind(stuff, bs::qi::_1, boost::phoenix::ref(test))]);

        std::cout << "The string is " << test << std::endl; 
        return success;
    }

}
