 // 解析字符串
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXSIZE 100

typedef enum {
    FALSE, TRUE, EXIT
} result_t;

// 优先级高的操作符 乘除, 优先级低的操作符 加减, 其他如， 括号
enum prority {HIGH_PRORITY = 5, LOW_PRORITY = 4, OTHER_PRORITY = 3};
// 是否是括号，左右括号
enum brace {NON_BRACE, LEFT_BRACE, RIGHT_BRACE};


typedef struct ExpressionStack{
    // data[i][0]用来装运算符或数字，
    // data[i][1]用来作为是运算符('c')或数字('i')的标志
    int data[MAXSIZE][2]; 
    int top;   // 栈为空
} expression_stack_t;

// 判断是否是减号
result_t IsMinus(char exp_char) { // 是否是负号
    return exp_char == '-';
}
// 判断是否是四则运算
result_t IsArithSymbol(char exp_char) { // 是否是四则运算符号
    return (exp_char == '+' || exp_char == '*' ||
            exp_char == '/' || exp_char == '-');
}
// 判断是否是左右括号
int IsBrace(char exp_char) {           // 是否是'(', 还是')'
    if (exp_char == '(')
        return LEFT_BRACE;
    else if (exp_char == ')')
        return RIGHT_BRACE;
    else
        return 0;
}

// 初始化栈
result_t InitExpStack(expression_stack_t *eps) {
    eps->top = -1;
}
// 判断是否为空
result_t IsEmptyExpStack(expression_stack_t eps) {
    return eps.top == -1;
}
// 判断是否已满
result_t IsFullExpStack(expression_stack_t eps) {
    return eps.top == MAXSIZE - 1;
}
// 添加四则运算元素
result_t ExpStackPushChar(expression_stack_t *eps, char exp_char) {
    if (IsFullExpStack(*eps))
        return FALSE;
    eps->data[++(eps->top)][1] = 'c';
    eps->data[eps->top][0] = exp_char;
    return TRUE;
}
// 添加数字元素
result_t ExpStackPushInt(expression_stack_t *eps, int exp_int) {
    if (IsFullExpStack(*eps))
        return FALSE;
    eps->data[++(eps->top)][1] = 'i';
    eps->data[eps->top][0] = exp_int;
    return TRUE;
}
// 删除元素
int ExpStackPop(expression_stack_t *eps, int *top_data) {
    if (IsEmptyExpStack(*eps))
        return FALSE;
    *top_data = eps->data[eps->top][0];
    return eps->data[(eps->top)--][1];
}
// 判断表达式是否规范
result_t IsValid(char *exp) {
    if (exp[0] == '\0')     // 是否是空字符串
        return FALSE;

    int i = 0, isSymBrace = 0, isMinNum = 0; // 判断左右括号数目 判断是否为负数
    while (1) {
        if (exp[i] == '\0') {               // 字符串末尾
            if (IsArithSymbol(exp[i - 1]))
                return FALSE;
            break;
        }   
        else if (IsArithSymbol(exp[i])) {       // 是四则运算符
            if (i && IsArithSymbol(exp[i - 1])) // 如果两个运算符连在一起
                return FALSE;

            // 运算符是首字符 或 不是负号而且在左括号后面
            if (!IsMinus(exp[i]) && (i == 0 || IsBrace(exp[i - 1]) == 1))
                return FALSE;
            if (IsMinus(exp[i]) && isdigit(exp[i + 1]) &&
                 (i == 0 || IsBrace(exp[i - 1]) == 2)) {
                    // 是一个负数 '-x' '(-x' ; 是一个减号： 'x-x'
            }
        }
        else if (IsBrace(exp[i]) == 1) {    // 是左括号
            if (i && isdigit(exp[i - 1]))   // 前面是数字
                return FALSE;
            ++isSymBrace;
        }
        else if (IsBrace(exp[i]) == 2) {        // 是右括号
            if (isSymBrace < 0 || IsArithSymbol(exp[i - 1])) // ')..' '..+)'
                return FALSE;
            --isSymBrace;     
        }
        else if (isdigit(exp[i])) {     // 是数字
            if (i && IsBrace(exp[i - 1]) == 2) // 前面有右括号
                return FALSE;
        }
        else                            // 不是数字，是其他非法字符
            return FALSE;
        ++i;
    }

    // 括号数目对不对 
    return isSymBrace == 0;
}

