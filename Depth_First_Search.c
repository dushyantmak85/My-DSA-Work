#include <stdio.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
  int adjacencyMatrix[7][7] = {
      {0, 1, 1, 1, 0, 0, 0},
      {1, 0, 1, 0, 0, 0, 0},
      {1, 1, 0, 1, 1, 0, 0},
      {1, 0, 1, 0, 1, 0, 0},
      {0, 0, 1, 1, 0, 1, 1},
      {0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 1, 0, 0},
  };
void DFS(int node){
    printf("%d ",node);
    visited[node]=1;
    for(int j=0;j<7;j++){
        if(adjacencyMatrix[node][j]==1 && visited[j]==0){
            DFS(j);
        }
    }
}


int main() {
    DFS(1);
    
    return 0;
}