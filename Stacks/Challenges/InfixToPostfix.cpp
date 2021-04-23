#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

/**
 * Challenge: Create a program that converts a Infix mat expression int Postfix form.
 * EX) ((a+b)*c)-d^e^f -> ab+c*def^^-
 */

/* Precedence Maps */
map<char,int>* out_stack_map_constructor()
{
    map<char,int> *osm = new map<char,int>;
    osm->insert(make_pair('+', 1));
    osm->insert(make_pair('-', 1));
    osm->insert(make_pair('*', 3));
    osm->insert(make_pair('/', 3));
    osm->insert(make_pair('^', 6));
    osm->insert(make_pair('(', 7));
    osm->insert(make_pair(')', 0));
    return osm;
}

map<char,int>* in_stack_map_constructor()
{
    map<char,int> *ism = new map<char,int>;
    ism->insert(make_pair('+', 2));
    ism->insert(make_pair('-', 2));
    ism->insert(make_pair('*', 4));
    ism->insert(make_pair('/', 4));
    ism->insert(make_pair('^', 5));
    ism->insert(make_pair('(', 0));
    ism->insert(make_pair(')', -1));
    return ism;
}

/* Helper functions */
bool is_operator(map<char, int> *mp, char ch)
{
    return mp->count(ch) == 1 ? true : false;
}

bool is_operand(char ch)
{
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*') return false;
    return true;
}

/* Solution */
string infix_to_postfix(string *infix)
{
    string postfix = "";
    stack<char> st;
    map<char, int> *osm = out_stack_map_constructor();
    map<char, int> *ism = in_stack_map_constructor();
    int pi = 0, i = 0;
    while(i < infix->length())
    {
        if (is_operator(osm, infix->at(i)))
        {
            if (!st.empty())
            {
                int infix_char_prec = osm->at(infix->at(i));
                int stack_top_prec = ism->at(st.top());
                if (infix_char_prec < stack_top_prec)
                {
                    postfix += st.top();
                    st.pop(); 
                } 
                else if (infix_char_prec == stack_top_prec)
                {
                    st.pop();
                } 
                else if (infix_char_prec > 0)
                {
                    st.push(infix->at(i++));
                }
            } 
            else
            {
                if (osm->at(infix->at(i)) != 0)
                    st.push(infix->at(i++));
                else
                    i++;
            }
        }
        else 
        {
            postfix += infix->at(i++);
        }
    }
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    delete ism;
    delete osm;
    return postfix;
}

int perform_operation(int x1, int x2, char op)
{
    switch (op)
    {
    case '+':
        return (x1 + x2) + '0';
        break;
    case '-':
        return (x1 - x2) + '0';
    case '*':
        return (x1 * x2) + '0';
    case '/':
        return (x1 / x2) + '0';
        break;
    default:
        return -1;
        break;
    }
}

int evaluate_postfix(string postfix)
{
    stack<char> st;
    int x1, x2;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (is_operand(postfix[i])) // push all operands to the stack
        {
            st.push(postfix[i]);
        } 
        else // pop two operands off the stack and perform operation
        {
            x2 = st.top() - '0';
            st.pop();
            x1 = st.top() - '0';
            st.pop();
            st.push(perform_operation(x1, x2, postfix[i]));
        }
    }
    return st.top() - '0';
}

int main()
{
    string input;
    int result;
    while (1)
    {
        cout << "Enter an operation or -1 to quit: ";
        cin >> input;
        if (input == "-1") break;
        cout << "Infix: " << input << endl;
        input = infix_to_postfix(&input);
        cout << "Postfix: " << input << endl;
        result = evaluate_postfix(input);
        cout << "Result: " << result << endl;
    }
    cout << "Program ended." << endl;
}