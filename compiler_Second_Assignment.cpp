#include<bits/stdc++.h>
using namespace std;
map< string, vector< string > > database;
int HashKey(string str)
{
    int sum = 0;
    for(char c : str)
        sum+=(int)c;
    return sum%101;
}
string itos(int n)
{
    string result = "";
    while(n)
    {
        result+=((n%10)+'0');
        n/=10;
    }
    reverse(result.begin(),result.end());
    return result;
}

vector< string > split(string str, char reg)
{
    vector< string > strings;
    string temp = "";
    for(char c : str)
    {
        if(c==reg)
        {
            strings.push_back(temp);
            temp = "";
            continue;
        }
        temp+=c;
    }
    strings.push_back(temp);
    return strings;
}
void remove_extra_space(string &str)
{
    bool first_space = true;
    string temp = "";
    for(char c : str)
    {
        if(c==' ' && !first_space)
            continue;
        if(c==' ')
            first_space = false;
        temp+=c;
    }
    str = temp;
    return;
}

void __menu()
{
    printf("Menu:\n1. Insert\n2. Find\n3. Delete\n4. Show Specific\n5. Show All\n6. Update\n7. Exit\n");
    printf("Choose an option: ");
}
void __updatemenu()
{
    printf("Which part you want to update?\n");
    printf("1. Type\n2. Value\n");
    printf("Choose an option: ");
}
void insertion()
{
    cout << "Please Enter an input statement: ";
    string str;
    getline(cin,str);
    remove_extra_space(str);
    str.pop_back();
    vector< string > strings = split(str,' ');
    string DataType = strings[0];
    strings = split(strings[1],',');

    auto has_equal = [&](string str)
    {
        for(char c : str)
        {
            if(c=='=')
                return true;
        }
        return false;
    };


    for(string s : strings)
    {
        string VariableName;
        string Value;

        if(has_equal(s))
        {
            vector< string > temp_strings = split(s,'=');
            VariableName = temp_strings[0];
            Value = temp_strings[1];
        }
        else
        {
            VariableName = s;
            Value = "NULL";
        }

        string serial = itos(HashKey(VariableName));
        database[VariableName]= {serial,DataType,Value};
    }
}
int main()
{
    while(true)
    {
        __menu();
        int choice;
        cin >> choice;
        if(choice>6)
        {
            if(choice==7)
                return 0;
            else
                continue;
        }

        switch(choice)
        {
        case 1 :
        {
            getchar();
            insertion();
            break;
        }
        case 2 :
        {
            cout << "Enter the variable name you want to find : ";
            string str;
            cin >> str;
            if(database[str].size())
                cout << "FOUND!!\n";
            else
                cout << "NO FOUND!!\n";
            break;
        }
        case 3 :
        {
            cout << "Enter the variable name you want to delete : ";
            string str;
            cin >> str;
            database.erase(str);
            break;
        }
        case 4 :
        {
            cout << "Enter the variable name you want to see : ";
            string str;
            cin >> str;
            if(database[str].size())
            {
                cout << database[str][0] << " " << str << " " << database[str][1] << " " << database[str][2] << endl;
            }
            else
                cout << "THIS VARIABLE DOES NOT EXIST IN THE TABLE\n";
            break;
        }
        case 5 :
        {
            cout << "TABLE VIEW: \n";
            for(auto x : database)
            {
                cout << x.second[0] << " " << x.first << " " << x.second[1] << " " << x.second[2] << endl;
            }
            break;
        }
        case 6 :
        {
            cout << "Enter the variable name you want to update : ";
            string str;
            cin >> str;
            if(database[str].size())
            {
                __updatemenu();
                int up_choice;
                cin >> up_choice;

                if(up_choice==1)
                {
                    cout << "Enter new data type for the variable named : " << str << " : ";
                    string type;
                    cin >> type;
                    vector< string > &t_v = database[str];
                    t_v[1]=type;
                }
                else if(up_choice==2)
                {
                    cout << "Enter new value for the variable named " << str << " : ";
                    string val;
                    cin >> val;
                    vector< string > &t_v = database[str];
                    t_v[2]=val;
                }
            }
            else
                cout << "THIS VARIABLE DOES NOT EXIST IN THE TABLE\n";
            break;

        }
        }
    }
}
