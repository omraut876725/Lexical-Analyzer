/*
 * ========================================================================
 *                         PROJECT DESCRIPTION
 * ========================================================================
 *
 * Project Name : C Lexical Analyzer
 *  Name : Om Raut 
 *  Date : 
 *  Batch Id: 26019f_009
 * Description :
 *
 * This project is a C-based Lexical Analyzer designed to analyze a
 * C source-code file and identify different types of lexical tokens
 * present in the source program.
 *
 * The program accepts the C source file as a command-line argument,
 * opens the file using file-handling functions, and reads the source
 * code line by line. Each line is then processed character by character
 * to separate individual lexemes and classify them according to their
 * type.
 *
 * The Lexical Analyzer identifies and classifies the following tokens:
 *
 * 1. Keywords
 *    Identifies C keywords such as int, char, float, if, else, for,
 *    while, return, static, struct, etc.
 *
 * 2. Identifiers
 *    Identifies variable names, function names, and other user-defined
 *    identifiers.
 *
 * 3. Constants
 *    Identifies integer and floating-point constants and performs basic
 *    validation of numeric values.
 *
 * 4. Operators
 *    Identifies arithmetic, relational, logical, bitwise, assignment,
 *    increment/decrement, and other C operators such as +, -, *, /,
 *    ==, !=, >=, <=, &&, ||, ++, --, +=, -=, etc.
 *
 * 5. Delimiters
 *    Identifies delimiters and special symbols such as parentheses,
 *    braces, square brackets, comma, semicolon, and colon.
 *
 * 6. String Literals
 *    Detects string literals enclosed within double quotation marks
 *    and checks whether the closing quotation mark is present.
 *
 * 7. Character Constants
 *    Identifies character constants enclosed within single quotation
 *    marks and validates normal and escape-sequence characters.
 *
 * 8. Comments
 *    Detects and ignores single-line comments beginning with // and
 *    multi-line comments enclosed between /* and */ /*so that tokens
 *    present inside comments are not processed.
 *
 * 9. Preprocessor Directives
 *    The analyzer skips preprocessor directives such as #include
 *    and #define because they are not considered as normal lexical
 *    tokens in this project.
 *
 * 10. Invalid Tokens
 *     Characters or combinations that do not match the defined lexical
 *     rules are reported as invalid tokens.
 *
 * Basic Syntax Checking :
 *
 * The project also performs basic syntax checking for matching opening
 * and closing braces {} and parentheses (). While performing this check,
 * braces and parentheses present inside comments and string literals
 * are ignored to avoid incorrect error detection.
 *
 * File Handling :
 *
 * The project uses C file-handling functions such as fopen(), fclose(),
 * fgets(), fgetc(), ftell(), and fseek() to read and process the source
 * file and to perform syntax checking from specific file positions.
 *
 * Concepts Used :
 *
 * - C Programming
 * - File Handling
 * - Strings and Character Arrays
 * - Pointers
 * - Functions
 * - Arrays
 * - Command Line Arguments
 * - String Handling Functions
 * - Character Classification Functions
 * - File Position Handling
 * - Basic Syntax Checking
 *
 * Output :
 *
 * The analyzer displays the identified lexemes in a structured table
 * along with their corresponding token types. It also displays errors
 * when invalid tokens, incomplete strings, or missing closing braces
 * and parentheses are detected.
 *
 * ========================================================================
 */




