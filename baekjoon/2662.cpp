#include <stdio.h>

using namespace std;
int N;
char result[81];



int check(int size);

int found;



void back(int size){



   if(found == 1)

      return ;



   if(size == N){

      cout<<result<<endl;

      found = 1;

      return ;

   }



   for(int i=1; i<=3 ; i++){

      result[size] = i + '0';

      if(check(size))

         back(size+1);

      result[size] = '0';

   }



}

int check(int size){

   int cnt;

   int half = (size+1)/2; //size는 0부터 시작한 숫자의 크기이므로 길이에 사용하려면 +1 해줘야함

   

   for(int i=1; i<=half; i++){

      for(int j=0; j<=size-i; j++){

         cnt=0;

         for(int z=j, k=j+i; z<j+i; z++, k++){

            if(result[z] == result[k]){

               cnt++;   

            }

         }

         if(cnt == i){

            return 0;

         }

      }

   }   



   return 1;

}

int main(){



   cin>>N;

   

   found = 0;

   back(0);

   

   return 0;

}

