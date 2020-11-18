  #include <bits/stdc++.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>    
  #include <sys/wait.h>
  #include <filesystem>
  #include <iostream>

using namespace std ; 
  char ** transform(string s)
  {
     int  p = 0;    
     char **command=  (char **)malloc(8 * sizeof(char *));;
     string temp ;
     for(int i =0;i<s.length();i++)
    { 
   
      if(i<s.length()-1&&s[i]==' '&&s[i+1]==' ')
        continue ;
      if(s[i]==' ') 
       { 
        command[p]= (char *) malloc(s.size()*sizeof(char));
      strcpy(command[p++], temp.c_str());
        temp.clear();
      }
      else if(s[i]!=' ')
      temp.push_back(s[i]);
          
    }
    command[p]= (char *) malloc(s.size()*sizeof(char));
    strcpy(command[p++], temp.c_str());
    command[p++]=NULL;
   return command;
  }

void handler(int signum)
{
    FILE *f;
    f = fopen("/home/islam/c++/log.txt", "a+");
    fprintf(f, "Child Process Terminated\n");
    fclose(f);
}



  int main() {
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));  
    int halt = 1 ;
    pid_t child_pid;
    int stat_code;
  while(1){
    cout<<cwd<<"$";
    halt = 1; 
  string s;
  getline(cin, s);
  if(s.substr(0,4)=="exit")
    break ;
  if(s[0]=='c'&&s[1]=='d')
  {
    s.erase(0,3);
    chdir(s.c_str());
     getcwd(cwd, sizeof(cwd));
     continue ;
  }


  if(s[s.size()-1]=='&')
  {
  s.pop_back();
  halt = 0 ;
   }
  char ** command  =transform(s);
  signal(SIGCHLD, handler);
  child_pid = fork();
        if (child_pid == 0) {
            int code ; 
            code =  execvp(command[0], command);
            printf("Error with command \n");
        } else if(halt){
            waitpid(child_pid, &stat_code, WUNTRACED);
        }

  }
}
 