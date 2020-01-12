#include <iostream>
#include <stack>
#include <string>
using namespace std;


class Bracket
{	
public:
	char type;
	int position;

	Bracket(char t, int p)
	{
		type=t;
		position=p;
	}
	bool Matchc(char c) 
	{
		if (type=='[' && c ==']')
			return true;
		if(type=='{' && c=='}')
			return true;
		if(type=='(' && c==')')
			return true;
		return false;
	}

};

int main() {
    string text;
    getline(cin, text);
    int pos_error=0;

    stack <Bracket> opening_brackets_stack;
    stack <Bracket> closing_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{'){
            // Process opening bracket, write your code here
            Bracket b = Bracket(next,position+1);
            opening_brackets_stack.push(b);
           
      	  }

        if (next == ')' || next == ']' || next == '}'){
            // Process closing bracket, write your code here
            
            if(opening_brackets_stack.empty())
            {
            	pos_error=position+1;	
            	break;
            }
            Bracket top = opening_brackets_stack.top();	
           if(!top.Matchc(next))
            {
            	pos_error  =  position+1;
            	
            	break;
            }
            opening_brackets_stack.pop();


        }
    }

    // Printing answer
    if(pos_error==0 && opening_brackets_stack.empty())
    {
    	cout<<"Success"<<endl;
    }
    else
    {
    	if(pos_error==0){
    		Bracket top = opening_brackets_stack.top();
    		pos_error= top.position;
    	}
    	cout<<pos_error;
    }

    return 0;
}
