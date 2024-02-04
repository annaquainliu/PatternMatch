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
        vector<string> keywords{"fun", "hello"};
};

#endif 
