#include <iostream>

using namespace std;
int main()
{
 cout<<"Enter the number of processes: ";
 int nProc=0;
 cin>>nProc;

 cout<<"Enter the burst times of processes: ";
 int data[10][5];
 for(int i =0;i<nProc;++i)
 {
  cin>>data[i][0];
  data[i][1]=data[i][0]; //for burst time subtractions
  data[i][2]=0; //for waiting times
  data[i][3]=0; //for turn around times
  data[i][4]=0; //for status of processes: whether completed or not
 }

 int time=0;
 cout<<"Enter time quantum: ";
 cin>>time;

 while(1)
 {
  bool resume = 0;
  for(int i =0;i<nProc;++i)
  {
   if(data[i][4]==0)
   {
    resume = 1;
    break;
   }
  }

  if(resume)
  {
   for(int i =0;i<nProc;++i)
   {
    if(data[i][1]<=time)
    {
     for(int j=0;j<nProc;++j)
     {
      if(i==j)
       continue;
      else if(data[j][4]==0)
      data[j][2]+=data[i][1];
     }
     data[i][1]=0;
     data[i][4]=1;
    }
    else if(data[i][1]>time)
    {
     data[i][1]-=time;
     for(int j =0;j<nProc;++j)
     {
      if(i==j)
       continue;
      else if(data[j][4]==0)
      data[j][2]+=time;
     }
    }
   }
  }
  else if(!resume)
   break;
 }

 float avgWt =0, avgTat =0;
  //calculation of TAT (Turn around time) and averages
  for(int i=0;i<nProc;++i)
  {
     data[i][3] = data[i][0]+data[i][2];
  avgWt+=data[i][2];
  avgTat+=data[i][3];
  }
  avgWt/=nProc;
  avgTat/=nProc;
 
   //show results
   for(int i = 0;i<nProc;++i)
   {
     cout<<"\nProcess ID "<<i<<endl;
     cout<<"Burst time : "<<data[i][0]<<endl;
     cout<<"Waiting time: "<<data[i][2]<<endl;
     cout<<"TAT: "<<data[i][3]<<endl;
     cout<<endl;
   }

   cout<<"Average waiting time: "<<avgWt<<endl;
   cout<<"Average turn around time: "<<avgTat<<endl;
   return 0;
}
