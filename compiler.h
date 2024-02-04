#ifndef COMPILER_H_
#define COMPILER_H_

#include <vector>
using namespace std;

class Compiler {

    public:
        Compiler();
        void run();

    private:
        vector<string> parse(string input);
        string toLowerString(string s);
        vector<char> keywords;
        
};

#endif 
