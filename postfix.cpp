#include <iostream>
#include <fstream>
#include "string.hpp"
#include "utilities.hpp"

int main(int x, char* e[]) {
    if (x < 2) {
        
        std::cerr << "Usage: " << e[0] << " input_file [output_file]\n";
        return 1;
    }

    std::ifstream in(e[1]);
    if (!in) {
        std::cerr << "Error opening input file: " << e[1] << "\n";
        return 1;
    }

    std::ostream* out = &std::cout;
    std::ofstream outFile;
    
    if (x >= 3) {
        outFile.open(e[2]);
        if (!outFile) {
            std::cerr << "Error opening output file: " << e[2] << "\n";
            return 1;
        }
        out = &outFile;
    }

    String token;
    String expr;
    
    while (in >> token) {
        expr += token + String(' ');
        if (token == ";") {
            String postfix = convertInfixToPostfix(expr);
            *out << "Infix Expression: " << expr << "\n";
            *out << "Postfix Expression: " << postfix << "\n\n";
            expr = String(); // Reset for next line
        }
    }
    
    if (outFile.is_open()) outFile.close();
    return 0;
}