#include <iostream>
#include <stack>
#include <map>
using namespace std;

bool fake_stack_solution(string str)
{
    int fake_stack = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(') fake_stack++;
        if (str[i] == ')') fake_stack--;
        if (fake_stack < 0) return false;
    }
    return fake_stack == 0 ? true : false;
}

/**
 * This works with all types of brackets.
 */
bool extended_stack_solution(string str)
{
    stack<char> st;
    map<char, char> mp;
    mp['}'] = '{';
    mp[')'] = '(';
    mp[']'] = '[';
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
            st.push(str[i]);
        if (str[i] == '}' || str[i] == ')' || str[i] == ']')
        {
            if (st.empty()) return false;
            if (st.top() != mp.at(str[i])) return false;
            st.pop();
        }
    }
    return st.empty() ? true : false;
}

int main()
{
    string test1 = "(1 + 2) * (1 + (2 - 4))";
    string test2 = "(5 + 5) / (5 - 8))";
    string test3 = "((6 + 5) * (4/6)";
    string test4 = "((()))()(((())))";
    string test5 = "{([5 + 5] * ([6 * 6]))}";
    cout << test1 << ": " <<  (fake_stack_solution(test1) == 1 ? "True" : "False") << endl;
    cout << test2 << ": " <<  (fake_stack_solution(test2) == 1 ? "True" : "False") << endl;
    cout << test3 << ": " <<  (fake_stack_solution(test3) == 1 ? "True" : "False") << endl;
    cout << test4 << ": " <<  (fake_stack_solution(test4) == 1 ? "True" : "False") << endl;
    cout << test5 << ": " <<  (extended_stack_solution(test5) == 1 ? "True" : "False") << endl;
    cout << test1 << ": " <<  (extended_stack_solution(test1) == 1 ? "True" : "False") << endl;
    cout << test2 << ": " <<  (extended_stack_solution(test2) == 1 ? "True" : "False") << endl;
}