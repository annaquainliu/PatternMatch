#include <iostream>
#include <string>
#include <vector>
#include "compiler.h"
#include "map"

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
            if (front == "fun") {
                string name = queue[queue.size() - 1];
                queue.pop_back();
                string front = queue[queue.size() - 1];
                while (front != "=") {
                    while (front != "=" && front != "|") {
                        
                    }
                }
            }
            else {

            }

        }
        Type* typeOf() {
            return new Type();
        }
    private:
        string toString() {
            return "error";
        }
};

// Object that represents datatype constructors
class DataTypeCons {
    public:
        //map of string name of type to datatype constructors
        map<string, vector<DataTypeCons>> datatypeMap{};

    private:
};

class ApplyToken : public Token {
    public:

    private:

};

// for constructors
// patternmatching
class ConstructorToken : public ApplyToken {

    private:
        string name; 

    public:
        

};  

class VarToken : public Token {
    public:
        VarToken(string name) {
            this->name = name;
        }
    private:
        string name;
};

class Literal : public Token {

};

class BoolToken : Literal {

};

class IntToken : Literal {

};

class StringToken : Literal {

};

class ListToken : Literal {

};

class FunctionToken : Token {
    public:
        FunctionToken(string name, vector<string> params, Token body, map<Token, Token> cases) {
            this->name = name;
            this->parameters = params;
            this->body = body;
            this->cases = cases;
        }
        
    private:
        string name;
        vector<string> parameters;
        map<Token, Token> cases;
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