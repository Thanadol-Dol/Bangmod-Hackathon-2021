#include<stdio.h>
#include<string.h>
void delete_str(char str[],int *n){
	int i;
	for(i=0;i<*n;i++)
	str[i]=str[i+1];
}
main(){
	char ele[50],func[20];
	gets(ele);
	int i,j=0,num=0,esmark=0,etmark=0,kemark=0;
	for(i=0;i<strlen(ele);i++){
		if(ele[i]=='C'&&ele[i+1]>='2'&&ele[i+1]<='9')
		num=num+(12*(ele[i+1]-'0'));
		else if(ele[i]=='C'&&(ele[i+1]=='H'||ele[i+1]=='O'||ele[i+1]<='N'))
		num+=12;
		else if(ele[i]=='H'&&ele[i+1]>='2'&&ele[i+1]<='9')
		num=num+(ele[i+1]-'0');
		else if(ele[i]=='H'&&(ele[i+1]>='C'||ele[i+1]<='O'||ele[i+1]<='N'))
		num+=1;
		else if(ele[i]=='O'&&ele[i+1]>='2'&&ele[i+1]<='9')
		num=num+(16*(ele[i+1]-'0'));
		else if(ele[i]=='O'&&(ele[i+1]>='C'||ele[i+1]<='H'||ele[i+1]<='N'))
		num+=16;
		else if(ele[i]=='N'&&ele[i+1]>='2'&&ele[i+1]<='9')
		num=num+(14*(ele[i+1]-'0'));
		else if(ele[i]=='N'&&(ele[i+1]>='C'||ele[i+1]<='H'||ele[i+1]<='O'))
		num+=14;
		if(ele[i]=='O'&&ele[i+1]=='C'){
			if(ele[i-1]=='O')
			esmark++;
			else if(ele[i-1]=='C')
			kemark++;
			else
			etmark++;
		}
		if(i>=strlen(ele)-5)
		func[j++]=ele[i];
	}
	printf("%d\n",num);
	if(esmark>0)
	printf("This compound is ester\n");
	else if(etmark>0)
	printf("This compound is ether\n");
	else if(kemark>0)
	printf("This compound is ketone\n");
	else{
		int a=strlen(func);
		while(a>=2){
			if(strcmp("CONH2",func)==0){
				printf("This compound is amide\n");
				break;
			}
			else if(strcmp("COOH",func)==0){
				printf("This compound is carboxylic acid\n");
				break;
			}
			else if(strcmp("CHO",func)==0){
				printf("This compound is aldehyde\n");
				break;
			}
			else if(strcmp("NH2",func)==0){
				printf("This compound is amine\n");
				break;
			}
			else if(strcmp("OH",func)==0){
				printf("This compound is alcohol\n");
				break;
			}
			else
			delete_str(func,&a);
		}
	}
}
