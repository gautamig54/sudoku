#include <stdio.h>
#include <stdlib.h>
void input();
void print();
void rows();
void columns();
void block();
void inter();
void sudoku();

struct abc{
   int a[10];
}row[10],col[10],blo[10];


int bloc[9][9][2]={{{1,1},{1,2},{1,3},{2,1},{2,2},{2,3},{3,1},{3,2},{3,3}},
				   {{1,4},{1,5},{1,6},{2,4},{2,5},{2,6},{3,4},{3,5},{3,6}},
				   {{1,7},{1,8},{1,9},{2,7},{2,8},{2,9},{3,7},{3,8},{3,9}},
				   {{4,1},{4,2},{4,3},{5,1},{5,2},{5,3},{6,1},{6,2},{6,3}},
				   {{4,4},{4,5},{4,6},{5,4},{5,5},{5,6},{6,4},{6,5},{6,6}},
				   {{4,7},{4,8},{4,9},{5,7},{5,8},{5,9},{6,7},{6,8},{6,9}},
			       {{7,1},{7,2},{7,3},{8,1},{8,2},{8,3},{9,1},{9,2},{9,3}},
				   {{7,4},{7,5},{7,6},{8,4},{8,5},{8,6},{9,4},{9,5},{9,6}},
				   {{7,7},{7,8},{7,9},{8,7},{8,8},{8,9},{9,7},{9,8},{9,9}}};

//each element of sudoku
struct node{	
    int face;
    int a[10] ;
    int blo;
}sudo[10][10];


int main(){
	
	int i,j;
	for(i=1;i<10;i++)
		for(j=0;j<10;j++)
			row[i].a[j]=col[i].a[j]=blo[i].a[j]=1;
    input();
    printf("printing\n");
    print();
    printf("\nrows\n");
    rows();
    printf("\ncolumns\n");
    columns();
    printf("\nblock\n");
    block();
    printf("\ncommon\n");
    inter();
    printf("the solved sudoku is: \n");
    sudoku();
    print();
    return 0;
}
int empty_ele=51;
//taking the input of each element
void input()
{
   /* 
   printf("enter the given valued of sudoku in their specific indexes\n");
    int i,j;
    for(i=1;i<10;i++)
    {
        printf("\n");
        for(j=1;j<10;j++){
            printf("sudo[%d][%d]=",i,j);
            scanf("%d",&sudo[i][j].face);
    		if(sudo[i][j].face!=0)
    			filled_ele++;
    		else
    			empty_ele++;
        }
    }*/
    

	/*FILE *fp;
    char c;
    fp=fopen("xyz.txt","r");
    int i=1,j=1;
    while( !feof(fp)){
        c = fgetc(fp);
        if(c>='0'&&c<='9'){
            
            sudo[i][j].face=c-48;
            if(j==9){
                i++;
                j=1;
            }
            else
                j++;

        }
        printf("%d ",empty_ele);
    }
    fclose(fp);
    for (int i = 1; i < 10; ++i){
    	for (int j = 1; j < 10; ++j){
    		if (sudo[i][j].face==0)
    			empty_ele--;
    	}
    }*/
	sudo[1][1].face=5;
	sudo[1][2].face=0;
	sudo[1][3].face=0;
	sudo[1][4].face=0;
	sudo[1][5].face=0;
	sudo[1][6].face=8;
	sudo[1][7].face=0;
	sudo[1][8].face=4;
	sudo[1][9].face=0;

	sudo[2][1].face=9;
	sudo[2][2].face=0;
	sudo[2][3].face=1;
	sudo[2][4].face=5;
	sudo[2][5].face=0;
	sudo[2][6].face=0;
	sudo[2][7].face=0;
	sudo[2][8].face=7;
	sudo[2][9].face=0;

	sudo[3][1].face=0;
	sudo[3][2].face=8;
	sudo[3][3].face=0;
	sudo[3][4].face=0;
	sudo[3][5].face=0;
	sudo[3][6].face=0;
	sudo[3][7].face=3;
	sudo[3][8].face=0;
	sudo[3][9].face=0;

	sudo[4][1].face=1;
	sudo[4][2].face=0;
	sudo[4][3].face=0;
	sudo[4][4].face=0;
	sudo[4][5].face=3;
	sudo[4][6].face=9;
	sudo[4][7].face=0;
	sudo[4][8].face=0;
	sudo[4][9].face=8;

	sudo[5][1].face=0;
	sudo[5][2].face=0;
	sudo[5][3].face=9;
	sudo[5][4].face=2;
	sudo[5][5].face=0;
	sudo[5][6].face=4;
	sudo[5][7].face=1;
	sudo[5][8].face=0;
	sudo[5][9].face=0;

	sudo[6][1].face=4;
	sudo[6][2].face=0;
	sudo[6][3].face=0;
	sudo[6][4].face=1;
	sudo[6][5].face=6;
	sudo[6][6].face=0;
	sudo[6][7].face=0;
	sudo[6][8].face=0;
	sudo[6][9].face=2;

	sudo[7][1].face=0;
	sudo[7][2].face=0;
	sudo[7][3].face=7;
	sudo[7][4].face=0;
	sudo[7][5].face=0;
	sudo[7][6].face=0;
	sudo[7][7].face=0;
	sudo[7][8].face=8;
	sudo[7][9].face=0;

	sudo[8][1].face=0;
	sudo[8][2].face=9;
	sudo[8][3].face=0;
	sudo[8][4].face=0;
	sudo[8][5].face=0;
	sudo[8][6].face=1;
	sudo[8][7].face=7;
	sudo[8][8].face=0;
	sudo[8][9].face=3;

	sudo[9][1].face=0;
	sudo[9][2].face=5;
	sudo[9][3].face=0;
	sudo[9][4].face=8;
	sudo[9][5].face=0;
	sudo[9][6].face=0;
	sudo[9][7].face=0;
	sudo[9][8].face=0;
	sudo[9][9].face=4;
}

