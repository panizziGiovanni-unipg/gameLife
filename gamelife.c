#include <stdio.h>
#include <stdlib.h>

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



int visitNeig(mat a,cell c){

    int cont=0;
    for (int i = -1; i < 2; i++)
    {
        if(c.row+i<0||c.row+i>9)
            continue;
        for (int j = 0; j < 3; j++)
        {
            if(c.column+j<0||c.column+j>9)
                continue;
            if(a.cells[i][j].alive==1&&(i!=0&&j!=0))
                cont++;
        }
    }
    return cont;
}




void stampaMatriceGrafica(mat m) {
    
    printf("   ");  
    for (int j = 0; j < COLLS; j++) {
        printf("%2d ", j);  
    }
    printf("\n");

    // Stampa la matrice
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


void putRandom(mat m,int l){

    for (int i = 0; i < l; i++)
    {
        int row = (rand() % (ROW-1 - 0 + 1)) + 0;
        int col=(rand() % (COLLS-1 - 0 + 1)) + 0;
        if(m.cells[row][col].alive)
            i--;
        else{
            m.cells[row][col].alive=1;
        }
    }   
    return;
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
    
    
    for (int i = 0; i < 10; i++)
    {
        int row = (rand() % (ROW-1 - 0 + 1)) + 0;
        int col=(rand() % (COLLS-1 - 0 + 1)) + 0;
        if(mat1.cells[row][col].alive)
            i--;
        else{
            mat1.cells[row][col].alive=1;
        }
    }   

    stampaMatriceGrafica(mat1);


    int prova=visitNeig(mat1,mat1.cells[3][6]);

    printf("%d\n",prova);

    return 0;
}