#include<iostream>
#include<stack>
#include<cmath>

using namespace std;

class ExpressionEvaluator {
    public:
        string convert(string exp) {
            if (exp.empty()) return "";

            stack<char> st;
            string output; 

            for (char c: exp) {
                if (c == '(' || c == '[' || c == '{') { // opening brackets push
                    st.push(c);
                } else if (c == ')' || c == ']' || c == '}') { // closing bracket
                    while(!st.empty() && !isClosing(c, st.top())) { // while opening is not found, 
                        char top = st.top();
                        if (top == '+' || top == '-' || top == '*' || top == '/' || top == '^') {
                            output += top; // if operator, append
                        }
                        st.pop(); 
                    }
                    st.pop(); // pop the opening bracket.
                } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') { // if operator
                    while(!st.empty() && precedence(st.top(), c)) { // remove all the operators with higher or equal priority
                        output += st.top();
                        st.pop();
                    }
                    st.push(c);
                } else { // operands
                    output += c;
                }
            }

            while (!st.empty()) {
                output += st.top();
                st.pop();
            }


            return output;
        }

        double evaluate(string exp) {
            stack<double> st;     

            for (char c: exp) {
                if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {

                    double val2 = st.top();
                    st.pop();
                    double val1 = st.top();
                    st.pop();

                    double result = applyOp(val1, val2, c);

                    st.push(result);
                } else {
                    st.push(double(c - '0'));
                }
            }

            return st.top();
        }




        // helper method to check opening-closing pair
        bool isClosing(char closing, char opening) {
            return (opening == '(' && closing == ')') ||
                (opening == '[' && closing == ']') ||
                (opening == '{' && closing == '}');
        }

        // helper method to check the precedence of two operator, true if 1 has greater than 2, else false
        bool precedence(char op1, char op2) {
            // Assign precedence values
            int prec1, prec2;

            switch (op1) {
                case '+':
                case '-': prec1 = 1; break;
                case '*':
                case '/': prec1 = 2; break;
                case '^': prec1 = 3; break;
                default: prec1 = 0;  // unknown operator
            }

            switch (op2) {
                case '+':
                case '-': prec2 = 1; break;
                case '*':
                case '/': prec2 = 2; break;
                case '^': prec2 = 3; break;
                default: prec2 = 0;  // unknown operator
            }

            // ^ is right-associative (special case)
            if (op1 == '^' && op2 == '^')
                return false;

            return prec1 >= prec2;
        }

        double applyOp(double a, double b, char op) {

            switch (op) {
                case '+': return a + b;
                case '-': return a - b;
                case '*': return a * b;
                case '/': 
                    if (b == 0) throw runtime_error("Division by zero!");
                    return a / b;
                case '^': 
                    return pow(a, b); // needs <cmath>
                default: 
                    throw invalid_argument("Unknown operator");
            }
}

};

int main() {
    string expression = "3+5-9+3";
    ExpressionEvaluator s;
    
    cout << s.convert(expression);

    return 0;
}