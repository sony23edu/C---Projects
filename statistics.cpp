/-------------------------------------------------------------------------
// Assignment ID:   PROG8
// File name:       statistics.cpp
//
// Due Date:        Nov 15, 2017
//
// Author:          
//
// Purpose:         Compute mean, variance and standard deviation for 
//                  numeric values stored in file 'scores.dat'.
//                  Author: Sony Jean-Baptiste
//-------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

//---------------------------------------------------------------------------
// Sort array into ascending order.
//---------------------------------------------------------------------------
void BubbleSort(float A[], int Asize)
{
   for (int pass=1; pass<Asize; pass++)
   {
      for (int k=0; k<Asize-pass; k++)
      {
         if (A[k] > A[k+1])
         {
            float temp=A[k]; 
            A[k] = A[k+1];
            A[k+1] = temp;  
         }
      }
   }//pass
}

//---------------------------------------------------------------------------
// Load data from input stream until all data has been read.
//---------------------------------------------------------------------------
void LoadArray(istream & inF, float A[], int & Asize)
{
    
   
    float val;
    while(inF>> val){
    A[Asize] = val;
        Asize++;
        
    }
}


//---------------------------------------------------------------------------
// Display array values in form: label v1 v2 v3 ... lastval
//---------------------------------------------------------------------------
void DisplayArray(string Label, float Q[], int Qsize)
{
cout<<Label;
   for(int i=0;i<Qsize;i++)
   {
       cout <<Q[i]<<" ";
       
      
   }
      

}


//---------------------------------------------------------------------------
// Return the sum of array values.
//---------------------------------------------------------------------------
float ArraySum(float B[], int Bsize)
{
   float sum = 0;

 for(int i=0;i<Bsize;i++)
 {
     sum+=B[i];
 }

   return sum;
}

//---------------------------------------------------------------------------
// Construct array Csquared by squaring each value in array C. 
//---------------------------------------------------------------------------
void SquareArray(float C[], int Csize, float Csquared[])
{
 for(int i=0;i<Csize;i++)
 {
     Csquared[i]= C[i]*C[i];
 }
      
}

// Return the average given a total and a count.
float Average(float total, int count)
{
float Average;
  
    if(count==0)
    {
     Average=0.00;    
    }
    else
    {
       
     Average = total/count;   
  
    } 

return Average;
}

//---------------------------------------------------------------------------
// Return the variance computed using equation (d).
//---------------------------------------------------------------------------
float Var(float mean, float sum, float sumsq, int N)
{
float Var;
    
  if(N!=0)
  {
     Var = (sumsq - (2 * mean * sum) + (N *mean*mean)) / N;
  }
  else
  {
   
   Var=0.00;

  }
return Var;
}

//---------------------------------------------------------------------------
// Return the variance computing using equation (e).
//-------------------------------------------------------------------------
float Variance(float T[], float avg, int N, int Tsize)
{
 float Variance;

    for(int i=0; i<Tsize;i++)
    {
        Variance=(T[i]-avg)*(T[i]-avg);
    }

return Variance;
}




