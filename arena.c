#include"cellList.h"

struct arena A_new(int row,int col){
    struct arena ar;
    ar.nb_rows = row;
    ar.nb_cols = col;
    return ar;
}


int A_isInside(struct cell c, struct arena ar){
    if (c.row < ar.nb_rows && c.row >= 0 && c.col < ar.nb_cols && c.col >= 0 ){
        return 1;
    }else{
        return 0;
    }
}