//printin the sudoku
void print(){
    int i,j;
    for(i=1;i<=3;i++){
        for(j=1;j<=3;j++)
            printf("%d  ",sudo[i][j].face);
        printf("   ");
        for(j=4;j<=6;j++)
            printf("%d  ",sudo[i][j].face);
        printf("   ");
        for(j=7;j<=9;j++)
            printf("%d  ",sudo[i][j].face);
        printf("\n");
    }
    printf("\n");
    for(i=4;i<=6;i++){
        for(j=1;j<=3;j++)
            printf("%d  ",sudo[i][j].face);
        printf("   ");
        for(j=4;j<=6;j++)
            printf("%d  ",sudo[i][j].face);
        printf("   ");
        for(j=7;j<=9;j++)
            printf("%d  ",sudo[i][j].face);
        printf("\n");
    }
    printf("\n");
    for(i=7;i<=9;i++){
        for(j=1;j<=3;j++)
            printf("%d  ",sudo[i][j].face);
        printf("   ");
        for(j=4;j<=6;j++)
            printf("%d  ",sudo[i][j].face);
        printf("   ");
        for(j=7;j<=9;j++)
            printf("%d  ",sudo[i][j].face);
        printf("\n");
    }
}

//finding the missing elements in each row
void rows()
{
	int i,j;
	for(i=1;i<10;i++)
		for(j=1;j<10;j++)
			if(sudo[i][j].face!=0)
				row[i].a[sudo[i][j].face]=0;
	printf("    1 2 3 4 5 6 7 8 9");	
	for(i=1;i<10;i++){
		printf("\nr%d->",i);
		for(j=1;j<10;j++)
		printf("%d ",row[i].a[j]);
	}
	
}

//finding the missing elements in each column
void columns()
{
	int i,j;
	for(i=1;i<10;i++)
		for(j=1;j<10;j++)
			if(sudo[j][i].face!=0)
				col[i].a[sudo[j][i].face]=0;
			printf("    1 2 3 4 5 6 7 8 9");	
	for(i=1;i<10;i++){
		printf("\nc%d->",i);
		for(j=1;j<10;j++)
		printf("%d ",col[i].a[j]);
	}
}

