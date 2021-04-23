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

/* Helper function */
bool is_operator(map<char, int> *mp, char ch)
{
    return mp->count(ch) == 1 ? true : false;
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
                } else if (infix_char_prec == stack_top_prec)
                {
                    st.pop();
                } else if (infix_char_prec > 0)
                {
                    st.push(infix->at(i++));
                }
            } else
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

int main()
{
    string test = "((a+b)*c)-d^e^f";
    cout << "Prefix: " << test << endl;
    string res = infix_to_postfix(&test);
    cout << "Postfix: " << res << endl;
}