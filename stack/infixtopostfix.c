#include <stdio.h>
#include <stdlib.h>
struct stack{
  int top;
  char *p;
};
int precedence(char ch)
{
  if(ch=='/' || ch=='*') 
  return 2;
  else if(ch=='+' || ch=='-') 
  return 1;
  else
  return 0;
}
void infix_topostfix(struct stack s1,int n, char ch[],char res[])
{
  int j=0;
  for(int i=0;i<n;i++)
  {
    char s=ch[i];
    if(s>='A' && s<='Z' || s>='a' && s<='z' || s>='0' && s<='9')
    res[j++]=s;

    else if(s=='(')
    s1.p[++s1.top]=s;

    else if(s==')')
    {
      while(s1.top!=-1 && s1.p[s1.top]!='('){
      res[j++]=s1.p[s1.top--];
      }
    if(s1.top!=-1 && s1.p[s1.top]=='(')
    s1.top--;
    }

    else{
      while(s1.top!=-1 && precedence(s1.p[s1.top])>=precedence(s))
      {
         res[j++]=s1.p[s1.top--];
      }
      s1.p[++s1.top]=s;
    }
}
while(s1.top!=-1)
{
  res[j++]=s1.p[s1.top--];
}
res[j]='\0';
printf("%s",res);
}
int main()
{
  struct stack s;
  int n;
  // printf("Enter the length\n");
  scanf("%d\n",&n);
  s.top=-1;
  s.p=(char*)malloc(n*sizeof(char));
  char res[n],ch[n];
  for(int i=0;i<n;i++)
  {
    scanf("%c",&ch[i]);
  }
  infix_topostfix(s,n,ch,res);
  free(s.p);
  return 0;
}