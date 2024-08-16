
int maxDistance(int** arrays, int arraysSize, int* arraysColSize) {
    // int dist=0;
    // int max=0;
    // for (int i=0;i<arraysSize;i++){
    //     for( int j=0;j<arraysSize;j++){
    //         if(i==j){
    //             continue;
    //         }
    //         dist=arrays[i][0]-arrays[j][arraysColSize[j]-1];
    //         if(dist<0){
    //             dist=-dist;
    //         }
    //         if(max<dist){
    //             max=dist;
    //         }
    //     }
    // }

    //minidx, maxidx 찾기
    //둘이 같은 array출신이면 그 다음 minidx2, maxidx2 찾기
    //dist(minidx2,maxidx)랑 dist(minidx,maxidx2) 중에 더 큰거 고르기
    int min=arrays[0][0]; //1
    int max=arrays[0][arraysColSize[0]-1];
    int minidx=0;
    int minidx2=0;
    int maxidx=0;
    int maxidx2=0;

    for (int i=0;i<arraysSize;i++){
        if(min>arrays[i][0]){
            min=arrays[i][0];
            minidx=i; //0
        }
        if(max<arrays[i][arraysColSize[i]-1]){
            max=arrays[i][arraysColSize[i]-1]; //5
            maxidx=i; //0
        }
    }
    if(minidx!=maxidx){
        if((min-max)<0){
            return -(min-max);
        }else{
            return min-max;
        }
    }else{
        int temp=min;
        min=max; //5
        max=temp; //0
        for (int i=0;i<arraysSize;i++){
            if(i!=minidx){
                if(min>arrays[i][0]){
                    min=arrays[i][0];//-3
                    minidx2=i; //1
                }
            }
            if(i!=maxidx){
                if(max<arrays[i][arraysColSize[i]-1]){
                    max=arrays[i][arraysColSize[i]-1]; //4
                    maxidx2=i; //1
                }
            }
        }
        int dist2=arrays[minidx2][0]-arrays[maxidx][arraysColSize[maxidx]-1];
        int dist3=arrays[minidx][0]-arrays[maxidx2][arraysColSize[maxidx2]-1];
        if(dist2<0){
            dist2=-dist2;
        }
        if(dist3<0){
            dist3=-dist3;
        }
        if(dist2>dist3){return dist2;}
        else{return dist3;}
    }
    
    return max;
}