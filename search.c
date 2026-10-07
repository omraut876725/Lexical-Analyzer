#include<stdio.h>
#include<string.h>
#include<ctype.h>

#include "search.h"

 
   void  search(char *pass)
   {
    static char *keywords[]=
    {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else",
        "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return",
        "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",
        "void", "volatile", "while"
    };
    static char *operators[]=
    {
        "+","-","*","/","%","++","--","=","+=","-=","*=","/=","%=","==","!=",
">","<",">=","<=","&&","||","!","&","|","^","~","<<",">>","&=","|=","^=",
"<<=",">>=","->","?"
    };
    static char *delimiters[]=
    {
    "\t","\n",",",";","(",")","{","}","[","]",":"
    };
    
    int left = 0;
    int right= sizeof(keywords) / sizeof(keywords[0])-1;  // length of keyword
   while(left<=right)
   {
    //checking the input string  is keyword or not 
    if(strcmp(pass, keywords[left])==0)
    {
        printf("%-35s%-15s\n", pass, "Keyword");
        return;
    }
    else if(strcmp(pass, keywords[right])==0)
    {
        printf("%-35s%-15s\n", pass, "Keyword");
        return;
    }
    left++;     
    right--;
   }
   left = 0;
    right= sizeof(operators) / sizeof(operators[0])-1;//length of operator
    
    while(left<=right)
   {
    //checking input string is operator or not
    if(strcmp(pass, operators[left])==0)
    {
        printf("%-35s%-15s\n", pass, "Operator");
        
        return;
    }
    else if(strcmp(pass, operators[right])==0)
    {
        printf("%-35s%-15s\n", pass, "Operator");
        
        return;
    }
    left++;     
    right--;
   }
   left = 0;
    right= sizeof(delimiters) / sizeof(delimiters[0])-1;//length of delimiters
    while(left<=right)
   {
        //checking input string is delimeters or not

    if(strcmp(pass, delimiters[left])==0)
    {   
        printf("%-35s%-15s\n", pass, "Delimiter");
        return;
    }
    else if(strcmp(pass, delimiters[right])==0)
    {
        printf("%-35s%-15s\n", pass, "Delimiter");
        return;
    }
    left++;     
    right--;
   }
   /* for string letreal printing*/
   if(pass[0]=='"')
   {
    int flag=0;
   
    printf("%-35s%-15s\n", pass, "String Literal");//if pass[0] is " then we print whole string 
         return ;
   }
  if(isdigit(pass[0])!=0||pass[0]=='.')//for constant checking;
  {   int count=0;
    int flag=0;
    for(int i=0;pass[i]!='\0';i++)
    {
        if(isdigit(pass[i])==0)
        {
            count++;
            if(pass[i]=='.')
            {
                flag++;
            }
        }
    }
    
    if(flag<=1)
    {
         printf("%-35s%-15s\n", pass, "Constant");
         return ;
    }
    else{
         printf("%-35s%-15s\n", pass, "Invalid Token");// more than 1  . operator in single digit
    }
    
  }
 
      
    
    
   else if(pass[0]=='_'||isalnum(pass[0])!=0)
   {
    printf("%-35s%-15s\n", pass, "Identifier");
   }
   else
   {
    
   printf("%-35s%-15s\n", pass, "Invalid Token");
   }
}
/* for character constant checking*/
void charconstant(char *pass)
{
      if(pass[0] == '\'' )
    {   static char *constant[]={"n","t","r","b","f","v","a","0"};
        int len=sizeof(constant)/sizeof(constant[0]);
       int count=0;
        if(pass[count+1]=='\\')
        { 
         for(int i=0;i<len;i++)
         {
            if(strchr(constant[i],pass[count+2])!=NULL)
            {
                if(pass[count+3]=='\'')
                {
                     printf("%-35s%-15s\n", pass, "Character Constant");
                     return;
                }
               
            }
        }
       
          printf("%-35s%-15s\n", pass, "Invalid Character");
        }
      else if(pass[count+2]=='\'')
        {
           printf("%-35s%-15s\n", pass, "Character Constant");
        }
        else
        {
             printf("%-35s%-15s\n", pass, "Invalid Character");

        }
}
}