// 运算符的优先级：乘除优先加减
int ProrityOfSymbol(char exp_char) {
    if (exp_char == '+' || exp_char == '-')
        return 1;
    else if (exp_char == '/' || exp_char == '*')
        return 2;
    else
        return 0;
}

void DisplayExpStack(expression_stack_t exp_stack) {
    for (int i = 0; i <= exp_stack.top; i++)
        if (exp_stack.data[i][1] == 'c')
            printf("%c ", exp_stack.data[i][0]);
        else
            printf("%d ", exp_stack.data[i][0]);

    putchar('\n');
} 
// 中缀表达式字符串 转化成 后缀表达式栈
void SufToInf(char *infix_exp, expression_stack_t *suffix_stack) {
    expression_stack_t t_expstack;
    InitExpStack(&t_expstack);
    int i = -1, isMinNum = 0; // 判断是否为负数
    while (infix_exp[++i] != '\0') { // 如果栈不为空
        // 如果是数字
        // printf("---- %c ---- ", infix_exp[i]);
        if (isdigit(infix_exp[i])) {
            int t_num = infix_exp[i] - '0';
            while (isdigit(infix_exp[i + 1])) {
                t_num *= 10;
                t_num += infix_exp[++i] - '0';
            }
            if (isMinNum) {        // 是负数
                t_num = - t_num;
                isMinNum = 0;
            }   
            ExpStackPushInt(suffix_stack, t_num);
            // printf("isdigit\n");
        }
        else if (IsBrace(infix_exp[i]) == 1) { // 左括号入栈入栈
            ExpStackPushChar(&t_expstack, infix_exp[i]);
            // printf("t_: ");
            // DisplayExpStack(t_expstack);
            // printf("left brace\n");
        }
        else if (ProrityOfSymbol(infix_exp[i]) == 2) { // 优先级高的运算符
            int pop_data = -1;
            // 把栈里的高级运算符 * /，都输出
            while (!IsEmptyExpStack(t_expstack)) {
                ExpStackPop(&t_expstack, &pop_data);
                if (ProrityOfSymbol(pop_data) < 2) {
                    ExpStackPushChar(&t_expstack, pop_data);
                    break;
                }
                else
                    ExpStackPushChar(suffix_stack, pop_data);
            }
            // 再把这个操作符放进栈里面
            ExpStackPushChar(&t_expstack, infix_exp[i]);
            // printf("t_: ");
            // DisplayExpStack(t_expstack);
            // printf("high symbol\n");
        }
        else if (IsBrace(infix_exp[i]) == 2) {    // 右括号
            // 依次把栈中的的运算符加入后缀表达式中
            // 直到出现'('，从栈中删除'(' 
            int pop_data;
            ExpStackPop(&t_expstack, &pop_data);
            while (pop_data != '(') {
                // printf("t_: ");
                // DisplayExpStack(t_expstack);
                
                ExpStackPushChar(suffix_stack, pop_data);
                ExpStackPop(&t_expstack, &pop_data);
                // printf("t_: ");
                // DisplayExpStack(t_expstack);
                // DisplayExpStack(*suffix_stack);
            }
            
        }
        else {  
            // 不是优先级高的运算符
            // 则将从栈顶到第一个优先级等于它的运算符（或 '(',但优先满足前一个条件）
            // 之间的运算符加入后缀表达式中，该运算符再入栈
            if (IsMinus(infix_exp[i]) && isdigit(infix_exp[i + 1]) &&
                 (i == 0 || IsBrace(infix_exp[i - 1]) == LEFT_BRACE)) {
                    isMinNum = 1; // 是一个负数 '-x' '(-x' ; 是一个减号： 'x-x' ‘x-(''
                    continue;
            }

            int pop_data = -1;                             
            while (!IsEmptyExpStack(t_expstack)) {
                ExpStackPop(&t_expstack, &pop_data);
                // ExpStackPushChar(suffix_stack, pop_data);
                if (pop_data == '(') {
                    ExpStackPushChar(&t_expstack, '(');
                    // ExpStackPop(suffix_stack, &pop_data);
                    break;
                }
                else
                    ExpStackPushChar(suffix_stack, pop_data);
            }
                
            ExpStackPushChar(&t_expstack, infix_exp[i]);

        }
        // DisplayExpStack(*suffix_stack);
        // printf("t_: ");
        // DisplayExpStack(t_expstack);
        // printf("others.\n");
    }
    while (!IsEmptyExpStack(t_expstack)) {
        int pop_data;
        ExpStackPop(&t_expstack, &pop_data);
        ExpStackPushChar(suffix_stack, pop_data);
    }
}

