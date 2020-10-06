#include<bits/stdc++.h>
using namespace std;
int Operator_Priority(char c)
{
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else
        return 3;
}
bool Operator(char c)
{
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}
void insert_operator(char op, string &str)
{
    int counter = 0;
    int braces = 0;

    for(int i=str.size()-1;i>=0;i--)
    {
        if(str[i]==')')
            braces++;
        else if(str[i]=='(')
            braces--;
        if(braces==0)
            counter++;

        if(counter==2)
        {
            string temp = "(";
            temp+=op;
            str.insert(i,temp);
            str+=")";
            break;
        }
    }
    return;
}
string infix_to_PrePost(string infix, bool flag)
{
    string PrePost = "";
    stack< char > st;
    for(char c : infix)
    {
        if(c==' ')
            continue;

        if(Operator(c))
        {
            if(c=='^')
                st.push(c);
            else
            {
                while(!st.empty() && Operator(st.top()) && Operator_Priority(st.top())>=Operator_Priority(c))
                {
                    if(flag) PrePost+=st.top();
                    else insert_operator(st.top(),PrePost);
                    st.pop();
                }
                st.push(c);
            }
        }
        else if(c=='(')
            st.push(c);
        else if(c==')')
        {
            while(st.top()!='(')
            {
                if(flag) PrePost+=st.top();
                else insert_operator(st.top(),PrePost);
                st.pop();
            }
            st.pop();
        }
        else
            PrePost+=c;
    }
    while(!st.empty())
    {
        if(flag) PrePost+=st.top();
        else insert_operator(st.top(),PrePost);
        st.pop();
    }

    if(!flag)
    {
        string result = "";
        for(char c : PrePost)
        {
            if(c==')' || c=='(') continue;
            result+=c;
        }
        PrePost=result;
    }
    return PrePost;
}
int menu()
{
    int choice;
    printf("1. Console Input\n2. File Input\n3. Exit\nEnter Choice: ");
    scanf("%d",&choice);
    getchar();
    return choice;
}
string another_menu(string str)
{
    printf("1. Prefix Expression\n2. Postfix Expression\nEnter Choice: ");
    int choice; scanf("%d",&choice);
    getchar();
    if(choice==1)
        return "Prefix Expression : " + infix_to_PrePost(str,false);
    else if(choice==2)
        return "Postfix Expression : " + infix_to_PrePost(str,true);
    else
    {
        printf("Invalid Choice!!\n");
        return another_menu(str);
    }
}
void console_input()
{
    printf("Enter the Expression : ");
    string str; getline(cin,str);
    cout << another_menu(str) << endl;
    printf("Press any key to continue....");
    getchar();
    return;
}
void file_input()
{
    printf("Enter File Path : ");
    char path[100]={'\0'}; gets(path);
    char str[100]={'\0'};

    FILE * file = fopen(path,"r");
    if(file==NULL)
    {
        cout << "File Not Found!\n";
        return;
    }
    else fgets(str,60,file);
    fclose(file);

    string result="";
    for(int i=0;str[i];i++)
        result+=str[i];
    result.pop_back();

    result = another_menu(result);

    for(int i=0;i<result.size();i++) str[i]=result[i];

    file = fopen(path,"a");
    fputs(str,file);
    fclose(file);

    printf("Wrote in File Successfully!!\n");
    printf("Press any key to continue.....");
    getchar();

    return;
}
int main()
{
    while(true)
    {
        system("cls");
        int choice = menu();
        if(choice==1)
            console_input();
        else if(choice==2)
            file_input();
        else if(choice==3)
            return 0;
    }
    return 0;
}
