#include<stdio.h>
#include<conio.h>
int main(){
	int pno,i,mem;  	int size[10];
	clrscr();
	printf("Enter main memory size\n");
	scanf("%d",&mem);
	printf("Enter no of processes\n");
	scanf("%d",&pno);

	for(i=1;i<=pno;i++){
		printf("Enter memory for process %d\n",i);
		scanf("%d",&size[i]);
		if(size[i]<=mem){
			mem=mem-size[i];
			printf("Remaining memory size %d\n",mem);
		}
		else{
			printf("Memory not allocated.\nExternal fragmentation %d",mem);
		}
	}
	getch();
	return 0;
}
