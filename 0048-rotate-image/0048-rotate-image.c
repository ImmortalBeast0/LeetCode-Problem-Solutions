void rotate(int** m, int s, int* c) {
    
    int a[s][s] ;
    for(int i=0;i<s;i++){
        for(int j=0 ;j<s;j++){
            a[j][i] = m[i][j];
        }
    }

        for(int i =0 ;i<s;i++){
            for(int j =s-1,z=0;j>=0;j--,z++){
                m[i][z] = a[i][j] ;
            }
        }


    }

