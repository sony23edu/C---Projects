//-|-----------------------------------------------------------------------
//-| File name: StudentReports.cpp
//-| Assign ID: PROG7
//-| 
//-|
//-| Purpose: Write a program to read and format data for three students.
//-|
//-|        (2) Flag the academic status of each student:
//-|                  ON PROBATION  -- when GPA < 2.0
//-|                  HONORS        -- when GPA >= 3.0
//-|                  GOOD STANDING -- when neither honors nor probation.
//-|
//-|              (3) Compute the arithmetic and weighted average GPA of the 
//-|                  three students.
//-|                  
//-| Author: sjean Sony Jean-Baptiste
//-|
//-|-------------------------------------------------------------------------
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//-|---------------------------------------------------------------------------
//-| PRINT student copyright.
//-|---------------------------------------------------------------------------
void Display_Copyright()
{
   cout << endl << "(c) 2017, sjean Sony Jean-Baptiste" << endl << endl;
   
}//Display_Copyright

//-|---------------------------------------------------------------------------
//-| READ a Student Record. Set success flag to indicate 
//-|      successful/unsuccessful read.
//-| 
//-|---------------------------------------------------------------------------
void Read_StudentData(istream & inF, long & ID, string & Fname, 
                     string & Lname, int & load, int & cumhrs, 
                     float & gpa, bool & success)
{
    
    if(inF >> ID >> Fname >> Lname >> load >> cumhrs >> gpa)
        success = true;
    else
        success = false;
    
    
   
}//Read_StudentData


//-|---------------------------------------------------------------------------
//-| Display GPA Report Heading Lines to output file.
//-|---------------------------------------------------------------------------
void Display_GPAReportHeadings(ostream & outF)
{
 outF << "STUDENT GPA REPORT" << endl << endl;
  outF << fixed << showpoint << setprecision(3);
    
outF << "====  =========  ====  =====  ================" << endl;     
    
outF << right <<setw(4) << " GPA"  << "  " 
     << right <<setw(9) << "StudentID" << "  " 
     << right <<setw(4) << "Load" << "  " 
     << right <<setw(5) << "Hours" << "   " 
     << left <<setw(16) << "Student_Name" << "  " 
     <<  endl;    
outF << "====  =========  ====  =====  ================" << endl;
  

}//Display_GPAReportHeadings


//-|---------------------------------------------------------------------------
//-| Write Academic Standing Report heading to output file.
//-|---------------------------------------------------------------------------
void Write_StandingReportHeadings(ostream & outF)
{
cout << "ACADEMIC STANDING REPORT" << endl << endl;
cout << " ====  =========  ====  =====   ================  =================="<< endl;   
cout << right << setw(4) << "GPA" << "  " 
     << right << setw(9) << "StudentID" << "  " 
     << right << setw(4) << "Load" << "  " 
     << right << setw(5) << "Hours" << "   " 
     << left  << setw(16) << "Student_Name" << "  " 
     << left  << setw(18) << "Academic Standing" << endl;   
cout << " ====  =========  ====  =====   ================  =================="<< endl;
 
}//WriteStandingReportHeadings

//-|---------------------------------------------------------------------------
//-| Write student data to GPA report file.
//-|---------------------------------------------------------------------------
void Write_StudentData(ostream & outF, long ID, string Fname, string Lname, 
                      int load, int cumhrs, float gpa)
{

 outF << fixed << setprecision(2) << right <<setw(4) << gpa <<"  "<< ID <<"  " 
   << setw(4) << right << load <<"  "<< setw(5) << right << cumhrs <<"  "
     << setw(16) << left << Lname +", "+Fname <<"   " << endl;

}//Write_StudentData


//-|---------------------------------------------------------------------------
//-| Display student data and standing to monitor.
//-|---------------------------------------------------------------------------
void Display_StudentData(long ID, string Fname, string Lname, 
                        int load, int cumhrs, float gpa, string standing)
{
   
 cout << fixed<< setprecision(2) << right << setw(4) <<gpa<<"  "<<ID<<"  " 
  << setw(4) <<right << load <<"  "<< setw(5) << right << cumhrs<<"   "
   << setw(16) << Lname+", "+Fname <<"      "<< left << standing<< endl; 
   
}//Display_StudentData


