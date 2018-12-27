#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
int numberOfPages;
void print(int arr [], int page,bool flag){
 printf("%02d ",page);
 if(flag==true)
   printf("    ");
 else
   printf("F   ");

 for(int i = 0; i < numberOfPages; i++)
     if(arr[i]==-1)
       printf("   ");
     else
      printf("%02d ",arr[i]);

 printf("\n");
}
void printForPairs(pair<int,int> arr [], int page,bool flag){
 printf("%02d ",page);
 if(flag==true)
   printf("    ");
 else
   printf("F   ");

 for(int i = 0; i < numberOfPages; i++)
     if(arr[i].first==-1)
       printf("   ");
     else
      printf("%02d ",arr[i].first);

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
int getPositionForLRU(pair<int,int> arr[]){
int mn=1e8,index=0;
for(int i=0;i<numberOfPages;i++){
  if(arr[i].second < mn)
  {
    mn=arr[i].second;
    index=i;
  }
}
return index;
}
void LRU(){
int page=-1,pageFault=0,used=0,mostUSed=0;
pair<int,int> myLRU[numberOfPages];
for(int i=0;i<numberOfPages;i++){
myLRU[i]=make_pair(-1,-1);
}
cin>>page;
printf("Replacement Policy = LRU\n-------------------------------------\nPage   Content of Frames\n----   -----------------\n");
while(page!=-1){
int flag=0;
for(int i=0;i<numberOfPages;i++){
   if(myLRU[i].first==page){
      flag=1;
      myLRU[i].second=mostUSed;
      break;
   }
}
if(flag==1){
  printForPairs(myLRU,page,true);
}
else{
 int index=getPositionForLRU(myLRU);
 myLRU[index]=make_pair(page,mostUSed);
 if(used<numberOfPages){
   printForPairs(myLRU,page,true);
 }
 else{
   printForPairs(myLRU,page,false);
   pageFault++;
 }
 used++;
}
mostUSed++;
cin>>page;
}
printf("-------------------------------------\nNumber of page faults = %d",pageFault);
}
void CLOCK(){
int page=-1,pageFault=0,used=0,index=0;
pair<int,int> myLRU[numberOfPages];
for(int i=0;i<numberOfPages;i++){
myLRU[i]=make_pair(-1,0);
}
cin>>page;
while(page!=-1){
int flag=0;
for(int i=0;i<numberOfPages;i++){
   if(myLRU[i].first==page){
     flag=1;
     myLRU[i].second=1;
     break;
   }
}
if(flag==1){
   printForPairs(myLRU,page,true);
}
else{
  while(myLRU[index].second != 0){
       myLRU[index].second=0;
       index++;
       index=index%numberOfPages;
  }
  myLRU[index]=make_pair(page,1);
  if(used<numberOfPages){
     printForPairs(myLRU,page,true);
  }
  else{
     printForPairs(myLRU,page,false);
     pageFault++;
  }
  index++;
  index=index%numberOfPages;
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
    else if(method == "LRU")
        LRU();
    else if(method == "CLOCK")
        CLOCK();

   return 0;
}
