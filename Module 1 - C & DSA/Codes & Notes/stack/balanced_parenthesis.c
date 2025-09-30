#include <stdio.h>
#include <stdlib.h>
struct stack {
    int top;
    char *p;
};
int balanced(char a,char b)
{
    if(a=='(' && b==')') return 1;
    else if(a=='{' && b=='}') return 1;
    else if(a=='[' && b==']') return 1;

    return 0;

}
void balanced_parenthesis(struct stack s1,int n,char ch[],char res[])
{
    int j=0;
    for(int i=0;i<n;i++)
    {
        char s=ch[i];
        if(s=='(' || s=='{' || s=='[')
        {
            s1.p[++s1.top]=s;
        }
        else if(s==')' || s=='}' || s==']')
        {
            if(balanced(s1.p[s1.top],s))
            s1.p[s1.top--];
            else
            break;
        }
    }
    if(s1.top==-1) 
    printf("Balanced Parenthesis\n");
    else
    printf("Unbalanced Parenthesis\n");
}
int main()
{
    struct stack s;
    s.top=-1;
    int n;
    printf("Enter the length of the string\n");
    scanf("%d\n",&n);
    s.p=(char*)malloc(n*sizeof(int));
    char ch[n],res[n];
    for(int i=0;i<n;i++)
    {
        scanf("%c",&ch[i]);
    }
    balanced_parenthesis(s,n,ch,res);
    free(s.p);
    return 0;

}