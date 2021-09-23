#include<bits/stdc++.h>
#include <fstream>
using namespace std;

vector <char> vec;

struct input{
	char Testfile[1000];
	int level;
}; 

void identify(int n){
	if(n==0){
	vec.back('s');
	} 
	
    else if(n==7){
	vec.back('c');
	} 
}

int main(){
  int level, Workbench;
  int size = 1000;
  char Testfile[size];
  int TotalNum = 0;
  int NoPointSwitch = 0, INum = 0, ENum = 0;
  int SwitchNum = 0, IfElseNum = 0, IfElseIfNum = 0; 
  int CaseNumArr[1000];
  int w;
  input UserInput;
  string word;
  string test = "while, volatile, switch, case, else, if, sizeof, auto, break, char, const, continue, default, do, double, enum, extern, float, for, goto, int, long, register, return, short, signed, static, struct, typedef, union, unsigned, void";  
  string IFAndElse[5]={"else if", "else ", "else{", "if(", "if "}; 
  fstream infile, anofile;
  cout << "Please enter the root of the file: "; 
  cin.getline(UserInput.File, size);
  cout << "Please enter the to inquire£º";
  cin >> UserInput.level;
  infile.open(UserInput.File);
  anofile.open(UserInput.File); 
  int i;
  
//LEVEL 1
  if (!infile.is_open()){
  exit(EXIT_FAILURE);
  }
  infile >> word;
  for(;!infile.eof();){
      if (infile.good()){
      	for(i=2; i<9; i++){
      	  Workbench = test.find(word.substr(0, i));
      	  if(WordTop<test.size()&&(word[i]==NULL||word[i]=='!'||word[i]=='('||word[i]==')'||word[i]=='{'||word[i]=='}'||word[i]==';'||word[i]==':')){
      	  	TotalNum++;  
      	  	identify(WordTop);
      	  	break;
			}
		  }
        infile >> word;
        }
    }
    cout << "total num: " << TotalNum << endl;
    
    for(int j=0; j<vec.size(); j++){
 	  if(vec[j]=='s' && vec[j+1]=='c'){
 	  	CaseNumArr[NoPointSwitch]=0;
 	  	SwitchNum++; 	  	
	    }  
      else if(vec[j]=='c' && vec[j+1]=='s'){
	   	 CaseNumArr[NoPointSwitch]++;
	   	 NoPointSwitch++;
	    }
	  else{
	   	CaseNumArr[NoPointSwitch]++;
	    }
	}
	
//LEVEL 2
	if(UserInput.level>1){
	  cout << "switch num: " << SwitchNum << endl;
	  cout << "case num: ";
      for(int k=0; k<=NoPointSwitch; k++)
      {
           cout << ' ' << CaseNumArr[k];
      }
      
//LEVEL 3
      if(UserInput.level>2){
      	cout << endl;		  
	    vec.erase(vec.begin(),vec.end()); 
	    while(getline(anofile,word)){ 
            for(int a=0; a<5; a++){
          	w=word.find(IFAndElse[a]);
          	if(w!=-1){
          	  if(a==0){
          	  	vec.push_back('0');
          	  	break;
				}
          	  else if(a==1 || a==2){
          	  	vec.push_back('e');
          	  	break;
				} 
          	  else{
          	  	vec.push_back('i');
          	  	break;
			    }
			}
		  } 
	    }
	    for(int w=0; w<vec.size(); w++){
	      if(vec[w]=='i') 
	        INum++;
	      else if(vec[w]=='e'){
	      	if(ENum==0 && INum>0){
              IfElseNum++;
	      	  INum--;
			  }
		  else if(ENum>0){
			  ENum--;
			  IfElseIfNum++;
			  }
		    }
	 	  else if(vec[w]=='0'){
		 	if(vec[w-1]!='0'){
				INum--;
				if(INum<0)
                {
                    INum=0;
                } 
				ENum++;	
			  }
		    }
		  }
          cout << "if-else num: " << IfElseNum << endl;
          
//LEVEL 4
          if(UserInput.level==4){
		  cout << "if-elseif-else num: " << IfElseIfNum << endl;	
	    }
	}
	  }
	  
  return 0;
}
