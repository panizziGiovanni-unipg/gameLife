#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int const ROW=10;
int const COLLS=10;

    typedef struct
    {
        int row;
        int column;
        int alive;
        int neigh;
    } cell;

    typedef struct
    {
        cell cells[10][10];
        
    }mat;



int visitNeig(mat* a,cell c){

    int cont=0;
    for (int i = -1; i < 2; i++)
    {
        if(c.row+i<0||c.row+i>ROW-1)
            continue;
        for (int j = -1; j < 2; j++)
        {
            if(c.column+j<0||c.column+j>COLLS-1)
                continue;
            
            if(a->cells[c.row+i][c.column+j].alive==1)
                cont++;
            
        }
    }

    if(a->cells[c.row][c.column].alive==1)
        cont--;
    return cont;
}




void stampaMatriceGrafica(mat m) {
    
    printf("   ");  
    for (int j = 0; j < COLLS; j++) {
        printf("%2d ", j);  
    }
    printf("\n");

    
    for (int i = 0; i < ROW; i++) {
        printf("%2d ", i);  
        for (int j = 0; j < COLLS; j++) {
            if(m.cells[i][j].alive==1)
                printf(" * ");
            else
                printf(" - ");
        }
        printf("\n");
    }
}


void putRandom(mat* m,int l){
    time_t t;
    
    srand((unsigned) time(&t));

    

    for (int i = 0; i < l; i++)
    {
        int row = (rand() % (ROW)) + 0;
        int col=(rand() % (COLLS)) + 0;
        if(m->cells[row][col].alive)
            i--;
        else{
            m->cells[row][col].alive=1;
        }
    }   
    return;
}


mat step(mat* m){

    mat matOut;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLLS; j++)
        {   
            cell c1;
            c1.row=i;
            c1.column=j;
            c1.neigh=0;
            
            m->cells[i][j].neigh=visitNeig(m,m->cells[i][j]);
            if(m->cells[i][j].alive==1){

                if(m->cells[i][j].neigh<2){
                    c1.alive=0;
                }else if(m->cells[i][j].neigh>3){
                    c1.alive=0;
                }

            }else{
                if(m->cells[i][j].neigh==3)
                   c1.alive=1; 
            }


            matOut.cells[i][j]=c1;
        }
        
    }

    return matOut;

}

int main(void){

    mat mat1;


    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLLS; j++)
        {
            cell c1;
            c1.row=i;
            c1.column=j;
            c1.alive=0;
            c1.neigh=0;
            mat1.cells[i][j]=c1;
        }
        
    }
    
    
    putRandom(&mat1,10); 

    stampaMatriceGrafica(mat1);

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    mat matout=step(&mat1);

    stampaMatriceGrafica(matout);

    return 0;
}