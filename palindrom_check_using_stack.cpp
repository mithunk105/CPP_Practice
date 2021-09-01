// Identifying palindrome strings using a stack
#include <cctype>
#include <stack>
#include <iostream>
#include <string>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a stack and a queue to solve the problem.
	std::stack<char> pldrm, temp;
	std::stack<char> pldrm1;
	if (s.size() > 1) {
		for( char ch_read : s ) {
			if ( std::isalpha(ch_read) ){
			    pldrm.push(std::toupper(ch_read));
			    }
		    }
		}
	temp = pldrm;
	while(!temp.empty()){
		pldrm1.push(temp.top());
		temp.pop();
		}
	while(!pldrm.empty() && !pldrm1.empty()) {
		if ( pldrm.top() != pldrm1.top() ) {
			return false;
			}
		pldrm.pop();
		pldrm1.pop();
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

/*Output - 
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
*/