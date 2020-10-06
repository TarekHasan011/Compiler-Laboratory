#include<bits/stdc++.h>
using namespace std;
bool valid_id(string str)
{
    if(str.size()!=9) return false;

    for(char c : str)
    {
        if(c>='0' && c<='9') continue;
        return false;
    }

    if(str.substr(0,3)=="011")
    {
        int year = stoi(str.substr(3,2));
        if(year>=0 && year<=99)
        {
            int trimester = stoi(str.substr(5,1));
            if(trimester>=1 && trimester<=3)
            {
                int roll = stoi(str.substr(6));
                if(roll>0)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}
bool valid_complex_number_format(string str)
{
    string temp = "";
    for(char c : str)
    {
        if(c!=' ') temp+=c;
    }
    str = temp;

    auto has_equal = [&]()
    {
        for(int i=0;i!=str.size();i++)
        {
            if(str[i]=='=')
                return i+1;
        }
        return 0;
    };

    str = str.substr(has_equal());
    string real="";
    string imaginary="";

    bool switching = false;
    for(char c : str)
    {
        if(c=='+' || c=='-')
        {
            switching = true;
            continue;
        }

        if(switching)
            imaginary+=c;
        else
            real+=c;
    }

    if(real.size() && imaginary.size())
    {
        auto check_i = [&](string str)
        {
            for(char c : str)
            {
                if(c=='i')
                    return true;
            }
            return false;
        };

        auto check = [&](string str)
        {
            for(char c : str)
            {
                if((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')) continue;
                return false;
            }
            return true;
        };

        if(!check_i(real) && check_i(imaginary) && check(real) && check(imaginary)) return true;
        else return false;
    }
    else
        return false;
}
bool valid_expression(string str)
{
    if(str.size()<3) return false;

    if(str[0]>='0' && str[0]<='9' && str[1]>='A' && str[1]<='Z')
    {
        if((str[2]>='a' && str[2]<='z') || (str[2]>='A' && str[2]<='Z')) return false;
        else return true;
    }
    else
        return false;
}
bool valid_number(string str)
{
    if(str[0]=='+' || str[0]=='-')
        str=str.substr(1);
    str="0"+str;

    bool has_decimal_point = false;
    for(char c : str)
    {
        if(c=='.')
        {
            has_decimal_point = true;
            break;
        }
    }


    auto valid = [&](string str)
    {
        if(str.size()==0) return false;

        for(char c : str)
        {
            if(c>='0' && c<='9') continue;
            return false;
        }
        return true;

    };

    if(has_decimal_point)
    {
        string first = "";
        string second = "";
        bool switching = false;

        for(char c : str)
        {
            if(c=='.')
            {
                switching = true;
                continue;
            }
            if(switching)
                second+=c;
            else
                first+=c;
        }

        return valid(first) && valid(second);
    }
    else
        return valid(str);
}
bool valid_password(string str)
{
    if(str.size()<8) return false;
    bool upper = false;
    bool lower = false;
    bool digit = false;

    for(char c : str)
    {
        if(c>='A' && c<='Z')
            upper=true;
        else if(c>='a' && c<='z')
            lower=true;
        else if(c>='0' && c<='9')
            digit=true;
    }

    return upper && lower && digit && (str[str.size()-1]=='@' || str[str.size()-1]=='#' || str[str.size()-1]=='$' || str[str.size()-1]=='&');
}
void __menu()
{
    cout << "1. UIU CSE ID\n2. Complex Number Format\n3. String\n4. Integer and Floating point Number\n5. Password\n6. Exit\nChoose an option: ";
}
int main()
{
    while(true)
    {
        __menu();
        int choice; cin >> choice;
        getchar();

        if(choice>5)
        {
            if(choice==6) break;
            else
            {
                cout << "Invalid Choice!\n"; continue;
            }
        }

        string input_s[] = {"UIU CSE ID : ","Complex Number : ","an String : ","Integer or floating point Number : ","Password : "};
        string input = "Enter "+ input_s[choice-1];
        cout << input;
        string str; getline(cin,str);

        bool flag = true;

        switch(choice)
        {
            case 1 :
            {
                flag = valid_id(str);
                break;
            }
            case 2 :
            {
                flag = valid_complex_number_format(str);
                break;
            }
            case 3 :
            {
                flag = valid_expression(str);
                break;
            }
            case 4 :
            {
                flag = valid_number(str);
                break;
            }
            case 5 :
            {
                flag = valid_password(str);
                break;
            }
        }

        cout << endl;
        flag ? cout << "VALID\n" : cout << "INVALID\n";
        cout << endl;
    }

    return 0;
}
