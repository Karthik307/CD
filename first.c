#include<stdio.h>
struct pro{
char s[1];
char p[10];
}g[10];
int n;
int main()
{
int i,j=0,t=0,f=0;
printf("Enter number of productions\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("LHS: ");
scanf("%s",&g[i].s[0]);
printf("\nRHS: ");
scanf("%s",g[i].p);
}
for(i=0;i<n;i++)
{
printf("First of %c is: ",g[i].s[0]);
first(g[i].s[0],i);
printf("\n");
}
printf("\n\n");
for(i=0;i<n;i++)
{
printf("Follow of %c is: ",g[i].s[0]);
follow(g[i].s[0],'$');
printf("\n");
}
return 0;
}
void first(char l,int x)
{
int i;
if(isupper(g[x].p[0]))
{
for(i=0;i<n;i++)
{
if(g[x].s[0]==g[x].p[0])
break;
if(g[i].s[0]==g[x].p[0])
first(g[x].p[0],i);
}
}
else
{
printf("%c ",g[x].p[0]);
}
}
void follow(char k,char temp)
{
if(k==temp)
return ;
temp=k;
int i,j=0,z;
if(k==g[0].s[0])
printf("$ ");
for(i=0;i<n;i++)
{
j=0;
while(g[i].p[j]!='\0')
{
if(g[i].p[j]==k)
{
if(g[i].p[j+1]=='\0')
follow(g[i].s[0],temp);
else if(isupper(g[i].p[j+1]))
{
for(z=0;z<n;z++)
if(g[z].s[0]==g[i].p[j+1])
first(g[z].s[0],z);
}
else
printf("%c ",g[i].p[j+1]);
}
j++;
}
}
}

