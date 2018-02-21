// Assign ID:   PROG8

// Due Date:    03/17/17

//

// Purpose:     Program containing utility charges for customers.

//

// Author:      sjean-baptiste Sony Jean-Baptiste

//---------------------------------------------------------------------------

#include <iostream>

#include <iomanip>

#include <fstream>

#include <ostream>

#include <cstdlib>

using namespace std;

 

int main()

{

   

    //-|--------------------------------------------------------------------------

    //-|  1. Open the input file 'kwhmeters.dat'.

    //-|     1.1 If a file-open error occurs

    //-|         1.1.1 Display message

    //-|               "FATAL ERROR: Can not open file 'kwhmeters.dat'"

    //-|         1.1.2 Exit from program.

    //-|--------------------------------------------------------------------------

    ifstream inF;

    inF.open("kwhmeters.dat");

   

     if (inF.fail())

    {

        cout << "FATAL ERROR: Can not open file 'kwhmeters.dat'"<< endl;

      

         exit(1);

    }

   

    //-|----------------------------------------------------------------------

    //-| Display the copyright notice declaring authorship.

    //-|----------------------------------------------------------------------

    cout << endl << "(c) 2017, sjean-baptiste Sony Jean-Baptiste" << endl << endl;

   

    //-|------------------------------------------------------------------------

    //-|  2. Open the output file, and write the report captions.

    //-|------------------------------------------------------------------------

    ofstream outF;

    outF.open("billing.log");

 

    outF << "===================" << endl;   

    outF << "UTILITY BILLING LOG" << endl;

    outF << "SPRING 2017" << endl;

    outF << "===================" << endl;

      

    outF << "                        METER READINGS" << endl;              

    outF << "    CHARGE  KWH USED   CURRENT  PREVIOUS  CUSTOMER NAME" << endl;

    outF << "==========  ========  ========  ========  ===================" << endl;

   

    //-|------------------------------------------------------------------------

    //-|  3. Initialize counters, totals, average.

    //-|------------------------------------------------------------------------

    long meter_before,   // Meter Before

         meter_after,    // Meter After

         KWHused,        // KWH Used

         Avg_KWHused = 0,    // Average KWH Used

         Tot_KWHused = 0;    // Total KWH Used

    string Cust_Name;     // Customer's Name

    float Charge,        // Charge Amount

          Tot_Charges = 0,   // Total Charges

          Avg_Charges = 0;   // Average Charges

    int  valid_Records = 0;  // Vaild Records Count

   

    //-|------------------------------------------------------------------------

    //-|  4. Repeat until all records have been read:

    //-|     4.1 Read usage record from the input file.

    //-|     4.2 Compute KWH used (Current - Previous)

    //-|     4.3 If units used is valid (>=0)

    //-|         4.3.1 Increment count (valid_Records)

    //-|         4.3.2 Compute charge based on KWH used

    //-|         4.3.3 Update totals (Charges, KWHused).

    //-|         4.3.4 Write billing record to output file

    //-|     4.4 Else

    //-|         4.4.1 Display bad meter reading message

    //-|         4.4.2 Write billing record to output file with

    //-|               xx.xx and xxx for Charge and KWH Used.

    //-|               end Repeat

    //-|------------------------------------------------------------------------

      

                   while(inF >> meter_before >> meter_after) {

                       inF.ignore();

                       getline(inF, Cust_Name);

                        KWHused = meter_after - meter_before;

 

 

                       if(KWHused >= 0){

                           valid_Records ++;

 

                           if(KWHused >= 0 && KWHused < 501){

                              Charge = 53.00 + 0.200 * KWHused;

 

                           } else if ( KWHused > 501 && KWHused < 1001){

                               Charge = 75.50 + 0.125 * KWHused;

 

                           } else if ( KWHused > 1001 && KWHused <= 3000){

                               Charge = 125.75 + 0.100 * KWHused ;

 

                           } else {

                               Charge = 400.07 + 0.075 * KWHused ;

                           }

                          Tot_Charges += Charge;

                           Tot_KWHused += KWHused; 

 

                           outF << "$" << setw(9) << right << fixed << showpoint << setprecision(2) << Charge << "  ";

                           outF << setw(8) << right << KWHused << "  " << setw(8) << setfill('0') << right << meter_after << setfill(' ');

                           outF << "  " << setw(8) << setfill('0') <<  right << meter_before << setfill(' ') << "  " << setw(19) << left << Cust_Name << endl ;

 

                       }

                      else{         cout << " BAD METER READING - old " << setw(8) << setfill('0') << meter_before << " new "  << setw(8) << meter_after << setfill(' ') << ' '  << Cust_Name << endl;

                          

                                    outF << "$" << setw(9) << right << fixed << showpoint << setprecision(2) << "xx.xx" << "  ";

                                    outF << setw(8) << right << "xxx" << "  " << setw(8) << setfill('0') << right << meter_after << setfill(' ') ;

                                    outF << "  " << setw(8) << setfill('0') <<  right << meter_before << setfill(' ') << "  " << setw(19) << left << Cust_Name << endl;

            

                             } 

 

                   }

                                    outF << "----------  --------  --------  --------  -------------------" << endl;

 

                 //-|--------------------------------------------------  

                 //-|   5. Write totals line (Tot_Charges, Tot_KWHUsed).

                 //-|--------------------------------------------------

               

                 outF << "$" << setw(9) << right << fixed << showpoint << setprecision(2) << Tot_Charges << "  "

                      << setw(8) << right << Tot_KWHused << "  " << setw(8) << right << "        "

                      << "  " << setw(8) <<  right << "        " << "  " << setw(19) << left << "TOTALS" << endl;

 

                 //-|--------------------------------------------------

                 //-|   6. Compute and write averages line (Avg_Charges, Avg_KWHUsed).

                 //-|--------------------------------------------------

                        Avg_Charges = Tot_Charges / valid_Records;

                        Avg_KWHused = Tot_KWHused / valid_Records;

    

                  outF << "$" << setw(9) << right << fixed << showpoint << setprecision(2) << Avg_Charges << "  "

                      << setw(8) << right << Avg_KWHused << "  " << setw(8) << right << "        "

                      << "  " << setw(8) <<  right << "        " << "  " << setw(19) << left << "AVERAGES" << endl;

                 //-|--------------------------------------------------  

                 //-|   7. Close input and output files.

                 //-|--------------------------------------------------   

 

           inF.close();

           outF.close();

       

 cout << endl << "(c) 2017, sjean-baptiste Sony Jean-Baptiste" << endl << endl;

    

        return 0;

    }