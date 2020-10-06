#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("expression.txt");
    if(fin.is_open())
    {
        string str; fin >> str;
        fin.close();
        fin.open("random.txt");
        if(fin.is_open())
        {
            double rand; fin >> rand;
            fin.close();

            double a = str[0]-'0'; double b = str[2]-'0';
            double result;
            if(str[1]=='+')
                result=a+b;
            else if(str[1]=='-')
                result=a-b;
            else if(str[1]=='*')
                result=a*b;
            else
            {
                if(b==0)
                {
                    cout << "Divided by Zero Exception\n";
                    return 0;
                }
                result=a/b;
            }

            cout << abs(result-rand)*abs(result-rand)*abs(result-rand) << endl;

        }
        else
            cout << "Random File Not Found\n";
    }
    else
        cout << "Expression File Not Found\n";
    return 0;
}
