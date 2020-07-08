#include "Calculator.h"

Calculator::Calculator(string infixExpression){
    stack = new Stack();
    this->infixExpression = infixExpression;
    this->postfixExpression = " ";

    string token;
    istringstream iss(this->infixExpression);
    iss >> token;

    while(token.compare(";") != 0) {
        StackItem *stackPtr =new StackItem(token);
        if(!stackPtr->isOperator){
            postfixExpression.append(stackPtr->toString()+" ");
        }
        else if(stackPtr->isOperator){
            if(stack->isEmpty()){
                stack->push(stackPtr);
            }
            else if(stackPtr->op == 0){
                stack->push(stackPtr);
            }
            else if(stackPtr->op == 1){
                while(!stack->isEmpty()){
                    if(stack->top()->op == 0){
                        stack->pop();
                        break;
                    }
                    else{
                        postfixExpression.append(stack->pop()->toString()+" ");
                    }
                }
            }
            else if(stack->top()->op < stackPtr->op){
                stack->push(stackPtr);
            }
            else if(stack->top()->op >= stackPtr->op){
                while(!stack->isEmpty()){
                    postfixExpression.append(stack->pop()->toString()+" ");
                    if(stack->isEmpty()){
                        stack->push(stackPtr);
                        break;
                    }
                    else if(stack->top()->op < stackPtr->op) {
                        stack->push(stackPtr);
                        break;
                    }
                }
            }
        }
        iss >> token;
    }
    while(!stack->isEmpty()){
        postfixExpression.append(stack->pop()->toString()+" ");
    }
    postfixExpression.append(";");
}



string Calculator :: getPostfix() {
    return this->postfixExpression;
}

Calculator::~Calculator(){
    delete stack;
    stack = 0;
}

int Calculator:: calculate() {
    string token;
    istringstream iss(this->postfixExpression);
    iss >> token;

    while(token.compare(";") != 0) {
        StackItem *stackPtr =new StackItem(token);
        if(!stackPtr->isOperator) {
            stack->push(stackPtr);
        }
        else if(stackPtr->isOperator){
            int numberF = stack->pop()->n;
            int numberS = stack->pop()->n;
            if(stackPtr->op == 2){
                int result = numberS - numberF;
                stack->push(new StackItem(to_string(result)));
            }
            else if(stackPtr->op == 3){
                int result = numberS + numberF;
                stack->push(new StackItem(to_string(result)));
            }
            else if(stackPtr->op == 4){
                int result = numberS / numberF;
                stack->push(new StackItem(to_string(result)));
            }
            else if(stackPtr->op == 5){
                int result = numberS * numberF;
                stack->push(new StackItem(to_string(result)));
            }
        }
        iss >> token;
    }
    return stack->pop()->n;
}
