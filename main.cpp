#include <iostream>
#include <string>
#include <stack>
#include <limits>
using namespace std;
char bracketReturn(char bracket){
    //if bracket is ), return (
    if(bracket == ')'){
        return '(';
    }
    //if bracket is ], return [
    else if(bracket == ']'){
        return '[';
    }
    //if bracket is }, return {
    else if(bracket == '}'){
        return '{';
    }
    //it is >, return <
    return '<';
}
void howToUse() {
    cout << "Welcome to Brackets Verifier Tutorial!\n" << "To get started, press 2 when you are on the menu screen. Afterwards, you will be prompt to enter the text that you would like to verify. For example: (Hi, this is a {test}). Press enter when you are done inputting your text. It will automatically verify your text for incorrect brackets placement. Then you will be notified if you have a missing bracket. For example: (Hi(This is wrong})). Output: You are missing a {. And that is it. Have fun!\n\n";
}
void verify(string txt) {
    //creating a stack to store the character
    stack <char> s;
    //entering the for loop
    for(int i = 0; i < txt.length(); i++){
        //if the current character is equal to any of this, push the character to the text for later use
        if(txt[i] == '(' || txt[i] == '{' || txt[i] == '[' || txt[i] == '<'){
            s.push(txt[i]);
        }
        //if the current character is equal to any of this but the stack is empty, go to function bracketReturn to get the missing bracket and end the function
        else if(txt[i] == ')' || txt[i] == '}' || txt[i] == ']' || txt[i] == '>'){
            if(s.empty()){
                cout << "You are missing a " << bracketReturn(txt[i]) << "\n\n";
                return;
            }
            //if the current character is equal to ) but the top of the stack is not equal to (, end the function
            else if(txt[i] == ')' && s.top() != '('){
                cout << "You are missing a '('\n\n";
                return;
            }
            //if the current character is equal to ] but the top of the stack is not equal to [, end the function
            else if(txt[i] == ']' && s.top() != '['){
                cout << "You are missing a [\n\n";
                return;
            }
            //if the current character is equal to } but the top of the stack is not equal to {, end the function
            else if(txt[i] == '}' && s.top() != '{'){
                cout << "You are missing a {\n\n";
                return;
            }
            //if the current character is equal to > but the top of the stack is not equal to <, end the function
            else if(txt[i] == '>' && s.top() != '<'){
                cout << "You are missing a <\n\n";
                return;
            }
            //everything checks out, pop the top of the stack
            else {
                s.pop();
            }
        }
    }
    //if the stack is empty, that means the string is not missing anything
    if(s.empty()){
        cout << "Your string is not missing any brackets\n\n";
        return;
    }
    //the stack is not empty,traversing the stack to show what the string is missing by using the bracketReturn function to get the bracket
    while(!s.empty()){
        cout << "You are missing a " << bracketReturn(s.top()) << " ";
        //Freeing the stack
        s.pop();
    }
    cout << "\n\n";
}
void howItWorks(){
    cout << "When the user type in the text and press enter, the program store the text into a string variable called txt. A data structure called stack will be created. Afterwards, the program will enter a for loop. The program will exit the for loop when variable i has been incremented to the value of the text length. In the for loop, it will check whether the current character of the text is equal to either ( { [ <. If it does, the character will be pushed to the stack data structure for later use. Or if it is equal to ) } ] >, it will check if the stack is empty. If it is, it will exit the for loop saying it is missing a bracket. If the current character of the input is equal either ) } ] > but the top of the stack is not equal to the counter part, it will exit the for loop. If everything checks out, the latest addition to the stack will be taken out of the stack. This will continue until it has checked all the characters in the input. Afterwards, if the stack is empty, that means the input is valid. If it is not, that means there is a missing bracket. That is pretty much how the program works. Now let's give it a try yourself!\n\n  ";
}
int main() {
    int decision; string str;
   
    while(true){
        //Header, menu, and the footer for visual effects.
        cout << "--------------------------------------------Welcome to Brackets Verifier---------------------------------------------"<<endl;
        cout << "Menu:\n\n" << "- Press 1: How to use \n" << "- Press 2: Start Now \n" << "- Press 3: How it works \n" << "- Press 0 to exit\n\n";
        cout << "----------------------------------------Brax Wong Production (Version 1.0.0)-----------------------------------------"<<endl;
        //Storing the input into the variable decision
        cin >> decision;
        if(decision == 1){
            //A paragraph of text guiding the user
            howToUse();
        }
        else if(decision == 2){
            //To clear out the previous input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //Ask for input
            cout << "Please enter the text you need to verify.\n";
            getline(cin,str);
            //Verify the string for incorrect brackets placement and prompt the output
            verify(str);
            //Printing out the string
            cout << "Your string is: " << str << endl;
        }
        else if(decision == 3){
            //A paragraph of text describing how this program works
            howItWorks();
        }
        else if(decision == 0){
            //ending the program
            break;
        }
    }
    return 0;
}