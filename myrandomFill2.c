
// struct cellList CL_randomFill2(int nb_obstacles, int nb_rows, int nb_cols) {
// 	struct cellList obs = CL_new();
// 	struct cellList cleanObs = CL_new();
// 	struct cellList cleanest = CL_new();
// 	while ( cleanest.size <= nb_obstacles  ){
// 		obs = CL_randomFill(nb_obstacles,nb_rows,nb_cols);
// 		cleanObs = CL_add(cleanObs,CL_randomCellNotInObst(nb_rows,nb_cols,obs));
// 		for ( int i = 0 ; i < cleanObs.size ; i++ ){
// 			for ( int j = i+1 ; j < cleanObs.size ; j++ ){
// 				if ( cleanObs.arr[i].row != cleanObs.arr[j].row &&  cleanObs.arr[i].col != cleanObs.arr[j].col){
// 					cleanest = CL_add(cleanest,cleanObs.arr[j]);
// 				}
// 			}
// 		}
// 	}
// 	return cleanest;
// }