//-|---------------------------------------------------------------------------
//-| Display GPA Report Footer.
//-|---------------------------------------------------------------------------
void Display_GPAReportFooter(float GPAavg, float GPA_wtavg)
{
cout << "====  =========  ====  =====  ================  ==================" << endl << endl;
cout << left << setw(23) << "Average Student GPA  = " << fixed << showpoint << setprecision(3) 
     << GPAavg << endl;  
cout <<left << setw(23)<< "Weighted Average GPA = " << fixed << showpoint << setprecision(3) 
     << GPA_wtavg << endl;    
}//Display_GPAReportFooter


//-|---------------------------------------------------------------------------
//-| Write GPA Report Footer.
//-|---------------------------------------------------------------------------
void Write_StandingReportFooter(ostream & outF, float GPAavg, float GPA_wtavg)
{

outF << "====  =========  ====  =====  ================" << endl << endl;
outF << "Average Student GPA  = " << fixed << showpoint << setprecision(3) 
     << GPAavg << endl;   
outF << "Weighted Average GPA = " << fixed << showpoint << setprecision(3) 
     << GPA_wtavg << endl;   
    

}//Write_StandingReportFooter

//*|***************************************************************************
//*| PUT YOUR MAIN DOWN HERE.
//*|***************************************************************************
int main()
{
    
//-----------------------------------------------
// Declare required variables (with comments).
//----------------------------------------------
long ID;
string Fname, Lname, standing;
int load, cumhrs, studentCount;  
float gpa, wtAvg_GPA, avg_GPA, sum_GPA, sum_GPAxCumHrs, sum_CumHours;
bool success; 
    
    
//-|-----------------------------------------------------------------------
//-|  Display copyright.
//-|-----------------------------------------------------------------------

    Display_Copyright();


   //-|--------------------------------------------------------------------------
   //-|  1. Open input and output files.
   //-|     1.1 If the input file can not be opened, display message and terminate.
   //-|--------------------------------------------------------------------------
    
    ifstream inF;
    ofstream outF;  
    
    inF.open("students.dat");
    outF.open("students.rpt");
    if(inF.fail())
    {
        cout <<  "FATAL ERROR: can not OPEN file 'students.dat'."  << endl;
        exit(1);
    }



   //-|-----------------------------------------------------------------------
   //-|  2. Display/write report heading.
   //-|     2.1 Display Academic Standing Report headings to monitor.
   //-|     2.2 Write GPA Report headings to output file.
   //-|-----------------------------------------------------------------------
        Display_GPAReportHeadings(outF);
        Write_StandingReportHeadings(cout);


   //-|-----------------------------------------------------------------------
   //-|  3. Initialize sums and counters to zero.
   //-|     3.1 studentCount = 0
   //-|     3.2 sum_GPA = 0
   //-|     3.3 sum_GPAxCumHrs = 0
   //-|     3.4 sum_CumHours = 0
   //-|-----------------------------------------------------------------------

    studentCount = 0;
    sum_GPA = 0;
    sum_GPAxCumHrs = 0;
    sum_CumHours = 0;


   //-|-----------------------------------------------------------------------
   //-|  4. Read data for one student from input file.
   //-|-----------------------------------------------------------------------
    Read_StudentData(inF, ID, Fname, Lname, load, cumhrs, gpa, success);


   //-|-----------------------------------------------------------------------
   //-|  5. REPEAT as long as data was read successfully:
   //-|     5.1 Count the student.
   //-|     5.2 Write student data to GPA Report.
   //-|     5.3 Determine academic standing of the student.
   //-|     5.4 Write student data and standing to Acadmemic Standing Report.
   //-|     5.5 Update sum_GPA += GPA
   //-|     5.6 Update sum_GPAxCumHrs += GPA * CumHrs
   //-|     5.7 Update sum_CumHrs += CumHrs
   //-|     5.8 Read data for next student from input file.
   //-|-----------------------------------------------------------------------

    while (success)
    {
       
       Write_StudentData(outF,ID,Fname,Lname,load,cumhrs,gpa); 
    if (gpa >= 3.0)
       standing = "HONORS";
    
    else if  (gpa >= 2.0)
       standing = "GOOD STANDING";   
    
    else if (gpa < 2.0 && gpa >= 0.0)
       standing  = "ON PROBATION";
        
       Display_StudentData(ID,Fname, Lname,load, cumhrs,gpa, standing);
        sum_GPA += gpa;
        sum_GPAxCumHrs += gpa * cumhrs;
        sum_CumHours += cumhrs;
        
        studentCount++;
        
       Read_StudentData(inF, ID, Fname, Lname, load, cumhrs, gpa, success);
    }


   //-|-----------------------------------------------------------------------
   //-|  6. Calculate avg_GPA = sum_GPA / studentCount [BEWARE OF zero division]
   //-|-----------------------------------------------------------------------
if( studentCount == 0)
{
    avg_GPA = 0.000;
}
    else
    avg_GPA = sum_GPA / studentCount;


   //-|-----------------------------------------------------------------------
   //-|  7. Calculate wtAvg_GPA = sum_GPAxCumHrs / sum_CumHrs [BEWARE of zero division]
   //-|-----------------------------------------------------------------------
if( sum_CumHours == 0)
{
    wtAvg_GPA = 0.000;
}
    else
    wtAvg_GPA = sum_GPAxCumHrs / sum_CumHours;


   //-|-----------------------------------------------------------------------
   //-|  8. Display Academic Standing Report footer and data (avg_GPA, wtAvg_GPA).
   //-|-----------------------------------------------------------------------

        Display_GPAReportFooter(avg_GPA, wtAvg_GPA);

   //-|-----------------------------------------------------------------------
   //-|  9. Write GPA Report footer and data (avg_GPA, wtAvg_GPA).
   //-|-----------------------------------------------------------------------

        Write_StandingReportFooter(outF, avg_GPA, wtAvg_GPA);

   //-|-----------------------------------------------------------------------
   //-| 10. Close input and output files.
   //-|-----------------------------------------------------------------------
    
        inF.close();
        outF.close();

   //-|-----------------------------------------------------------------------
   //-|  Display copyright.
   //-|-----------------------------------------------------------------------
        Display_Copyright();


    return 0;

}//main
//-|-----------------------------------------------------------------------
//-| File name: StudentReports.cpp
//-| Assign ID: PROG7
//-| 
//-|
//-| Purpose: Write a program to read and format data for three students.
//-|
//-|        (2) Flag the academic status of each student:
//-|                  ON PROBATION  -- when GPA < 2.0
//-|                  HONORS        -- when GPA >= 3.0
//-|                  GOOD STANDING -- when neither honors nor probation.
//-|
//-|              (3) Compute the arithmetic and weighted average GPA of the 
//-|                  three students.
//-|                  
//-| Author: sjean Sony Jean-Baptiste
//-|
//-|-------------------------------------------------------------------------
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//-|---------------------------------------------------------------------------
//-| PRINT student copyright.
//-|---------------------------------------------------------------------------
void Display_Copyright()
{
   cout << endl << "(c) 2017, sjean Sony Jean-Baptiste" << endl << endl;
   
}//Display_Copyright

