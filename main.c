#include"cellList.h"



int main(){


    int nb_rows = 10, nb_cols = 10;
    struct cellList obst = CL_randomFill(50,nb_rows,nb_cols);
    //CL_draw2(obst, nb_cols, nb_rows, "obst1");       Checking of CL_draw2()

    struct cell c = C_new(9,9);
    //printf("%d\n",CL_isInList(c,obst));             Checking of CL_isInList()


    struct cell cnio = CL_randomCellNotInObst(10,10,obst);
    //C_print(cnio,"Cell that is not in the list Obst");
    //CL_print(obst,"Obst list");                             Checking of CL_randomCellNotInObst()
    
    printf("Mainde bura qeder her shey ela\n, indi randomfill 2 ni ishledeceyik\n");
    struct cellList obst2 = CL_randomFill2(50,nb_rows,nb_cols);
    printf("Randomfill2 ishledi qurtardi!!\n");
    CL_print(obst2,"Obst 2 list");
    CL_draw2(obst2,nb_cols,nb_rows,"obst2");



    return 0;
}