//finding the missing elements in each block and assigning the block number to each node
void block()
{
	int i,j;
	for(i=1;i<=3;i++){
		for(j=1;j<=3;j++){
			sudo[i][j].blo=1;
			if(sudo[i][j].face!=0)
				blo[1].a[sudo[i][j].face]=0;
		}
		for(j=4;j<=6;j++){
			sudo[i][j].blo=2;
			if(sudo[i][j].face!=0)
				blo[2].a[sudo[i][j].face]=0;
		}
		for(j=7;j<=9;j++){
			sudo[i][j].blo=3;
			if(sudo[i][j].face!=0)
				blo[3].a[sudo[i][j].face]=0;	
		}
	}
	for(i=4;i<=6;i++){
		for(j=1;j<=3;j++){
			sudo[i][j].blo=4;
			if(sudo[i][j].face!=0)
				blo[4].a[sudo[i][j].face]=0;
		}
		for(j=4;j<=6;j++){
			sudo[i][j].blo=5;
			if(sudo[i][j].face!=0)
				blo[5].a[sudo[i][j].face]=0;
		}
		for(j=7;j<=9;j++){
			sudo[i][j].blo=6;
			if(sudo[i][j].face!=0)
				blo[6].a[sudo[i][j].face]=0;	
		}
	}
	for(i=7;i<=9;i++){
		for(j=1;j<=3;j++){
			sudo[i][j].blo=7;
			if(sudo[i][j].face!=0)
				blo[7].a[sudo[i][j].face]=0;
		}
		for(j=4;j<=6;j++){
			sudo[i][j].blo=8;
			if(sudo[i][j].face!=0)
				blo[8].a[sudo[i][j].face]=0;
		}
		for(j=7;j<=9;j++){
			sudo[i][j].blo=9;
			if(sudo[i][j].face!=0)
				blo[9].a[sudo[i][j].face]=0;	
		}
	}	

			printf("    1 2 3 4 5 6 7 8 9");	
	for(i=1;i<10;i++){
		printf("\nb%d->",i);
		for(j=1;j<10;j++)
		printf("%d ",blo[i].a[j]);
	}
}

//finding the intersection of row,col and blo for each node -> node..a..
void inter()
{
	int i,j,k,p;

	for(i=1;i<10;i++)
		for(j=1;j<10;j++){
			int count=0;
			if(sudo[i][j].face==0)
				for(k=1;k<10;k++)
					if(row[i].a[k]==1 && col[j].a[k]==1 && blo[sudo[i][j].blo].a[k]==1){
						count++;
						sudo[i][j].a[k]=1;
					}
					else 
						sudo[i][j].a[k]=0;
			sudo[i][j].a[0]=count;
			printf("\nsudo[%d][%d]=%d\n",i,j,sudo[i][j].face);
			printf("0 1 2 3 4 5 6 7 8 9\n");
			for(p=0;p<10;p++)
				printf("%d ",sudo[i][j].a[p]);
		}
}