//-|---------------------------------------------------------------------------
//-| READ a Student Record. Set success flag to indicate 
//-|      successful/unsuccessful read.
//-| 
//-|---------------------------------------------------------------------------
void Read_StudentData(istream & inF, long & ID, string & Fname, 
                     string & Lname, int & load, int & cumhrs, 
                     float & gpa, bool & success)
{
    
    if(inF >> ID >> Fname >> Lname >> load >> cumhrs >> gpa)
        success = true;
    else
        success = false;
    
    
   
}//Read_StudentData


//-|---------------------------------------------------------------------------
//-| Display GPA Report Heading Lines to output file.
//-|---------------------------------------------------------------------------
void Display_GPAReportHeadings(ostream & outF)
{
 outF << "STUDENT GPA REPORT" << endl << endl;
  outF << fixed << showpoint << setprecision(3);
    
outF << "====  =========  ====  =====  ================" << endl;     
    
outF << right <<setw(4) << " GPA"  << "  " 
     << right <<setw(9) << "StudentID" << "  " 
     << right <<setw(4) << "Load" << "  " 
     << right <<setw(5) << "Hours" << "   " 
     << left <<setw(16) << "Student_Name" << "  " 
     <<  endl;    
outF << "====  =========  ====  =====  ================" << endl;
  

}//Display_GPAReportHeadings