int main ()
{
   int N = 0;          // Number of scores.
       
   float X[100];       // Score array. 
   float Xsq[100];     // Squared values from X array. 
          
   float SumX = 0.0,   // The sum of scores.
         SumXsq = 0.0, // The sum of the square of each score.
         Avg = 0.0,    // The mean (average).
         VarX = 0.0,   // The variance.
         XVar = 0.0,   // The variance.
         XStdDev = 0.0,// Standard deviation.
         StdDev = 0.0; // Standard deviation.
   
   ifstream scoresF;

   //-| ------------------------------------------------------------------
   //-|   Print copyright.
   //-| ------------------------------------------------------------------
   cout << endl << "(c) 2017, sjean Sony Jean-Baptiste" << endl << endl;

   //-| ------------------------------------------------------------------
   //-| 1. Initialize accumulators, SumX and SumXsq, to 0. 
   //-| ------------------------------------------------------------------
   
    SumX=0;
    SumXsq=0;
    
   //-|-----------------------------------------------------------------------
   //-|  2. Open input file 'scores.dat'; terminate if unable to open.
   //-|     Then load scores into array X from input stream.
   //-|
   //-|     Use: void LoadArray(istream & inF, float A[], int & Asize);
   //-|     Load scores into array X
   //-| ------------------------------------------------------------------
 
   scoresF.open ("scores.dat");
    
    if(scoresF.fail())
    {
        cout<< "FATAL ERROR: UNABLE TO OPEN FILE \"scores.dat\". TERMINATING..." <<endl;
        
        //exit(1);
    }
    
    LoadArray(scoresF,X, N);
    
   
   //-|-----------------------------------------------------------------------
   //-|  3. Display contents of array X, 2 decimal places.
   //-|     Output format: Array X: xx.xx xxxx.xx xxxxxx.xx
   //-|     Use: void Display(string Label, float Q[], Qsize);
   //       DisplayArray("Array+Xsq: ",Xsq, N);
   //-|-----------------------------------------------------------------------
      
      cout<<fixed<<showpoint<<setprecision(2);
      DisplayArray("Array X: ", X, N);
      cout<<endl;
   //-|-----------------------------------------------------------------------
   //-|  4. Compute the sum of values in array X.
   //-|     Use: float ArraySum(float B[], int Bsize);
   //       SumX= ArraySum(X,N);
   //-|-----------------------------------------------------------------------
    
     
     SumX=ArraySum(X, N);
    


   //-|-----------------------------------------------------------------------
   //-|  5. Construct array Xsq containing the square of elements of array X.
   //-|     Use: void SquareArray(float C[], int Csize, float Csquared[]);
   //       SquareArray(X,N, Xsq);
   //-|-----------------------------------------------------------------------
    
    SquareArray(X, N, Xsq);

   //-|-----------------------------------------------------------------------
   //-|  6. Display contents of array Xsq, 2 decimal places.
   //-|     Output format: Array Xsq: xx.xx xxxx.xx xxxxxx.xx
   //-|     Use: void Display(string Label, float Q[], Qsize);
   //       DisplayArray("ArrayXsq: ",Xsq, N);
   //-|-----------------------------------------------------------------------
   
    cout<<fixed<<setprecision(2)<<showpoint;
    DisplayArray("Array Xsq: ", Xsq, N);
    
   //-|-----------------------------------------------------------------------
   //-|  7. Compute the sum of the squares of the X values (stored
   //-|     in array Xsq -- step 5 above.)
   //-|     Use: float ArraySum(float C[], int Csize);
   //-|-----------------------------------------------------------------------
  
    SumXsq= ArraySum(Xsq, N);

   //-|-----------------------------------------------------------------------
   //-|  8. Compute the mean (average) using equation (b).
   //-|     Use: float Average(float total, int count);
   //-|-----------------------------------------------------------------------
 
     Avg=Average(SumX,N);
    
   //-|-----------------------------------------------------------------------
   //-|  9. Compute variance (XVar) using equation (d).
   //-|     Use: float Var(float mean, float sum, float sumsq, int N);
   //-|-----------------------------------------------------------------------

     XVar= Var(Avg,SumX, SumXsq, N);
   //-|-----------------------------------------------------------------------
   //-| 10. Compute variance (VarX) using equation (e).
   //-|     Use: float Variance(float T[], float avg, int N);
   //-|-----------------------------------------------------------------------

    VarX=Var(Avg, SumX, SumXsq, N);

   //-|-----------------------------------------------------------------------
   //-| 11. Compute standard deviation (StdDev) using equation (f).
   //-|-----------------------------------------------------------------------

   StdDev= sqrt(VarX);

   //-|-----------------------------------------------------------------------
   //-| 12. Compute standard deviation (XStdDev) using equation (g).
   //-|-----------------------------------------------------------------------
  
    XStdDev= sqrt(XVar);

   //-|-----------------------------------------------------------------------
   //-| 13. Display the computed values in the Statistical Analysis Report.
   //-|-----------------------------------------------------------------------
   cout << endl << endl
        << "STATISTICAL ANALYSIS REPORT" << endl;
   cout << "===========================" << endl;
   cout << fixed << setprecision(2) << showpoint << endl;
   cout << "SCORE COUNT    = " << setw(9) << N << endl;
   cout << "SUM OF VALUES  = " << setprecision(1) << setw(9) << SumX << endl;
   cout << "SUM OF SQUARES = " << setprecision(1) << setw(9) << SumXsq << endl;
   cout << "AVERAGE        = " << setw(9) << setprecision(2) <<  Average(SumX, N) << endl;  
   cout << "VARIANCE1      = " << setw(9) << XVar << endl;
   cout << "VARIANCE2      = " << setw(9) << VarX << endl;
   cout << "STD DEVIATION1 = " << setw(9) << StdDev << endl;
   cout << "STD DEVIATION2 = " << setw(9) << XStdDev << endl;
   cout << "" << endl;
   cout << "===========================" << endl << endl;


   //-|-----------------------------------------------------------------------
   //-| 14. Sort the values in array X
   //-|-----------------------------------------------------------------------

    BubbleSort(X, N);


   //-|-----------------------------------------------------------------------
   //-| 15. Display the sorted array X as: Sorted X: xx.xx xx.xx .... xx.xx
   //-|-----------------------------------------------------------------------

    DisplayArray("Sorted Array X: ",X,N);
    cout<<endl;

   //-|-----------------------------------------------------------------------
   //-| 16. Sort the values in array Xsq.
   //-|-----------------------------------------------------------------------

    BubbleSort(Xsq, N);

   //-|-----------------------------------------------------------------------
   //-| 17. Display the sorted array Xsq as: Sorted Xsq: xx.xx xx.xx .... xx.xx
   //-|-----------------------------------------------------------------------

   
    DisplayArray("Sorted Array Xsq: ",Xsq,N);
    cout<<endl;
   //-| ------------------------------------------------------------------
   //-|   Print copyright.
   //-| ------------------------------------------------------------------

       cout << endl << "(c) 2017,sjean Sony " << endl << endl;

  scoresF.close();

   return 0;
}//main
