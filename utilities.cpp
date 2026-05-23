#include <iostream>
#include <cassert>
#include "stack.hpp"
#include "string.hpp"
#include "utilities.hpp"

String convertInfixToPostfix(const String& expr)
{
    Stack<String> e;
    std::vector<String> tokens = expr.split(' ');
    for (size_t i =0; i< tokens.size(); i++)
    {
        String x = tokens[i];
        if (x == ";" || x == "")
            continue;
        else if (x == ")")
        {
            String r = e.pop();
            String o = e.pop();
            String l = e.pop();
            e.push(l + " " + r + " " + o);
        }
        else if (x != "(")
            e.push(x);
    }
    if (!e.empty())
        return e.pop();
    else
        return String();
}

String evaluate(String l, String op, String r, int& T, std::ostream& o)
{
    String Tem = String("TMP") + String(T);
    T++;
    o << "   LD   " << l << "\n";
    if (op == "+")
        o <<"   AD   "<<r<<"\n";
    else if (op =="-")
        o <<"   SB   "<<r<<"\n";
    else if (op == "*")
        o<<"   MU   "<<r<<"\n";
    else if (op=="/")
        o << "   DV   "<<r<<"\n";
    o<< "   ST   "<<Tem<<"\n";
    return Tem;
}

void generateAssembly(const String& pf, std::ostream& o)
{
    Stack<String> s;
    std::vector<String> t = pf.split(' ');
    int Tem =1;
    for (size_t i=0; i<t.size();i++)
    {
        String tz = t[i];
        if (tz=="")
            continue;
        if (tz != "+" && tz != "-" && tz != "*" && tz != "/")
            s.push(tz);
        else
        {
            String r = s.pop();
            String l = s.pop();
            String tm = evaluate(l, tz, r, Tem, o);
            s.push(tm);
        }
    }
}