//-|---------------------------------------------------------------------------
//-| Write Academic Standing Report heading to output file.
//-|---------------------------------------------------------------------------
void Write_StandingReportHeadings(ostream & outF)
{
cout << "ACADEMIC STANDING REPORT" << endl << endl;
cout << " ====  =========  ====  =====   ================  =================="<< endl;   
cout << right << setw(4) << "GPA" << "  " 
     << right << setw(9) << "StudentID" << "  " 
     << right << setw(4) << "Load" << "  " 
     << right << setw(5) << "Hours" << "   " 
     << left  << setw(16) << "Student_Name" << "  " 
     << left  << setw(18) << "Academic Standing" << endl;   
cout << " ====  =========  ====  =====   ================  =================="<< endl;
 
}//WriteStandingReportHeadings

//-|---------------------------------------------------------------------------
//-| Write student data to GPA report file.
//-|---------------------------------------------------------------------------
void Write_StudentData(ostream & outF, long ID, string Fname, string Lname, 
                      int load, int cumhrs, float gpa)
{

 outF << fixed << setprecision(2) << right <<setw(4) << gpa <<"  "<< ID <<"  " 
   << setw(4) << right << load <<"  "<< setw(5) << right << cumhrs <<"  "
     << setw(16) << left << Lname +", "+Fname <<"   " << endl;

}//Write_StudentData


//-|---------------------------------------------------------------------------
//-| Display student data and standing to monitor.
//-|---------------------------------------------------------------------------
void Display_StudentData(long ID, string Fname, string Lname, 
                        int load, int cumhrs, float gpa, string standing)
{
   
 cout << fixed<< setprecision(2) << right << setw(4) <<gpa<<"  "<<ID<<"  " 
  << setw(4) <<right << load <<"  "<< setw(5) << right << cumhrs<<"   "
   << setw(16) << Lname+", "+Fname <<"      "<< left << standing<< endl; 
   
}//Display_StudentData


//-|---------------------------------------------------------------------------
//-| Display GPA Report Footer.
//-|---------------------------------------------------------------------------
void Display_GPAReportFooter(float GPAavg, float GPA_wtavg)
{
cout << "====  =========  ====  =====  ================  ==================" << endl << endl;
cout << left << setw(23) << "Average Student GPA  = " << fixed << showpoint << setprecision(3) 
     << GPAavg << endl;  
cout <<left << setw(23)<< "Weighted Average GPA = " << fixed << showpoint << setprecision(3) 
     << GPA_wtavg << endl;    
}//Display_GPAReportFooter


//-|---------------------------------------------------------------------------
//-| Write GPA Report Footer.
//-|---------------------------------------------------------------------------
void Write_StandingReportFooter(ostream & outF, float GPAavg, float GPA_wtavg)
{

outF << "====  =========  ====  =====  ================" << endl << endl;
outF << "Average Student GPA  = " << fixed << showpoint << setprecision(3) 
     << GPAavg << endl;   
outF << "Weighted Average GPA = " << fixed << showpoint << setprecision(3) 
     << GPA_wtavg << endl;   
    

}//Write_StandingReportFooter

