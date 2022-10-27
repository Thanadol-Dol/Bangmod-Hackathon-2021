#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void addspace(char *sen){
	int i,count;
	char temp[50]="";
	for(i=0,count=0;i<strlen(sen);i++){
		if(strchr("#*",sen[i])!=NULL){
			temp[count++]=' ';
			temp[count++]=sen[i];
			temp[count++]=' ';
		}
		else
		temp[count++]=sen[i];
	}
	strcpy(sen,temp);
}
void addspace2(char word[][50],char *test){
	int i,j,count,flag=1,countword;
	char temp[50]="";
	if(strcmp(word[0],"#")==0||strcmp(word[0],"*")==0)
	countword=1;
	else
	countword=0;
	for(i=0,count=0;i<strlen(test);){
		if(test[i]==word[countword][0]){
			for(j=1;j<strlen(word[countword]);j++){
				if(test[i+j]!=word[countword][j]){
					flag=1;
					break;
				}
				else
				flag++;
			}
		}
		if(flag==strlen(word[countword])){
			temp[count++]=' ';
			strcat(temp,word[countword]);
			count+=strlen(word[countword]);
			temp[count++]=' ';
			i=i+strlen(word[countword]);
			flag=1;
			countword+=2;
		}
		else
		temp[count++]=test[i++];
	}
	strcpy(test,temp);
}
int split(char *sen,char word[][50]){
	int count;
	char *tok;
	tok=strtok(sen," ");
	while(tok!=NULL)
	{
		strcpy(word[count++],tok);
		tok=strtok(NULL," ");
	}
	return count;
}
main(){
	int count1=0,count2=0,i,flag;
	char *tok,sen[50],wordprob[10][50],wordtest[10][50];
	gets(sen);
	addspace(sen);
	count1=split(sen,wordprob);
	while(strcmp(sen,"QUIT")!=0){
		flag=1;
		gets(sen);
		if(count1==1&&strcmp(sen,"QUIT")!=0){
			if(strcmp(sen,wordprob[0])==0)
			printf("YES\n");
			else
			printf("NO\n");
		}
		else{
			if(strcmp(sen,"QUIT")!=0){
				addspace2(wordprob,sen);
				count2=split(sen,wordtest);
				if(strcmp(wordprob[0],"#")==0||strcmp(wordprob[0],"*")==0){
					for(i=1;i<count1;i+=2)
					if(strcmp(wordprob[i],wordtest[i])!=0)
					flag=0;
					if(flag==1){
						for(i=0;i<count1;i+=2){
							if(strcmp(wordprob[i],"#")==0&&(strlen(wordtest[i]))%2==0)
							flag=0;
							else if(strcmp(wordprob[i],"*")==0&&(strlen(wordtest[i]))%2==1)
							flag=0;
						}
					}
				}
				else if(strcmp(wordprob[0],"#")!=0||strcmp(wordprob[0],"*")!=0){
					for(i=0;i<count1;i+=2)
					if(strcmp(wordprob[i],wordtest[i])!=0)
					flag=0;
					if(flag==1){
						for(i=1;i<count1;i+=2){
							if(strcmp(wordprob[i],"#")==0&&(strlen(wordtest[i]))%2==0)
							flag=0;
							else if(strcmp(wordprob[i],"*")==0&&(strlen(wordtest[i]))%2==1)
							flag=0;
						}
					}
				}
				if(flag==0)
				printf("NO\n");
				else
				printf("YES\n");
			}
		}
	}while(strcmp(sen,"QUIT")!=0);
}
