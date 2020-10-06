#include<bits/stdc++.h>
using namespace std;
bool Operator(char c)
{
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}
int main()
{
    string postfix; getline(cin,postfix);
    stack< double > st;
    for(char c : postfix)
    {
        if(c==' ') continue;

        if(!Operator(c)) st.push(c-'0');

        if(Operator(c))
        {
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            if(c=='+')
                st.push(a+b);
            else if(c=='-')
                st.push(a-b);
            else if(c=='*')
                st.push(a*b);
            else if(c=='/')
            {
                if(b==0)
                {
                    cout << "Divided by Zero Exception\n";
                    return 0;
                }
                st.push(a/b);
            }
            else
                st.push(pow(a,b));
        }
    }
    cout << "Result: ";
    cout << st.top() << endl;
    return 0;
}