//*|***************************************************************************
//*| PUT YOUR MAIN DOWN HERE.
//*|***************************************************************************
int main()
{
    
//-----------------------------------------------
// Declare required variables (with comments).
//----------------------------------------------
long ID;
string Fname, Lname, standing;
int load, cumhrs, studentCount;  
float gpa, wtAvg_GPA, avg_GPA, sum_GPA, sum_GPAxCumHrs, sum_CumHours;
bool success; 
    
    
//-|-----------------------------------------------------------------------
//-|  Display copyright.
//-|-----------------------------------------------------------------------

    Display_Copyright();


   //-|--------------------------------------------------------------------------
   //-|  1. Open input and output files.
   //-|     1.1 If the input file can not be opened, display message and terminate.
   //-|--------------------------------------------------------------------------
    
    ifstream inF;
    ofstream outF;  
    
    inF.open("students.dat");
    outF.open("students.rpt");
    if(inF.fail())
    {
        cout <<  "FATAL ERROR: can not OPEN file 'students.dat'."  << endl;
        exit(1);
    }



   //-|-----------------------------------------------------------------------
   //-|  2. Display/write report heading.
   //-|     2.1 Display Academic Standing Report headings to monitor.
   //-|     2.2 Write GPA Report headings to output file.
   //-|-----------------------------------------------------------------------
        Display_GPAReportHeadings(outF);
        Write_StandingReportHeadings(cout);


   //-|-----------------------------------------------------------------------
   //-|  3. Initialize sums and counters to zero.
   //-|     3.1 studentCount = 0
   //-|     3.2 sum_GPA = 0
   //-|     3.3 sum_GPAxCumHrs = 0
   //-|     3.4 sum_CumHours = 0
   //-|-----------------------------------------------------------------------

    studentCount = 0;
    sum_GPA = 0;
    sum_GPAxCumHrs = 0;
    sum_CumHours = 0;


   //-|-----------------------------------------------------------------------
   //-|  4. Read data for one student from input file.
   //-|-----------------------------------------------------------------------
    Read_StudentData(inF, ID, Fname, Lname, load, cumhrs, gpa, success);


   //-|-----------------------------------------------------------------------
   //-|  5. REPEAT as long as data was read successfully:
   //-|     5.1 Count the student.
   //-|     5.2 Write student data to GPA Report.
   //-|     5.3 Determine academic standing of the student.
   //-|     5.4 Write student data and standing to Acadmemic Standing Report.
   //-|     5.5 Update sum_GPA += GPA
   //-|     5.6 Update sum_GPAxCumHrs += GPA * CumHrs
   //-|     5.7 Update sum_CumHrs += CumHrs
   //-|     5.8 Read data for next student from input file.
   //-|-----------------------------------------------------------------------

    while (success)
    {
       
       Write_StudentData(outF,ID,Fname,Lname,load,cumhrs,gpa); 
    if (gpa >= 3.0)
       standing = "HONORS";
    
    else if  (gpa >= 2.0)
       standing = "GOOD STANDING";   
    
    else if (gpa < 2.0 && gpa >= 0.0)
       standing  = "ON PROBATION";
        
       Display_StudentData(ID,Fname, Lname,load, cumhrs,gpa, standing);
        sum_GPA += gpa;
        sum_GPAxCumHrs += gpa * cumhrs;
        sum_CumHours += cumhrs;
        
        studentCount++;
        
       Read_StudentData(inF, ID, Fname, Lname, load, cumhrs, gpa, success);
    }


   //-|-----------------------------------------------------------------------
   //-|  6. Calculate avg_GPA = sum_GPA / studentCount [BEWARE OF zero division]
   //-|-----------------------------------------------------------------------
if( studentCount == 0)
{
    avg_GPA = 0.000;
}
    else
    avg_GPA = sum_GPA / studentCount;


   //-|-----------------------------------------------------------------------
   //-|  7. Calculate wtAvg_GPA = sum_GPAxCumHrs / sum_CumHrs [BEWARE of zero division]
   //-|-----------------------------------------------------------------------
if( sum_CumHours == 0)
{
    wtAvg_GPA = 0.000;
}
    else
    wtAvg_GPA = sum_GPAxCumHrs / sum_CumHours;


   //-|-----------------------------------------------------------------------
   //-|  8. Display Academic Standing Report footer and data (avg_GPA, wtAvg_GPA).
   //-|-----------------------------------------------------------------------

        Display_GPAReportFooter(avg_GPA, wtAvg_GPA);

   //-|-----------------------------------------------------------------------
   //-|  9. Write GPA Report footer and data (avg_GPA, wtAvg_GPA).
   //-|-----------------------------------------------------------------------

        Write_StandingReportFooter(outF, avg_GPA, wtAvg_GPA);

   //-|-----------------------------------------------------------------------
   //-| 10. Close input and output files.
   //-|-----------------------------------------------------------------------
    
        inF.close();
        outF.close();

   //-|-----------------------------------------------------------------------
   //-|  Display copyright.
   //-|-----------------------------------------------------------------------
        Display_Copyright();


    return 0;

}//main
