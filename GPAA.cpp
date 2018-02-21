//------------------------------------------------------------------
// File name: StudentGPAs.cpp
// Assign ID: PROG4
// Due Date: 02/02/2017 at 23:00
//
// Purpose: Write a program to read and format data for three students.
//
//         (2) Flag the academic status of each student:
//                  ON PROBATION  -- when GPA < 2.0
//                  HONORS        -- when GPA >= 3.0
//                  GOOD STANDING -- when neither honors nor probation.
//
//              (3) Compute the arithmetic and weighted average GPA of the 
//                  three students.
//                  
// Author: sjean Byoung Cwinn 
//
//------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;
int main()

{  
//-|---------------------------------------------------------------------
//-| Declare variables.
//-|--------------------------------------------------------------------- 
  
int CourseLoad1,
    CourseLoad2,
    CourseLoad3,
    CumHours1,
    CumHours2,
    CumHours3;


 string FirstName1,
        FirstName2,
        FirstName3,
        LastName1,
        LastName2,
        LastName3,
        AcademicStanding1,
        AcademicStanding2,
        AcademicStanding3;

 float GPA1,
        GPA2,
        GPA3,
        avgGPA,
        WtAvgGPA;
 
 long Student_ID1,
      Student_ID2,
      Student_ID3;
        
    
//-|------------------------------------------------------------    
//-| 1. Open input and output files.  
//-|------------------------------------------------------------    
    ifstream inF;
    ofstream outF;  
    
    inF.open("students.dat");
    outF.open("students.rpt");
    
//-|------------------------------------------------------------    
//-| 1.1 If the input file can not be opened,  
//-|------------------------------------------------------------ 
    if (inF.fail())
        {
            cout << " FATAL ERROR: can not OPEN file 'students.dat'." << endl;
       
            exit(0);   
        }   

    
//-|------------------------------------------------------------    
//-| 2. Read input data for each student.  
//-|------------------------------------------------------------      
    inF >> Student_ID1 >> FirstName1 >> LastName1 >> CourseLoad1 >> CumHours1 >> GPA1;
    inF >> Student_ID2 >> FirstName2 >> LastName2 >> CourseLoad2 >> CumHours2 >> GPA2;
    inF >> Student_ID3 >> FirstName3 >> LastName3 >> CourseLoad3 >> CumHours3 >> GPA3; 

//-|------------------------------------------------------------    
//-| 3. Determine academic standing of each student.  
//-|------------------------------------------------------------    
    if (GPA1 >= 3.0)
         AcademicStanding1 = "HONORS";
    
    else if  (GPA1 >= 2.0)
        AcademicStanding1 = "GOOD STANDING";   
    
    else if (GPA1 < 2.0 && GPA1 >= 0.0)
        AcademicStanding1  = "ON PROBATION";
//-|-------------------------------------------------------------    
    if (GPA2 >= 3.0)
         AcademicStanding2 = "HONORS";
    
    else if  (GPA2 >= 2.0)
        AcademicStanding2 = "GOOD STANDING";   
    
    else if (GPA2 < 2.0 && GPA2 >= 0.0)
        AcademicStanding2  = "ON PROBATION";
//-|--------------------------------------------------------------     
    if (GPA3 >= 3.0)
         AcademicStanding3 = "HONORS";
    
    else if  (GPA3 >= 2.0)
        AcademicStanding3 = "GOOD STANDING";   
    
    else if (GPA3< 2.0 && GPA3 >= 0.0)
        AcademicStanding3  = "ON PROBATION";
    
        
//-|------------------------------------------------------------    
//-| 4. Calculate average GPA = (GPA1 + GPA2 + GPA3) / 3.0;  
//-|------------------------------------------------------------       
    avgGPA = (GPA1 + GPA2 + GPA3) / (3.0);
    
//-|------------------------------------------------------------    
//-| 5. Calculate the weighted average GPA:   
//-|------------------------------------------------------------        
    WtAvgGPA = ((GPA1 * CumHours1) + (GPA2 * CumHours2) + (GPA3 * CumHours3)) / (CumHours1 + CumHours2 + CumHours3);
    
//-|------------------------------------------------------------    
//-|  6. Write GPA Report headings.          
//-|  7. Write output line for each student.  
//-|  8. Write GPA report footer.           
//-|  9. Write average GPA.               
//-| 10. Write weighted average GPA.  
//-|------------------------------------------------------------    

cout << "ACADEMIC STANDING REPORT" << endl << endl;
cout << right << setw(4) << "====" << "  " << right << setw(9) << "=========" << "  ";
cout << right << setw(4)<< "====" << "  " << right << setw(4) << "=====" << "  ";
cout << left << setw(16) << "================" << "  "  << left << setw(18) << "==================" << endl;    
cout << right << setw(4) << "GPA" << "  " << right << setw(9) << "StudentID" << "  " << right << setw(4) << "Load";
cout << "  " << right << setw(4) << "Hours" << "  " << left << setw(16) << "Student_Name" << "  ";
cout << left << setw(18) << "Academic Standing" << endl;    
cout << right << setw(4) << "====" << "  " << right << setw(9) << "=========" << "  ";
cout << right << setw(4)<< "====" << "  " << right << setw(4) << "=====" << "  ";
cout << left << setw(16) << "================" << "  "  << left << setw(18) << "==================" << endl;
    
//-|------------------------------------------------------------    
//-| 12. Display output line for each student. 
//-|------------------------------------------------------------             
cout << right << setw(4) << fixed << setprecision(2) << GPA1 << "  "; 
cout << right << setw(9) << Student_ID1 << "  " << right << setw(4) << CourseLoad1 << "  "; 
cout << right << setw(5) << CumHours1 << "  "; 
cout << left << setw(16) << LastName1 + "," + FirstName1 << "  " << left << setw(18) << AcademicStanding1 << endl;
//--------------------------------------------------------------
cout << right << setw(4) << fixed << setprecision(2) << GPA2 << "  "; 
cout << right << setw(9) << Student_ID2 << "  " << right << setw(4) << CourseLoad2 << "  "; 
cout << right << setw(5) << CumHours2 << "  "; 
cout << left << setw(16) << LastName2 + "," + FirstName2 << "  " << left << setw(18) << AcademicStanding2 << endl;
//--------------------------------------------------------------   
cout << right << setw(4) << fixed << setprecision(2) << GPA3 << "  "; 
cout << right << setw(9) << Student_ID3 << "  " << right << setw(4) << CourseLoad3 << "  "; 
cout << right << setw(5) << CumHours3 << "  "; 
cout << left << setw(16) << LastName3 + "," + FirstName3 << "  "; 
cout << left << setw(18) << AcademicStanding3 << endl;
    
//-|------------------------------------------------------------    
//-| 13. Display Academic Standing Report footer.   
//-|------------------------------------------------------------            
cout << right << setw(4) << "====" << "  " << right << setw(9) << "=========" << "  ";
cout << right << setw(4)<< "====" << "  " << right << setw(4) << "=====" << "  ";
cout << left << setw(16) << "================" << "  "  << left << setw(18) << "==================" << endl << endl;
    
//-|------------------------------------------------------------    
//-| 14. Display average GPA.   
//-|------------------------------------------------------------           
cout << left << setw(23) << " Average Student GPA = "; 
cout << right << setw(5) << fixed << setprecision(3) << avgGPA << endl << endl;    
//-|------------------------------------------------------------    
//-| 15. Display weighted average GPA.  
//-|------------------------------------------------------------           
cout << left << setw(23) << " Weighted Average GPA = "; 
cout << right << setw(5) << fixed << setprecision(3) << WtAvgGPA << endl << endl;    
    
    
    
//-|------------------------------------------------------------    
//-| 11. Display Academic Standing Report headings.    
//-|------------------------------------------------------------           
outF << " ACADEMIC STANDING REPORT" << endl << endl;
outF << right << setw(4) << "====" << "  " << right << setw(9) << "=========" << "  ";
outF << right << setw(4)<< "====" << "  " << right << setw(4) << "=====" << "  ";
outF << left << setw(16) << "================" << "  "  << left << setw(18) << "==================" << endl;    
outF << right << setw(4) << "GPA" << "  " << right << setw(9) << "StudentID" << "  " << right << setw(4) << "Load";
outF << "  " << right << setw(4) << "Hours" << "  " << left << setw(16) << "Student_Name" << "  ";
outF << left << setw(18) << "Academic Standing" << endl;    
outF << right << setw(4) << "====" << "  " << right << setw(9) << "=========" << "  ";
outF << right << setw(4)<< "====" << "  " << right << setw(4) << "=====" << "  ";
outF << left << setw(16) << "================" << "  "  << left << setw(18) << "==================" << endl;
    
//-|------------------------------------------------------------    
//-| 12. Display output line for each student. 
//-|------------------------------------------------------------             
outF << right << setw(4) << fixed << setprecision(2) << GPA1 << "  "; 
outF << right << setw(9) << Student_ID1 << "  " << right << setw(4) << CourseLoad1 << "  "; 
outF << right << setw(5) << CumHours1 << "  "; 
outF << left << setw(16) << LastName1 + "," + FirstName1 << "  " << left << setw(18) << AcademicStanding1 << endl;
//-|-------------------------------------------------------------
outF << right << setw(4) << fixed << setprecision(2) << GPA2 << "  "; 
outF << right << setw(9) << Student_ID2 << "  " << right << setw(4) << CourseLoad2 << "  "; 
outF << right << setw(5) << CumHours2 << "  "; 
outF << left << setw(16) << LastName2 + "," + FirstName2 << "  " << left << setw(18) << AcademicStanding2 << endl;
//-|-------------------------------------------------------------   
outF << right << setw(4) << fixed << setprecision(2) << GPA3 << "  "; 
outF << right << setw(9) << Student_ID3 << "  " << right << setw(4) << CourseLoad3 << "  "; 
outF << right << setw(5) << CumHours3 << "  "; 
outF << left << setw(16) << LastName3 + "," + FirstName3 << "  " << left << setw(18) << AcademicStanding3 << endl;
    
//-|------------------------------------------------------------    
//-| 13. Display Academic Standing Report footer.   
//-|------------------------------------------------------------            
outF << right << setw(4) << "====" << "  " << right << setw(9) << "=========" << "  ";
outF << right << setw(4)<< "====" << "  " << right << setw(4) << "=====" << "  ";
outF << left << setw(16) << "================" << "  "  << left << setw(18) << "==================" << endl << endl;
    
//-|------------------------------------------------------------    
//-| 14. Display average GPA.   
//-|------------------------------------------------------------           
outF << left << setw(23) << " Average Student GPA = "; 
outF << right << setw(5) << fixed << setprecision(3) << avgGPA << endl;    
//-|------------------------------------------------------------    
//-| 15. Display weighted average GPA.  
//-|------------------------------------------------------------           
outF << left << setw(23) << " Weighted Average GPA = "; 
outF << right << setw(5) << fixed << setprecision(3) << WtAvgGPA << endl;  
    
//-|-----------------------------------------------------------------------------------------    
//-|------------------------------------------------------------    
//-| Student GPA Report.    
//-|------------------------------------------------------------           
  outF << " STUDENT GPA REPORT" << endl << endl;
outF << right << setw(4) << "====" << "  " << right << setw(9) << "=========" << "  ";    
outF << right << setw(4)<< "====" << "  " << right << setw(4) << "=====" << "  ";   
outF << left << setw(16) << "================" << "  "  << left << setw(18) << endl;     
outF << right << setw(4) << "GPA" << "  " << right << setw(9) << "StudentID"; 
outF << "  " << right << setw(4) << "Load";
outF << "  " << right << setw(4) << "Hours" << "  " << left << setw(16) << "Student_Name"; 
outF << "  " << left << setw(18) << endl;    
outF << right << setw(4) << "====" << "  " << right << setw(9) << "=========" << "  ";
outF << right << setw(4)<< "====" << "  " << right << setw(4) << "=====" << "  ";
outF << left << setw(16) << "================" << "  "  << left << setw(18) << endl;
    
//-|------------------------------------------------------------    
//-| 12. Display output line for each student. 
//-|------------------------------------------------------------             
outF << right << setw(4) << fixed << setprecision(2) << GPA1 << "  "; 
outF << right << setw(9) << Student_ID1 << "  " << right << setw(4) << CourseLoad1 << "  "; 
outF << right << setw(5) << CumHours1 << "  "; 
outF << left << setw(16) << LastName1 + "," + FirstName1 << "  " << left << setw(18) << endl;
//-|-------------------------------------------------------------
outF << right << setw(4) << fixed << setprecision(2) << GPA2 << "  "; 
outF << right << setw(9) << Student_ID2 << "  " << right << setw(4) << CourseLoad2 << "  "; 
outF << right << setw(5) << CumHours2 << "  "; 
outF << left << setw(16) << LastName2 + "," + FirstName2 << "  " << left << setw(18) <<  endl;
//-|-------------------------------------------------------------   
outF << right << setw(4) << fixed << setprecision(2) << GPA3 << "  "; 
outF << right << setw(9) << Student_ID3 << "  " << right << setw(4) << CourseLoad3 << "  "; 
outF << right << setw(5) << CumHours3 << "  "; 
outF << left << setw(16) << LastName3 + "," + FirstName3 << "  " << left << setw(18) << endl;
    
//-|------------------------------------------------------------    
//-| 13. Display Academic Standing Report footer.   
//-|------------------------------------------------------------            
outF << right << setw(4) << "====" << "  " << right << setw(9) << "=========" << "  ";
outF << right << setw(4)<< "====" << "  " << right << setw(4) << "=====" << "  ";
outF << left << setw(16) << "================" << "  "  << left << setw(18) << endl << endl;
    
//-|------------------------------------------------------------    
//-| 14. Display average GPA.   
//-|------------------------------------------------------------           
outF << left << setw(23) << " Average Student GPA = "; 
outF << right << setw(5) << fixed << setprecision(3) << avgGPA << endl;    
//-|------------------------------------------------------------    
//-| 15. Display weighted average GPA.  
//-|------------------------------------------------------------           
outF << left << setw(23) << " Weighted Average GPA = "; 
outF << right << setw(5) << fixed << setprecision(3) << WtAvgGPA << endl;   
    
    
 
//-| -----------------------------------------------------------
//-| 16. Close input and output files.
//-| -----------------------------------------------------------
    inF.close();
    outF.close();
    
//-|--------------------------------------------------------------------
//-| Display the copyright notice declaring authorship again.
//-|--------------------------------------------------------------------        
    cout << endl << "(c) 2017, sjean byoung cwinn " << endl << endl;
 

return 0;
}//main 