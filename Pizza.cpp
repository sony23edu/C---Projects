//------------------------------------------------------------------
// File name: pizzaNstuff.cpp
// Assign ID: PROG3c
// Due Date: 09/22/2017 at 23:00
//
// Purpose: Calculate orders and print a reciept.
//
//
// Author: sjean Sony Jean-Baptiste
//
//------------------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
float PriPizza;
float PriDrink;
float PriBreadStick;
float PriCookie;
int quaPizza;
int quaDrink;
int quaBreadStick;
int quaCookie;
float AmoTendered;
float totalamount;
float taxrate = 0.075;
float salestax;
float amountdue;
float changedue;
//-|--------------------------------------------------------------------
//-| Display the copyright notice declaring authorship.
//-|--------------------------------------------------------------------
 cout << endl << "(c) 2017, sjean Sony Jean-Baptiste " << endl << endl;
    
//-|-----------------------------------------------
 //-| 2.    read price orders
 //-| 2.1 . read price of pizza.
 //-| 2.2 . read price of drink.
 //-| 2.3 . read price of breadsticks.
 //-| 2.4 . read price of cookie.
 //-|-----------------------------------------------

cout << "Enter cost of today's Pizza:  ";
cin >> PriPizza;
cout << endl;
cout << "Enter cost of today's Drinks: ";
cin >> PriDrink;
cout << endl;
cout << "Enter cost of today's Bread Sticks: ";
cin >> PriBreadStick;
cout << endl;
cout << "Enter cost of today's Cookie: ";
cin >> PriCookie;
cout << endl;
    


cout << "TODAY'S MENU at PIZZA-N-STUFF" << endl; 
    
cout   << setw(6) << "$" << setw(6) << setprecision(2) << fixed << PriPizza << " - Pizza of the Day" << endl;
cout  << setw(6) << "$" << setw(6)  << setprecision(2) << fixed << PriDrink << " - 2L Drink" << endl;
cout  << setw(6) << "$" << setw(6) << setprecision(2) << fixed << PriBreadStick << " - Bread Sticks(6)" << endl;
cout  << setw(6) << "$" << setw(6) << setprecision(2) << fixed << PriCookie << " - Big Cookie" << endl << endl;
    
    
 //-|-----------------------------------------------
 //-| 3. input numbers of items ordered.
 //-| 3.1 . input number of pizzas.
 //-| 3.2 . input number of drinks.
 //-| 3.3 . input number of breadsticks.
 //-| 3.4 . input number of cookies.
 //-|-----------------------------------------------
cout << "Enter number of Pizzas: ";
cin >> quaPizza;
cout << endl;
cout << "Enter number of Drinks: ";
cin >> quaDrink;
cout << endl;
cout << "Enter number of Bread Stick orders: ";
cin >> quaBreadStick;
cout << endl;
cout << "Enter number of Cookies: ";
cin >> quaCookie;
cout << endl;
    
    
 //-|-----------------------------------------------
 //-| 4. compute total cost of order.
 //-| 4.1 . compute pizzacost. (numpizzas * pizzaPrice).
 //-| 4.2 . compute drinkcost. (numDrink * drinkPrice).
 //-| 4.3 . compute breadStickCost. (numBreadStick * breadStickPrice).
 //-| 4.4 . compute cookieCost. (numcookie * cookiePrice).
 //-| 4.5 . compute totalamount. (pizzacost + drinkcost + breadStickCost + cookieCost).
 //-| 4.6 . compute salestax. (totalamount * taxrate).
 //-| 4.7 . compute amountdue. (totalamount + salestax).
 //-|-----------------------------------------------
totalamount = PriPizza * quaPizza + PriDrink * quaDrink + PriBreadStick * quaBreadStick + PriCookie * quaCookie;
salestax = totalamount * taxrate;
amountdue = totalamount + salestax;
    

 //-|-----------------------------------------------
 //-| 6. read amount tendered.
 //-|-----------------------------------------------
cout << "Amount Due: $ " << amountdue << endl << endl;
cout << "Enter payment: ";
cin >> AmoTendered;
    
    
 //-|-----------------------------------------------
 //-| 7. compute changedue. ( amountdue - amounttendered).
 //-|-----------------------------------------------
changedue = (AmoTendered - amountdue);
    

 //-|-----------------------------------------------
 //-| 9. display order to screen.
 //-|-----------------------------------------------
cout << "CUSTOMER RECEIPT" << endl;
cout << "===================================" << endl << endl;
cout << "YOUR ORDER: " << endl << endl;
cout << setw(10) << "#Pizzas" << " = " << quaPizza << endl;
cout << setw(10) << "#Drinks" << " = "  << quaDrink << endl;
cout << setw(10) << "#Breads" << " = " << quaBreadStick << endl ;
cout << setw(11) << "#Cookies" << "= " << quaCookie << endl << endl;
    

 //-|-----------------------------------------------
 //-| 10.    display amount of order.
 //-| 10.1 . display sales tax.
 //-| 10.2 . display amount tendered.
 //-| 10.3 . display change due
 //-|-----------------------------------------------
cout << "YOUR PAYMENT: " << endl << endl;
cout << setw(5) << "     AMOUNT OF ORDER" << " = $" << setw(6) << right << setprecision(2) << fixed << totalamount << endl;
cout << setw(5)  << "     SALES TAX" << setw(6) << "       = " << setw(1) << "$" << setw(6) << right << setprecision(2) << fixed << salestax << endl;
cout << setw (5) << "     AMOUNT DUE" << setw(6) << "      = " << setw(1) << "$  " << setw(5) << right << setprecision(2) << fixed << amountdue << endl;
cout << setw (5) << "     AMOUNT TENDERED" << setw(2) << " = $   " << setw(4) << setprecision(2) << fixed << AmoTendered << endl;
cout << setw (5) << "     CHANGE RECEIVED" << setw(2) << " = $   " << setw(3) << setprecision(2) << fixed << changedue << endl;
cout << "THANKS FOR YOUR BUSINESS. COME AGAIN." << endl;


//-|--------------------------------------------------------------------
//-| Display the copyright notice declaring authorship again.
//-|--------------------------------------------------------------------
 cout << endl << "(c) 2017, sjean Sony Jean-Baptiste " << endl << endl;
return 0;
}//main