// Mathematical Expression Converter
// Prefix -> Expression Tree -> Infix, Postfix, Evaluation
//
// Input: prefix expression with tokens separated by spaces
// Example: + * 5 4 - 100 20      (multi-digit and decimal numbers supported)
//          * + a b - c d         (variables supported, values asked at runtime)
// Operators supported: + - * / ^

#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <cmath>
#include <stdexcept>
using namespace std;

struct Node {
    string val;
    Node *left, *right;
    Node(const string &v) : val(v), left(nullptr), right(nullptr) {}
};

bool isOperator(const string &t) {
    return t == "+" || t == "-" || t == "*" || t == "/" || t == "^";
}

bool isNumber(const string &t) {
    try {
        size_t pos;
        stod(t, &pos);
        return pos == t.size();
    } catch (...) {
        return false;
    }
}

// Build expression tree from prefix tokens (scan right to left using a stack)
Node *buildTree(const vector<string> &tokens) {
    stack<Node *> st;
    for (int i = (int)tokens.size() - 1; i >= 0; i--) {
        Node *n = new Node(tokens[i]);
        if (isOperator(tokens[i])) {
            if (st.size() < 2) {
                delete n;
                while (!st.empty()) { delete st.top(); st.pop(); }
                throw runtime_error("Invalid prefix expression (missing operand).");
            }
            n->left = st.top();  st.pop();   // first operand
            n->right = st.top(); st.pop();   // second operand
        }
        st.push(n);
    }
    if (st.size() != 1) {
        while (!st.empty()) { delete st.top(); st.pop(); }
        throw runtime_error("Invalid prefix expression (extra operands).");
    }
    return st.top();
}

// Infix: (left op right) - parentheses keep the original order of evaluation
void infix(Node *root, string &out, bool isRoot = true) {
    if (!root) return;
    if (!root->left && !root->right) {
        out += root->val;
        return;
    }
    if (!isRoot) out += "(";
    infix(root->left, out, false);
    out += " " + root->val + " ";
    infix(root->right, out, false);
    if (!isRoot) out += ")";
}

// Postfix: left right op
void postfix(Node *root, string &out) {
    if (!root) return;
    postfix(root->left, out);
    postfix(root->right, out);
    out += root->val + " ";
}

// Evaluate the tree recursively
double evaluate(Node *root, map<string, double> &vars) {
    if (!root->left && !root->right) {
        if (isNumber(root->val)) return stod(root->val);
        if (vars.find(root->val) == vars.end()) {
            double v;
            cout << "Enter value of " << root->val << ": ";
            cin >> v;
            vars[root->val] = v;
        }
        return vars[root->val];
    }
    double a = evaluate(root->left, vars);
    double b = evaluate(root->right, vars);
    char op = root->val[0];
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw runtime_error("Division by zero.");
            return a / b;
        case '^': return pow(a, b);
    }
    throw runtime_error("Unknown operator.");
}

void freeTree(Node *root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    string line;
    char again = 'y';

    cout << "=== Expression Tree Converter (Prefix -> Infix / Postfix / Value) ===\n";
    cout << "Operators: + - * / ^   |   Separate tokens with spaces\n";

    while (again == 'y' || again == 'Y') {
        cout << "\nEnter prefix expression: ";
        getline(cin >> ws, line);

        vector<string> tokens;
        stringstream ss(line);
        string tok;
        while (ss >> tok) tokens.push_back(tok);

        if (tokens.empty()) {
            cout << "Empty expression.\n";
        } else {
            Node *root = nullptr;
            try {
                root = buildTree(tokens);

                string in, post;
                infix(root, in);
                postfix(root, post);

                cout << "Prefix  : " << line << "\n";
                cout << "Infix   : " << in << "\n";
                cout << "Postfix : " << post << "\n";

                map<string, double> vars;
                double result = evaluate(root, vars);
                cout << "Result  : " << result << "\n";
            } catch (const exception &e) {
                cout << "Error: " << e.what() << "\n";
            }
            freeTree(root);
        }

        cout << "\nConvert another expression? (y/n): ";
        cin >> again;
    }
    return 0;
}
