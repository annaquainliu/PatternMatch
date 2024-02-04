#include <iostream>
#include <string>
#include <vector>
#include "compiler.h"
#include <stdexcept>
using namespace std;

class Type {

    public:
        Type() {

        }
    private:
};


class Token {
    public:
        static Token tokenize(vector<string> queue) {
            string front = queue[queue.size() - 1];
            queue.pop_back();

        }
        Type* typeOf() {
            return new Type();
        }
    private:
        string toString() {
            return "error";
        }
};

class NameToken : Token {
    public:
        NameToken(string name) {
            this->name = name;
        }
    private:
        string name;
};

class FunctionToken : Token {
    public:
        FunctionToken(string name, vector<string> params, Token body) {
            this->name = name;
            this->parameters = params;
            this->body = body;
        }
        
    private:
        string name;
        vector<string> parameters;
        Token body;
};

Compiler::Compiler() {
    this->keywords.assign({'[', ']', '(', ')', ',', ' ', ':', ';', '|'}); 
}

string Compiler::toLowerString(string s) {
    string lowered = "";
    for (size_t i = 0; i < s.length(); i++) {
        lowered += tolower(s[i]);
    }
    return lowered;
}

/**
 * Parses input into string queue
*/
vector<string> Compiler::parse(string input) {
    input = toLowerString(input);
    vector<string> queue;
    string str = "";
    for (size_t i = 0; i < input.length(); i++) {
        if (find(keywords.begin(), keywords.end(), input[i]) != keywords.end()) {
            if (str != "") {
                queue.push_back(str);
            }
            // special case: :: cons, a two character keyword
            if (i < input.length() - 1 && input[i] == ':' && input[i + 1] == ':') {
                queue.push_back("::");
                i++;
            }
            else if (input[i] != ' ') {
                queue.push_back(string(1, input[i]));
            }
            str = "";
        }
        else {
            str += input[i];
        }
    }
    if (str != "" && queue[str.length() - 1] != str) {
        queue.push_back(str);
    }
    reverse(queue.begin(), queue.end());
    return queue;
}

void Compiler::run() {
    std::string line;
    cout << " > ";
    while (std::getline(std::cin, line)) {
        vector<string> queue = parse(line);
        for (size_t i = 0; i < queue.size(); i++) {
            cout << queue[i] << " ";
        }
        cout << "\n > ";
    }
}