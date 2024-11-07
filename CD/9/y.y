%{
    #include<stdio.h>
    int flag = 0;
    int yylex(void);
    void yyerror(const char *s);
%}
%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%
ArithmeticExpression: E { printf("\nResult = %d\n", $$); return 0; };
E: E '+' E { $$ = $1 + $3; }
 | E '-' E { $$ = $1 - $3; }
 | E '*' E { $$ = $1 * $3; }
 | E '/' E { $$ = $1 / $3; }
 | E '%' E { $$ = $1 % $3; }
 | '(' E ')' { $$ = $2; }
 | NUMBER { $$ = $1; };
%%
void main() {
    printf("\nEnter an Arithmetic Expression: ");
    yyparse();
}
void yyerror(const char *s) {
    printf("\nEntered arithmetic expression is Invalid: %s\n", s);
    flag = 1;
}