void sudoku(){
	int i,j,k,p,moves=1,ele,t,count,var,t2,x,y;
	printf("%d",empty_ele);
	while(empty_ele!=0){
	
		printf("start");
		int flag=0;
		for(i=1;i<10;i++){
			
			for(j=1;j<10;j++){

				if(sudo[i][j].a[0]==1){ 
					flag=1;
					printf("\nmove-> %d\n",moves);
					printf("sudo[%d][%d]= \n",i,j);
					sudo[i][j].a[0]=0;
					empty_ele--;   
					for(k=1;k<10;k++){
						//the only possible element that can be inserted
						if(sudo[i][j].a[k]==1){
							sudo[i][j].face=k;

							printf("...sudo[%d][%d]=%d\n",i,j,k);
						
							for(p=0;p<9;p++){
							
								if(sudo[bloc[sudo[i][j].blo-1][p][0]][bloc[sudo[i][j].blo-1][p][1]].a[sudo[i][j].face]==1  &&   sudo[bloc[sudo[i][j].blo-1][p][0]][bloc[sudo[i][j].blo-1][p][1]].a[0]>0)
								{
									sudo[bloc[sudo[i][j].blo-1][p][0]][bloc[sudo[i][j].blo-1][p][1]].a[0]--;
									sudo[bloc[sudo[i][j].blo-1][p][0]][bloc[sudo[i][j].blo-1][p][1]].a[k]=0;
									blo[sudo[i][j].blo].a[k]=0;

									printf("......bl...sudo[%d][%d] %d %d\n",bloc[sudo[i][j].blo-1][p][0],bloc[sudo[i][j].blo-1][p][1],sudo[bloc[sudo[i][j].blo-1][p][0]][bloc[sudo[i][j].blo-1][p][1]].a[0],sudo[bloc[sudo[i][j].blo-1][p][0]][bloc[sudo[i][j].blo-1][p][1]].a[k]); 
								}
								else
									printf("...bl...sudo[%d][%d] %d \n",bloc[sudo[i][j].blo-1][p][0],bloc[sudo[i][j].blo-1][p][1],sudo[bloc[sudo[i][j].blo-1][p][0]][bloc[sudo[i][j].blo-1][p][1]].a[0]);   
					    	}
						
							for(p =1;p<10;p++){
								if(sudo[i][p].a[k]==1  &&  sudo[i][p].a[0]>0){
									sudo[i][p].a[0]--;
									sudo[i][p].a[k]=0;
									row[i].a[k]==0;	
									printf("......ro...sudo[%d][%d] %d %d\n",i,p,sudo[i][p].a[0],sudo[i][p].a[k] );
								}
								else
									printf("...ro...sudo[%d][%d] %d\n",i,p,sudo[i][p].a[0] );
							
								if(sudo[p][j].a[k]==1  &&  sudo[p][j].a[0]>0){
									sudo[p][j].a[0]--;
									sudo[p][j].a[k]=0;
									col[j].a[k]==0;
									printf("......co...sudo[%d][%d] %d %d\n",p,j,sudo[p][j].a[0],sudo[p][j].a[k] );
								}
								else	
									printf("...co...sudo[%d][%d] %d\n",p,j,sudo[p][j].a[0] );
								}
							moves++;
							print();
							break;
						}
					}
				}
				else
					printf("sudo[%d][%d]  %d\n",i,j,sudo[i][j].a[0]);
			}	
			
		}
		printf("case 1\n");
		print();
		if (flag==0){
			for( i=1; i<10 ; i++){
				for (ele = 1; ele < 10; ++ele){
					count=0;
					if(row[i].a[ele]==1){
						for(t=1;t<10;t++){		//i is row t is column
							if(sudo[i][t].a[ele]==1){
								count++;
								var=t;
							}
						}
						if(count==1){
							printf("\n........move-> %d\n",moves);
							printf("sudo[%d][%d]= \n",i,var);
							moves++;
							sudo[i][var].face=ele;
							sudo[i][var].a[0]=0;
							for(k=1;k<10;k++)
								sudo[i][var].a[k]=0;
							row[i].a[ele]=0;
							col[var].a[ele]=0;
							blo[sudo[i][var].blo].a[ele]=0;
							empty_ele--;
							for(t=1;t<10;t++){			//t is row
								if(sudo[t][var].a[ele]==1  &&  sudo[t][var].a[0]>0){
									sudo[t][var].a[0]--;
									sudo[t][var].a[ele]=0;
									printf("...ro...sudo[%d][%d]= %d\n",t,var,sudo[t][var].a[0]);

								}
								else{
									printf("..ro..sudo[%d][%d]= %d\n",t,var,sudo[t][var].a[0]);
								}
								for(t2=0;t2<9;t2++){		//t2 is for 1d array in 3d array
									if(sudo[bloc[sudo[t][var].blo-1][t2][0]][bloc[sudo[t][var].blo-1][t2][1]].a[ele]==1  &&   sudo[bloc[sudo[t][var].blo-1][t2][0]][bloc[sudo[t][var].blo-1][t2][1]].a[0]>0)
									{
										sudo[bloc[sudo[t][var].blo-1][t2][0]][bloc[sudo[t][var].blo-1][t2][1]].a[0]--;
										sudo[bloc[sudo[t][var].blo-1][t2][0]][bloc[sudo[t][var].blo-1][t2][1]].a[ele]=0;
										printf("...bl...sudo[%d][%d]= %d\n",bloc[sudo[t][var].blo-1][t2][0],bloc[sudo[t][var].blo-1][t2][1],sudo[bloc[sudo[t][var].blo-1][t2][0]][bloc[sudo[t][var].blo-1][t2][1]].a[0]);
									}
									else{
										printf("..bl..sudo[%d][%d]= %d\n",bloc[sudo[t][var].blo-1][t2][0],bloc[sudo[t][var].blo-1][t2][1],sudo[bloc[sudo[t][var].blo-1][t2][0]][bloc[sudo[t][var].blo-1][t2][1]].a[0]);
									}
								}

							}
						print();}
						
					}
					if(col[i].a[ele]==1){

						count=0;
						for(t=1;t<10;t++){			// t is row i is column
							if(sudo[t][i].a[ele]==1){
								count++;
								var=t;
							}
						}
						if(count==1){
							printf("\n........move-> %d\n",moves);
							printf("sudo[%d][%d]= \n",var,i);
							moves++;
							sudo[var][i].face=ele;
							sudo[var][i].a[0]=0;
							for (k=1;k<10;k++)
								sudo[var][i].a[k]=0;
							row[var].a[ele]=0;
							blo[sudo[var][i].blo].a[ele]=0;
							empty_ele--;
							for(t=1;t<10;t++){		// t is column
								if(sudo[var][t].a[ele]==1  &&  sudo[var][t].a[0]>0){
									sudo[var][t].a[0]--;
									sudo[var][t].a[ele]=0;
									printf("...co...sudo[%d][%d]= %d\n",var,t,sudo[var][t].a[0]);

								}
								else{
									printf("..co..sudo[%d][%d]= %d\n",var,t,sudo[var][t].a[0]);
								}
								for(t2=0;t2<9;t2++){	// t2 is for 1d array in 3d array
									if(sudo[bloc[sudo[var][t].blo-1][t2][0]][bloc[sudo[var][t].blo-1][t2][1]].a[ele]==1  &&   sudo[bloc[sudo[var][t].blo-1][t2][0]][bloc[sudo[var][t].blo-1][t2][1]].a[0]>0)
									{
										sudo[bloc[sudo[var][t].blo-1][t2][0]][bloc[sudo[var][t].blo-1][t2][1]].a[0]--;
										sudo[bloc[sudo[var][t].blo-1][t2][0]][bloc[sudo[var][t].blo-1][t2][1]].a[ele]=0;
										
									printf("...bl...sudo[%d][%d]= %d\n",bloc[sudo[t][var].blo-1][t2][0],bloc[sudo[t][var].blo-1][t2][1],sudo[bloc[sudo[t][var].blo-1][t2][0]][bloc[sudo[t][var].blo-1][t2][1]].a[0]);
									}
									else{
										printf("..bl..sudo[%d][%d]= %d\n",bloc[sudo[t][var].blo-1][t2][0],bloc[sudo[t][var].blo-1][t2][1],sudo[bloc[sudo[t][var].blo-1][t2][0]][bloc[sudo[t][var].blo-1][t2][1]].a[0]);
									}
								}
							}
					print();	}
						
					}
				}
			}
			
			for(i=0;i<9;i++){		//i is block number
				for(ele=1;ele<10;ele++){
					count =0;
					if(blo[i+1].a[ele]==1){
						for(t=1;t<10;t++){
							if(sudo[bloc[i][t][0]][bloc[i][t][1]].a[ele]==1){
								count++;
								x=bloc[i][t][0];
								y=bloc[i][t][1];
							}
						}
						if(count==1){
							printf("\n........move-> %d\n",moves);
							printf("sudo[%d][%d]= \n",x,y);
							moves++;
							sudo[x][y].face=ele;
							sudo[x][y].a[0]=0;
							for(k=1;k<10;k++)
								sudo[x][y].a[k]=0;
							blo[i+1].a[ele]=0;
							row[x].a[ele]=0;
							col[y].a[ele]=0;
							empty_ele--;
							for(t=1;t<10;t++){
								if(sudo[x][t].a[ele]==1  &&  sudo[x][t].a[0]>0){
									sudo[x][t].a[0]--;
									sudo[x][t].a[ele]=0;
									
								printf("...co...sudo[%d][%d]= %d\n",x,t,sudo[x][t].a[0]);

								}
								else{
									printf("..co..sudo[%d][%d]= %d\n",x,t,sudo[x][t].a[0]);
								}
								if(sudo[t][y].a[ele]==1  &&  sudo[t][y].a[0]>0){
									sudo[t][y].a[0]--;
									sudo[t][y].a[ele]=0;
			
								printf("...ro...sudo[%d][%d]= %d\n",t,y,sudo[t][y].a[0]);

								}
								else{
									printf("..ro..sudo[%d][%d]= %d\n",t,y,sudo[t][y].a[0]);
								}
							}
					print();	}
						
					}
				}
			}
			printf("case 2\n");
			print();
		}
		

	}		

}
