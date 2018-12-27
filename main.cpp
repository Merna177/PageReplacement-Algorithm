#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
int numberOfPages;
void print(int arr [], int element,bool boolean){
 printf("%02d ",element);
 boolean == true ? printf("    ") : printf("F   ");
 for(int i = 0; i < numberOfPages; i++)
     if(arr[i]==-1)
       printf("   ");
     else
      printf("%02d ",arr[i]);

 printf("\n");
}
void FIFO(){
int page=-1,used=0,pageFault=0;
cin>>page;
int myqueue[numberOfPages],turn=0;
for(int i=0;i<numberOfPages;i++)myqueue[i]=-1;
printf("Replacement Policy = FIFO\n-------------------------------------\nPage   Content of Frames\n----   -----------------\n");
    while(page!=-1){
     int flag=0;
       for(int i=0;i<numberOfPages;i++){
          if(myqueue[i]==page)
           {
           flag=1;
           break;
           }
       }
       if(flag==1){
          print(myqueue,page,true);
       }
       else{
          myqueue[turn++]=page;
          if(used<numberOfPages)
            print(myqueue,page,true);
          else
          {
            print(myqueue,page,false);
            pageFault++;
          }
          turn=turn%numberOfPages;
          used++;
       }
      cin>>page;
    }
printf("-------------------------------------\nNumber of page faults = %d",pageFault);
}
int main()
{
 cin >> numberOfPages;
 string method;
    cin >> method;
    if(method == "FIFO")
        FIFO();
//    else if(method == "LRU")
//    LRU();
//    else if(algorithm == "CLOCK")
//        //CLOCK();

   return 0;
}
