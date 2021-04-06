//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include <string>
#include "catch.hpp"
using Catch::Matchers::Equals;
//------------------------------

// Fix the following class
class Complex {
  public:
  Complex() {
    this->re = 0;
    this->im = 0;
  }
  Complex(int re, int im) {
    this->re = re;
    this->im = im;

  }
  int getRE() {
    return re;
  }
  int getIM() {
    return im;
  }
   private: 
  int re, im;
};
  
  
  void operator>>(std::string& s) const

  {
     s.append(std::to_string(this->re));
        if (this->im > 0)
        {
                s.append("+");
                
        }
         s.append(std::to_string(this->im));
        s.append("i");
        }

  void operator<<(const std::string& s);
  {
     if (s[0] == '-')
        {
                int re = s[1] - '0';
                this->re = -1 * re;

        }
        else
        {
                this->re = s[0] - '0'; //converting char to int;
        }

        int ipos = s.find("i");
        int bpos = ipos - 1;
        int bsignpos = ipos - 2;
        if (s[bsignpos] == '-')
        {
                this->im = -1 * (s[bpos] - '0');
        }
        else
        {
                this->im = s[bpos] - '0';
        }
  }
  
#include <iostream>
#include "catch.hpp"

int main()
{
    Complex c;
    std::cout << c.re() << c.re() << std::endl;
    std::string s = "-1-1i";
    c << s;
    std::cout << c.re() << c.re()<<std::endl;
    std::string s2 = "";
    c >> s2;
    std::cout << s2 << std::endl;
}


//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Complex c;
        REQUIRE( c.re() == 0 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c2" ) {
        Complex c{1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c3" ) {
        Complex c{1,1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "o1" ) {
        Complex c; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("0+0i") );
    }
    SECTION( "o2" ) {
        Complex c{1, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("1+2i") );
    }
    SECTION( "o3" ) {
        Complex c{2, -2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("2-2i") );
    }
    SECTION( "o4" ) {
        Complex c{-2, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("-2+2i") );
    }
    SECTION( "p1" ) {
        Complex c;
        c << "1+1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "p2" ) {
        Complex c;
        c << "1-1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == -1 );
    }
    SECTION( "p3" ) {
        Complex c;
        c << "-1+0i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "p4" ) {
        Complex c;
        c << "-1-2i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == -2 );
    }
};
//------------------------------
