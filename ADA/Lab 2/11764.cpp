#include <iostream>
#include <fstream>
using namespace std;
int main(){
  int cases,walls,hj,lj;
  int heightwall=0,next_wall=0;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++) {
      heightwall=0;
      next_wall=0;
      hj=0;
      lj=0;
      scanf("%d", &walls);
      scanf("%d", &heightwall);
      for (int i = 0; i < walls-1; i++) {
          scanf("%d", &next_wall);
          if(heightwall<next_wall){
            hj++;
          }
          else if(heightwall>next_wall){
            lj++;
          }
          heightwall=next_wall;
      }
      cout << "Case " << i+1 << ": ";
      cout << hj << " " << lj << endl;
    }
}