typedef enum {
    SUCCESS, DIVIDEDBYZERO, OVERFLOW 
} cal_result_t;

result_t IsOverFlow(double result) {
    double INT_MIN = -2147483648, INT_MAX = 2147483647;
    return result > INT_MAX || result < INT_MIN;
}

result_t ExpStackPushDouble(expression_stack_t *eps, int exp_double) {
    if (IsFullExpStack(*eps))
        return FALSE;
    eps->data[++(eps->top)][1] = 'd';
    eps->data[eps->top][0] = exp_double;
    return TRUE;
}

cal_result_t Calculator(expression_stack_t suffix_stack, double *cal_result) {
    expression_stack_t t_expstack;
    InitExpStack(&t_expstack);
    double result;
    for (int i = 0; i <= suffix_stack.top; i++) {
        if (suffix_stack.data[i][1] == 'i') {   // 如果是数字
            ExpStackPushDouble(&t_expstack, suffix_stack.data[i][0]);
        }
        else if (suffix_stack.data[i][1] == 'c') {
            int pop_data1, pop_data2;
            ExpStackPop(&t_expstack, &pop_data1);
            ExpStackPop(&t_expstack, &pop_data2);
             double data1 = pop_data1, data2 = pop_data2;
            switch (suffix_stack.data[i][0]) {
                case '+' :
                    result = data2 + data1;
                    break;
                case '-':
                    result = data2 - data1;
                    break;
                case '/':
                    if (data1 == 0)
                        return DIVIDEDBYZERO; 
                    result = data2 / data1;
                    break;
                case '*':
                    result = data2 * data1;
                    break;
            }
            if (IsOverFlow(result))
                return OVERFLOW;
            else {
                ExpStackPushDouble(&t_expstack, result);
                // printf("%lf %c %lf = %lf\n", data2, suffix_stack.data[i][0], data1, result);
                // DisplayExpStack(t_expstack);
            }
        }
    }
    *cal_result = result;
    return SUCCESS;
}

int main() {
    // char exp[MAXSIZE];
    // scanf("%s", exp);
    char exp[30][MAXSIZE] = {
        "3/7*49/9-4/3",
        "8/9*15/36+1/27",
        "12*5/6-2/9*3",
        "8*5/4+1/4",
        "6/3/8-3/8/6",
        "4/7*5/9+3/7*5/9",
        "5/2-(3/2+4/5)",
        "7/8+(1/8+1/9)",
        "9*5/6+5/6",
        "5/2-(3/2+4/5)",
        "(1+2+6)/9*4-(5/0)",      // 正确       
        "((11+44)/4312",        // 括号数目不对
        "1+2)/3*4-(5/6)",       // 括号数目不对  
        "+1*2+23/23+(23+21)*(-1)",   // 正确
        "(1+34)/7+(5+(-24/6)+8/(1+(2*4-1)))",     // = 7 perfect!
        "12+920+(*9)",          // (*9)
        "/1+2)/3*4-(5/6)",      // /1
        "*1+2)/3*4-(5/6)",      // *1
        "(/1+2)/3*4-(5/6)",     // (/1)
        "(*1+2)/3*4-(5/6)",     // (*1)
        "(-112+32*23+23/32)",
        "034+8*32-32+65",
        "-00221/124+820",
        "0+8/3+8*7(87)23+5",     // Error!
        "9+(3-1)*3+10/2"
    };

    int i = 0;
    while (i != 15) {
        expression_stack_t t_exp;
        InitExpStack(&t_exp);
       if (IsValid(exp[i])) {
           printf("Correct!\n");
            printf("EXP: %s\n", exp[i]);
            SufToInf(exp[i], &t_exp);
            // DisplayString(exp[1 - 1]);
            // SufToInf(exp[1 - 1], &t_exp);
            DisplayExpStack(t_exp);
            double result;
            int cal_result = Calculator(t_exp, &result);
            switch (cal_result) {
                case SUCCESS:
                    printf("PERFECT! The result is %f\n", result);
                    break;
                case DIVIDEDBYZERO:
                    printf("Divided by zero!\n");
                    break;
                case OVERFLOW:
                    printf("OVERFLOW!\n");
                    break;
            }
            printf("----------\n");
        }   
        else 
            printf("Error!\n");
        ++i;
    }

    printf("Done!\n");
    return 0;
}   