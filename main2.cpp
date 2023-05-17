#include <bits/stdc++.h>

#include "function.cpp"

#include "stacker.cpp"

using namespace std;

// SPACE COMPLEXITY -> O(2N)

// TIME COMPLEXITY  -> O(2N) if correct input is inserted at first go 

// TIME COMPLEXITY  -> O((M*N)+2N) M=no. of wrong inputs entered 

/*
SPECS :

make  a calculator for string input for only positive and negative integers and check for the following
-> parnthesis( will do later )
-> no alphabets in the string
-> no 2 consecutive signs

*/

int main()
{
    string input;
    vector<long long int >nums;
    vector<char>signs;
    cout<<"enter the expression : "<<endl;
    getline(cin,input);
    bool validity=is_valid(input);
    
    while(validity==false)


    {
        cout<<"enter a valid expression : "<<endl;
        getline(cin,input);
        validity=is_valid(input);
    }
    bool bracket_checker=paranthesis_checker(input);
    while (bracket_checker==false)
    {
        cout<<"check your brackets"<<endl;
        getline(cin,input);
        bracket_checker=paranthesis_checker(input);
    }
    
    nums=split(input,signs);
    answer(signs,nums);
    for (int i=0;i<nums.size();i++)
    {
        cout<<"nums : "<<nums[i]<<endl;
    }
    for (int i=0;i<signs.size();i++)
    {
        cout<<"sign : "<<signs[i]<<endl;
    }
    return 0;
}

bool isvalid(string input)
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

    */
    // string sign[4]={"+","-","*","/"};
    for (int i=0;i<input.length();i++)// checking valid or not
    {
        if ((47<=(int(input[i])) && (int(input[i]))<=57) || (int(input[i]))==45 || (int(input[i]))==42 || (int(input[i]))==43 || (int(input[i]))==32)
        {
            if ((int(input[i]))==45 || (int(input[i]))==42 || (int(input[i]))==43 || (int(input[i]))==47)
            {
                if ((int(input[i+1]))==45 || (int(input[i+1]))==42 || (int(input[i+1]))==43 || (int(input[i+1]))==47)
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
    }
    // if (input[(input.length()-1)])
    if ((int(input[(input.length()-1)]))==45 || (int(input[(input.length()-1)]))==42 || (int(input[(input.length()-1)]))==43 || (int(input[(input.length()-1)]))==47)
    {
        return false;
    }
    if ((int(input[0]))==42 || (int(input[0]))==47)
    {
        return false;
    }
return true;
}

bool paranthesis_checker(string input)
{
    int s=input.size();
    stacker st(s);
    for(int i=0;i<s;i++)
    {
        switch (input[i]){
            case '(':
            st.push('(');
            break;
            case ')':
            st.pop();
            break;
        }
    }
    if (st.is_empty())
    return true;
    else
    return false;
    // return true;// for now
    // will write this function later


}

vector<long long int > split(string input,vector<char> &sign)
{
    string temp="";
    long long int  n=0;
    vector<long long int >num;
    for (int i=0;i<input.length();i++)
    {
        if ((input[i]=='+'&&input[i]!='-')||(input[i]!='+'&&input[i]=='-'))
        {
            num.push_back(n);
            sign.push_back(input[i]);
            n=0;
            
            temp="";
        }
        else if (input[i]==' '||input[i]=='('||input[i]==')')
        continue;
        else
        {
            temp+=input[i];
            int digit=input[i]-'0';
            n=n*10+digit;
        }
    }

    num.push_back(n);
    return num;
}

void answer(vector<char> &sign,vector<long long int > &num)
{
    long long int  res=num[0];
    int sign_ptr=0;
    int num_ptr=1;
    while (num_ptr!=num.size())
    {
        if (sign[sign_ptr]=='+')
        {
            res+=num[num_ptr];
        }
        else if (sign[sign_ptr]=='-')
        {
            res-=num[num_ptr];
        }
        sign_ptr++;
        num_ptr++;
    }
    cout<<"answer : "<<res<<endl;   
}

