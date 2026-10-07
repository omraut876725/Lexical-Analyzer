#include<stdio.h>
int syntax1(FILE *fp,double position)
{      fseek(fp,position,SEEK_SET);
    int ch;
    int open_brace=1;
    int close_brace=0;
   while((ch=getc(fp))!=EOF)
   {
    if(ch=='{')
    {   
        int ch1;
        while((ch1=fgetc(fp))!=EOF)
        {
          if(ch1=='/'&&(ch1=fgetc(fp))=='*')// for multiline checking
                {    int check;
                    int count;
                   
                    while((check=fgetc(fp))!=EOF)
                    {
                       if(check=='*'&&(check=fgetc(fp))=='/')
                       {
                        break;
                       }
                     
                    }
                  
                }
                else if(ch1=='/')
                {
                     while((ch=fgetc(fp))!='\n'&&ch!=EOF)
                   {
                     
                   }
                }
                 if(ch1=='"')//for checking or skiping the string literal
                {    int check;
                    while((check=fgetc(fp))!='"'&&check!=EOF)
                    {
                       if(check=='\\')
                        {   fgetc(fp);
                            continue;
                        }
                    }
                  
                }
               
                 
             
                  if(ch1=='{')
                {
                    open_brace++;
                }
                if(ch1=='}')
                {
                     close_brace++;
                    if(open_brace==close_brace)
                    {
                        return 0;
                    }
                   
                }
               
            
        }
    }
      if(open_brace!=close_brace)
      {
        return 1;
      }
    
    }
   return 0;
}


int syntax2(FILE *fp,double position)
{      fseek(fp,position,SEEK_SET);
    int ch;
    int open_brace=1;
    int close_brace=0;
   while((ch=getc(fp))!=EOF)
   {
    if(ch=='(')
    {   
        int ch1;
        while((ch1=fgetc(fp))!=EOF)
        {
          if(ch1=='/'&&(ch1=fgetc(fp))=='*')// for multiline checking
                {    int check;
                    int count;
                   
                    while((check=fgetc(fp))!=EOF)
                    {
                       if(check=='*'&&(check=fgetc(fp))=='/')
                       {
                        break;
                       }
                     
                    }
                  
                }
                else if(ch1=='/')
                {
                     while((ch=fgetc(fp))!='\n'&&ch!=EOF)
                   {
                     
                   }
                }
                 if(ch1=='"')//for checking or skiping the string literal
                {    int check;
                    while((check=fgetc(fp))!='"'&&check!=EOF)
                    {
                       if(check=='\\')
                        {   fgetc(fp);
                            continue;
                        }
                    }
                  
                }
               
                 
             
                  if(ch1=='(')
                {
                    open_brace++;
                }
                if(ch1==')')
                {
                     close_brace++;
                    if(open_brace==close_brace)
                    {
                        return 0;
                    }
                   
                }
               
            
        }
    }
      if(open_brace!=close_brace)
      {
        return 1;
      }
    
    }
   return 0;
}