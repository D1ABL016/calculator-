#include <iostream>
using namespace std;
// is empty , peek , pop , push 
// 
class stacker
{
public:
    char *arr;
    int size;
    int top;
    
    stacker(int s1)
    {
        size=s1;//yha errr ho skta h shayd
        arr=new char[size];
        top=-1;
    }

    void push(char element)
    {
        if (top==size-1)
        cout<<"stack overflow"<<endl;
        else
        {
            top++;
            arr[top]=element;
        }
    }
    
    void pop()
    {
        if (top==-1)
        cout<<"stack underflow"<<endl;
        else
        top--;
    }

    int peek()
    {
        if (top==-1)
        return -1;
        else
        return arr[top];
    }

    bool is_empty()
    {
        if (top==-1)
        return true;
        else
        return false;
    }
    
};

bool is_valid(string input)

{
    /*this will check whether the inputt is valid or not 
    -> no 2 sign can be adjacent
    -> no other char other than (0-9,-,+,*,/)
    -> last elemnt cant be  a sign
    -> spaces should be ignored
    -> cant start with a sign
    ASCII 48-57(FOR NUM)
    42 -> *
    43 -> +
    45 -> -
    47 -> /
    () should be ignored 
    */
    // string sign[4]={"+","-","*","/"};

    char temp;
    char arr[]={'+','-','*','/','(',')','6','5','4','3','2','1','0','7','8','9',' '};
    char start[]={'*','/'};
    char sign[]={'+','-','*','/'};
    char end[]={'+','-','*','/','('};
    for (int i=0;i<input.length();i++)
    {
        // cout<<input.length()<<endl;
        temp=input[i];
        if (i!=input.length()-1)
        {
            char temp1=input[i+1];
            // bool valid=false;
            for (int j=0;j<4;j++)
            {
                if (temp==sign[j])
                {
                    for (int k=0;k<4;k++)
                    {
                        if (temp1==sign[k])
                        return false;
                    }
                }
            }
        }
        // cout<<temp<<endl;
        
        for (int j=0;j<2;j++)
        {
            if(input[0]==start[j])
            return false;
        }
        bool v=false;
        for (int j=0;j<17;j++)
        {
            if (temp!=arr[j])
            v=false;
            else
            {v=true;
            break;}
        }
        
        if (v==false)
        return false;

        for (int j=0;j<6;j++)
        
        {
            if (input[input.length()-1]==end[j])
            return false;
        }
        
    }
    return true;
}


int main1(){
    // stacker st(4);

    // st.push(34);
    // st.push(65);
    // st.push(21);
    // st.push(19);
    // st.push(91);
    // st.push(78);

    // // st.pop();

    // cout<<st.peek()<<endl;
    // st.pop();

    // cout<<st.peek()<<endl;
    // st.pop();

    // cout<<st.peek()<<endl;
    // st.pop();

    // if (st.is_empty())
    // cout<<"stack is empty"<<endl;
    // else
    // cout<<"stack is not empty"<<endl;

    return 0;
}