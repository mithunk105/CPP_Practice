// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

bool is_palindrome(const std::string& s) {
    char c1{};
    char c2{};
    if ( !s.empty() ) {
        std::deque<char> pdrm;
        for ( auto x : s ) {
            if ( std::isalpha( x ) ) {
	            pdrm.push_back(std::toupper(x));
	        }
	    }
	    while ( pdrm.size() > 1) {
	        c1 = pdrm.front();
	        c2 = pdrm.back();
	        pdrm.pop_front();
	        pdrm.pop_back();
	        if ( c1 != c2 ) {
	            return false;
	        }
	    }
	}
    return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

Output -

Result  String
true    a
true    aa
true    aba
true    abba
true    abbcbba
false   ab
false   abc
true    radar
true    bob
true    ana
true    avid diva
true    Amore, Roma
true    A Toyota's a toyota
true    A Santa at NASA
true    C++
true    A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!
false   This is a palindrome
false   palindrome



** Process exited - Return Code: 0 **