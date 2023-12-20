/*==========================================================*\
  Sunday March the 10th 2019
  Arash Habibi
  CL_draw and CL_animate
\*==========================================================*/


//----------------------------------------------------
// Draws a grid of nb_rows x nb_cols cells in blue,
// and, on this grid, draws the cells of cell list cl.
// The whole image is saved in ppm_name with a .ppm
// extension.

#include"cellList.h"



struct cellList CL_new() {
	struct cellList cl;
	cl.size = 0;
	return cl;
}



struct cellList CL_add(struct cellList cl, struct cell c){
	cl.arr[cl.size]=c;
	cl.size++;
	return cl;
}



void CL_print(struct cellList cl, char *label) {
	printf("%s\n",label);
	for ( int i = 0 ; i < cl.size ; i++ ){
		printf("%d : ",i);
		printf("(%d,%d)\n",cl.arr[i].row,cl.arr[i].col);
	}
}






struct cell CL_random(struct cellList cl){
	if( cl.size == 0 ){
		printf("This cellList is empty! | Function will now return an impossible cell\n");
		return C_new(-1,-1);
	} 
	int random = rand() % cl.size;
	return  cl.arr[random];
}




void CL_draw2(struct cellList cl, int nb_rows, int nb_cols, char *ppm_name)
{
	int pixels_per_cell = 20;
	char ppm_file_name[50];
	float proportion_serpent = 0.5;
	struct ppm img = PPM_new(nb_rows, nb_cols, pixels_per_cell, proportion_serpent);
	img = PPM_drawBG(img);

	for(int i=0; i<cl.size;i++)
	{
		struct cell c = cl.arr[i];
		img = PPM_drawCell(img, c.row, c.col, img.ob_color_r, img.ob_color_g, img.ob_color_b);
	}
	sprintf(ppm_file_name,"%s.ppm",ppm_name);
	PPM_save(img,ppm_file_name);
}

//----------------------------------------------------
// Draws a series of ppm image files. All of them show
// in orange the cells of cell list fix. The first image
// also shows the first cell of cell list anim. The second
// image shows only the second cell of anim and so on.

void CL_animate2(struct cellList fix, struct cellList anim, int nb_rows, int nb_cols, char *ppm_name)
{
	int pixels_per_cell = 20;
	char ppm_file_name[50];
	float proportion_serpent = 0.5;
	struct ppm img = PPM_new(nb_rows, nb_cols, pixels_per_cell, proportion_serpent);
	img = PPM_drawBG(img);

	// img = PPM_drawCell(img, c.row, c.col);

	for(int t=0; t<anim.size;t++)
	{
		img = PPM_drawBG(img);
		for(int i=0; i<fix.size;i++)
		{
			struct cell c = fix.arr[i];
			img = PPM_drawCell(img, c.row, c.col, img.ob_color_r, img.ob_color_g, img.ob_color_b);
		}
		struct cell c = anim.arr[t];
		img = PPM_drawCell(img, c.row, c.col, img.fg_color_r, img.fg_color_g, img.fg_color_b);

		sprintf(ppm_file_name,"%s_%02d.ppm",ppm_name,t);
		PPM_save(img,ppm_file_name);
	}
}





struct cellList CL_randomFill(int nb_cells, int nb_rows, int nb_cols){
	struct cellList obs = CL_new();
	int r1,r2;
	for ( int i = 0 ; i < nb_cells ; i++ ){
		r1 = rand() % nb_rows;
		r2 = rand() % nb_cols;
		obs = CL_add(obs,C_new(r1,r2));
	}
	return obs;
}




int CL_isInList(struct cell c, struct cellList cl){
	for ( int i = 0 ; i < cl.size ; i++ ){
		if ( cl.arr[i].row == c.row && cl.arr[i].col == c.col ){
			return 1;
		}else{
			continue;
		}
	}
	return 0;
}





struct cell CL_randomCellNotInObst(int nb_rows, int nb_cols, struct cellList obst){
	struct cell cnio = C_new(0,0);
	int r1,r2;
	while (1){
		r1 = rand() % nb_rows;
		r2 = rand() % nb_cols;
		cnio = C_new(r1,r2);
		for ( int i = 0; i < obst.size ; i++ ){
			if ( CL_isInList(cnio,obst) != 1 ){
				return cnio;
			}
		}
	}
}





struct cellList CL_randomFill2(int nb_obstacles, int nb_rows, int nb_cols) {
    struct cellList cl = CL_new();
    struct cell c = C_new(0,0);
    for ( int i = 0 ; i < nb_obstacles ; i++) {
        c = CL_randomCellNotInObst(nb_rows,nb_cols,cl);
		printf("%d,%d",c.row,c.col);
        if( c.row == -1  &&  c.col == -1 ) {
            break;
        }
        cl=CL_add(cl,c);
    }
    if(cl.size==0) {
        printf("empty list");
    }
    return cl;
}


