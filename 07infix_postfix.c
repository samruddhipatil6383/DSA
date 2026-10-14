#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int priority(char x)
{
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char infix[100], postfix[100], x;
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    for(i = 0; infix[i] != '\0'; i++)
    {
        x = infix[i];

        if(isdigit(x))
            postfix[j++] = x;

        else if(x == '(')
            push(x);

        else if(x == ')')
        {
            while(top != -1 && stack[top] != '(')
                postfix[j++] = pop();

            if(top != -1)
                pop();
        }
        else
        {
            while(top != -1 && stack[top] != '(' &&
                  priority(stack[top]) >= priority(x))
                postfix[j++] = pop();

            push(x);
        }
    }

    while(top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    int values[100], t = -1, a, b;

    for(i = 0; postfix[i] != '\0'; i++)
    {
        x = postfix[i];

        if(isdigit(x))
            values[++t] = x - '0';
        else
        {
            if(t < 1)
            {
                printf("Invalid expression\n");
                return 0;
            }

            b = values[t--];
            a = values[t--];

            if(x == '+') values[++t] = a + b;
            else if(x == '-') values[++t] = a - b;
            else if(x == '*') values[++t] = a * b;
            else if(x == '/')
            {
                if(b == 0)
                {
                    printf("Division by zero\n");
                    return 0;
                }
                values[++t] = a / b;
            }
        }
    }

    if(t == 0)
        printf("Result: %d\n", values[t]);
    else
        printf("Invalid expression\n");

    return 0;
}