#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "search.h"
int main(int argc, char *argv[])
{      if(argc!=2)
   {
    printf("Usage: ./a.out <filename>\n");
    return 0;
   }
    FILE *fp;
   fp = fopen(argv[1], "r");
  
   
   if(fp==NULL)
   { printf("File cannot be opened\n");
    return 1;
   }
  
  
   {printf("==========================================================\n");
printf("                    LEXICAL ANALYZER\n");
printf("==========================================================\n\n");

printf("%-35s%-15s\n", "Lexeme", "Token");
printf("----------------------------------------------------------\n");
}
    char str[200];
    int tem=0;//for searching the multiline comment
  while(1)
  {   long int start=ftell(fp);
     if(fgets(str, sizeof(str), fp)== NULL)
         break;
         long int orignal=ftell(fp);
    if(strstr(str,"#include") != NULL)//for skip the header file
    {
        continue;
    }
    else if(strstr(str,"#define") != NULL)//for skip the macros
    {
        continue;
    }
    else if(str[0]== '\n')//skip the empty line;
    {
        continue;
    }
    
for(int i=0; i<strlen(str); i++)
    {
      if(str[i]=='/'&&str[i+1]=='/')//skip the single line comment 
      {
        break;
      }
      if(str[i]=='/'&&str[i+1]=='*')//check multiline commment
        {
          tem=1;
          continue;
        }
         if(str[i]=='*'&&str[i+1]=='/')
        {
          tem=0;
          i=i+2;
          
        }
        if(tem>0)//skip loop until '*/' not found
        {
          continue;
        }
        
        
char pass[50];
  if(str[i]=='\n'||str[i]=='\t')
    {
     continue;
    }
    // for string search
    else if(str[i]=='"')//for string search
    {   int count=0;//for indexing of pass
      int flag=0;// for checking the " 
    int j=i;
      while(str[j]!='\n'&&flag<2&&str[j]!='\0')
      {    if(str[j]=='"')
        {
            flag++;
        }
        
           pass[count]=str[j];
           j++;
           i++;
            count++;
           
      }
       pass[count]='\0';
     if(flag!=2)
     {
       printf("%-50s\n","Error: \" missing");
     }
     else
     {
       search(pass); 
     }
     
    i--;
    }
    /* char constant*/
    
  else if(str[i]=='\'')
    { int count=0;
      do
      {
        pass[count]=str[i];
        count++;
        i++;

      }
      while(str[i]!='\'');
      pass[count]='\'';
      count++;
      pass[count]='\0';
      charconstant(pass);

    }
  /* Keyword / Identifier / Constant */
  else if(isalnum(str[i])!=0||str[i]=='_'||str[i]=='.')
  { 
     int count=0;
    int j=i;
  for(j=i;isalnum(str[j])!=0||str[j]=='_'||str[j]=='.';j++)
  {
    pass[count]=str[j];
    count++;
  }
  pass[count]='\0';
  i=j-1;
     search(pass);
  }
  /* Space */
  else if(str[i]==' ')
  {
    continue;
  }
  /* Operator / Delimiter / Other symbol */
  
   else
    {
       static char *operators[]=
    {
        "=","+","-","*","/","%",">","<","!","&","|","^","~","?"
    };
      int count=0;
      pass[count]=str[i];
     /* for { checking*/
      {if(str[i]=='{')
      {  
        double position=start+i;
       int value= syntax1(fp,position);
       if(value==0)
       {
         fseek(fp,orignal,SEEK_SET);
       }
      else if(value==1)
       {
        printf("%-35s%-15s\n", "Error : ", "}missing");
          fseek(fp,orignal,SEEK_SET);
          continue;
       }
       
      }
      }
      /*for ( checking*/

      {if(str[i]=='(')
      {  
        double position=start+i;
       int value= syntax2(fp,position);
       if(value==0)
       {
         fseek(fp,orignal,SEEK_SET);
       }
      else if(value==1)
       {
        printf("%-35s%-15s\n", "Error : ", ")missing");
          fseek(fp,orignal,SEEK_SET);
          continue;
       }
       
      }
      }
       int len=sizeof(operators)/sizeof(operators[0]);
      int flag=0;
      for(int j=0;j<len;j++)
      {
        if(strchr(operators[j],str[i])!=NULL)//check the character is opearator ""single char operator""
        {    
             flag=1;
             break;
        }
      }
      if(flag==1)
      {
      
      for(int j=0;j<len;j++)
      {
        if((i+1)<strlen(str)&&strchr(operators[j],str[i+1])!=NULL)//check the character is opearator ""Double char operator""
        {    count++;
           pass[count]=str[i+1];
           i++;
        }
      }
       for(int j=0;j<len;j++)
      {
        if((i+1)<strlen(str)&&strchr(operators[j],str[i+1])!=NULL)//check the character is opearator ""triple char operator""
        {    count++;
           pass[count]=str[i+1];
           i++;
        }
      }
    }
    count++;
    pass[count]='\0';
    search(pass);
     }
    }
  
   
   
}
{
printf("----------------------------------------------------------\n");
printf("                    END OF ANALYSIS\n");
printf("==========================================================\n");
}
 fclose(fp);

    return 0;	
}

