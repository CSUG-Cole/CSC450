# Module 1: Critical Thinking Assignment Statement

Demonstrate an understanding of basic C++ programming
concepts by completing the following: 

1. Create a simple C++ console application using Eclipse
   IDE that will accomplish the following:

    1. First Name, 
    2. Last Name, 
    3. Street Address
    4. City
    5. Zip code

   Prints the following information for a fictional person:

2. Given the provided code in file CSC450_CT1_mod1-1.cpp
   Download CSC450_CT1_mod1-1.cpp, correct all syntax errors
   so that the code will compile correctly. 

3. Given the provided code in file CSC450_CT1_mod1-2.cpp
   Download CSC450_CT1_mod1-2.cpp, correct all syntax errors
   so that the code will compile correctly. 

Compile and submit your pseudocode, source code, and
screenshots of the application executing the application,
the results and your GIT repository in a single document. 

## Part 1 Documentation

The solution to part one can be found in the `Person`
directory which contains a single `.cpp` file that satisfies
the requirements. The last part of the assignment cuts off,
so I had to fill in the details myself. I chose to print the
fictional person's information in the format one might use
to send them a letter. I also chose to implement a `Person`
class to handle setting the details of the person, and
displaying the information. Aside from the stated
requirements, I implemented validation for the zip code
parameter. This requires the user to enter a zip code
exactly 5 digits long, and not just any random string.

## Part 2 Correction 1

This file had several genuine syntax errors mainly revolving
around missing comments. There was also an invalid (at least
on my machine) `#include` statement, missing quotes around
one string to be displayed, and a missing return statement
at the end of the `main` function. I added some additional
white space to the file to make the formatting less cramped,
but this was not strictly speaking a syntax error. 

The corrected file can be found at `Corrections/CSC450_CT1_mod1-1-FIXED.cpp`.

Here is the diff:

``` diff
--- CSC450_CT1_mod1-1.cpp	2024-10-11 11:28:29.224374997 -0700
+++ CSC450_CT1_mod1-1-FIXED.cpp	2024-10-11 15:16:08.309526516 -0700
@@ -1,24 +1,25 @@
 /* Simple Program with a few Errors for Correction
-   Please be sure to correct all outlined errors.
+   Please be sure to correct all outlined errors. */
 
 
-#include<iostream>
-#include<conio.h>
+#include <iostream>
+// #include <conio.h>
 
-Standard namespace declaration
+/* Standard namespace declaration */
 using namespace std;
 
-Main Function
+/* Main Function */
 int main()
 {
 
      //Standard Ouput Statement
-     cout<<"Welcome to this C++ Program"<<endl;
+     cout << "Welcome to this C++ Program" << endl;
 
-     cout<<I have corrected all errors for this program. <<endl;
+     cout << "I have corrected all errors for this program." << endl;
 
      // Wait For Output Screen
 
      //Main Function return Statement
 
+     return 0;
 }
```

## Part 3 Correction 2

This file had many of the same errors as correction 1, as
well as a missing parameter for the last print statement.

The corrected file can be found at `Corrections/CSC450_CT1_mod1-2-FIXED.cpp`.

Here is the diff:

``` diff
--- CSC450_CT1_mod1-2.cpp	2024-10-11 11:28:53.370627764 -0700
+++ CSC450_CT1_mod1-2-FIXED.cpp	2024-10-11 15:19:19.150773376 -0700
@@ -1,27 +1,25 @@
+#include <iostream>
+/* #include<conio.h> */
 
-
-#include<iostream>
-#include<conio.h>
-
-Standard namespace declaration
+/* Standard namespace declaration */
 using namespace std;
 
-Main Function
+/* Main Function */
 int main()
 {
 
      double myMoney = 1000.50;  //this should be printed out
 
 
-     Standard Ouput Statement
-     cout"Please be sure to correct all syntax errors in this program"<<endl;
+     /* Standard Ouput Statement */
+     cout << "Please be sure to correct all syntax errors in this program" <<endl;
 
-     cout<<"I have corrected all errors for this program. <<endl;
+     cout << "I have corrected all errors for this program." <<endl;
 
-     cout<<" The total amount of money available is = "<<   <<endl;
+     cout << "The total amount of money available is = " << myMoney <<endl;
 
      // Wait For Output Screen
 
-     Main Function return Statement
+     /* Main Function return Statement */
      return 0;
 }
```
