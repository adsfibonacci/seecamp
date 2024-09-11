#include <string> 
#include <iostream> 
#include <stdio.h>
#include <sstream>
#include <assert.h>
#include <cstring>
#include <cmath> // For std::fabs
#include <chrono>
#include <fstream>

#include "header/Challenge1.h"
#include "header/Challenge2.h"
#include "header/Challenge3.h"
#include "header/Challenge4.h"
#include "header/Challenge5.h"

using namespace std;

class autograder{
private:
  int m_hint1, m_hint2, m_hint3, m_hint4, m_hint5;
  fstream hint;
  fstream answers;
  bool areCloseEnough(double a, double b, double tolerance = 0.01) {
	return fabs(a - b) < tolerance;
  }
  
public:
  autograder() {
	hint.open("hints.txt");
	hint >> m_hint1 >> m_hint2 >> m_hint3 >> m_hint4 >> m_hint5;
	hint.close();

	answers.open("answers.txt");	
  }
  ~autograder() {
	hint.open("hints.txt");
	hint << m_hint1 << "\n";
	hint << m_hint2 << "\n";
	hint << m_hint3 << "\n";
	hint << m_hint4 << "\n";
	hint << m_hint5 << "\n";
	hint.close();

	answers.close();
  }
  
  // Check Challenge
  void checkChallenge1(){
	// Redirect standard output to a string stream
	ostringstream oss;
	streambuf* p_cout_buf = cout.rdbuf();
	cout.rdbuf(oss.rdbuf());
	printHelloWorld();
	cout.rdbuf(p_cout_buf);
	if(oss.str() == "Hello World!"){cout << "Challenge 1 passed!" << endl;}
	else{cout << "Challenge 1 failed! " << oss.str() << endl;}
  }
  void checkChallenge2(){	
	if(calculator(2,3,'+') != 5){cout << "Challenge 2 failed!\n Failed test case 2 + 3 = 5" << endl;}
	else if(calculator(5,2,'-') != 3){cout << "Challenge 2 failed!\n Failed test case 5 - 2 = 3" << endl;}
	else if(calculator(10,5,'*') != 50){cout << "Challenge 2 failed!\n Failed test case 10 * 5 = 50" << endl;}
	else if(calculator(8,4,'/') != 2){cout << "Challenge 2 failed!\n Failed test case 8 / 4 = 2" << endl;}
	else if(calculator(-2,3,'+') != 1){cout << "Challenge 2 failed!\n Failed test case -2 + 3 = 1" << endl;}
	else if(calculator(5,-2,'-') != 7){cout << "Challenge 2 failed!\n Failed test case 5 - -2 = 7" << endl;}
	else if(calculator(10,-5,'*') != -50){cout << "Challenge 2 failed!\n Failed test case 10 * -5 = -50" << endl;}
	else if(calculator(-10,5,'/') != -2){cout << "Challenge 2 failed!\n Failed test case -10 / 5 = -2" << endl;}
	else {cout << "Challenge 2 passed!" << endl;}
  }
  void checkChallenge3(){
	int people[] = {103, 45, 23, 120, 92, 78, 23, 137, 68, 45, 23, 56, 78, 90, 34, 56, 78, 90};
	int numRides = 18; 
	string campers[] = {"Cheick", "Cayden", "Gracie", "Sophie", "Roman", "Jude",
						"Kayla", "Wyatt", "Noah", "Jiyun", "Anita", "Nathan",
						"Kiera", "Evelyn", "Max", "Henry", "Dahlia", "Terry",
						"Ale", "Aine", "Beatrice", "Ojas", "Nayan", "Alyssa",
						"David", "Quinn", "Ava", "Jozi", "Bryan", "Lydia",
						"Cate", "Marco", "Gus", "Brooke", "Paula",
						"Annika", "Nora", "J.B.", "Rohan", "Carolyn"};
	int numCampers = 40; 
	
	// Assuming totalPeople_forLoop and findCamper_whileLoop are defined correctly elsewhere
	if(totalPeople_forLoop(people, numRides) != 1239){
	  cout << "Challenge 3 failed!\n totalPeople_forLoop() incorrect" << endl;
	}
	else if(findCamper_whileLoop(campers, numCampers) != 27){
	  cout << "Challenge 3 failed!\n findCamper_whileLoop() incorrect" << endl;
	}
	else {
	  cout << "Challenge 3 passed!" << endl;
	}
  }
  void checkChallenge4(){
	if (calculateThrillLevel(22) != 1){cout << "Challenge 4 failed!\n calculateThrillLevel(22) = 1 incorrect" << endl;}
	else if (calculateThrillLevel(30) != 2){cout << "Challenge 4 failed!\n calculateThrillLevel(30) = 2 incorrect" << endl;}
	else if (calculateThrillLevel(60) != 3){cout << "Challenge 4 failed!\n calculateThrillLevel(60) = 3 incorrect" << endl;}
	else if (calculateThrillLevel(110) != 4){cout << "Challenge 4 failed!\n calculateThrillLevel(110)= 4 incorrect" << endl;}
	else if (calculateThrillLevel(130) != 5){cout << "Challenge 4 failed!\n calculateThrillLevel(130) = 5 incorrect" << endl;}
	else {cout << "Challenge 4 passed!" << endl;}
  }
  void checkChallenge5(){
	if (!areCloseEnough(convertToLbs(1), 2.20462)) {
	  cout << "Challenge 5 failed!\n convertToLbs(1) = 2.2 incorrect" << endl;
	}
	else if (!areCloseEnough(convertToLbs(52), 114.64024)) {
	  cout << "Challenge 5 failed!\n convertToLbs(52) = 114.64024 incorrect" << endl;
	}
	else if (!areCloseEnough(convertToLbs(1000), 2204.62)) {
	  cout << "Challenge 5 failed!\n convertToLbs(1000) = 2204.62 incorrect" << endl;
	}
	else if (!areCloseEnough(convertToLbs(1500), 3306.93)) {
	  cout << "Challenge 5 failed!\n convertToLbs(1500) = 3306.93 incorrect" << endl;
	}
	else {
	  double weights[] = {2, 3, 6, 3, 9, 7, 4};
	  if (!areCloseEnough(totalWeight(weights, 7), 74.957)) {
		cout << totalWeight(weights, 7)<< endl;
		cout << "Challenge 5 failed!\n totalWeight([2,3,6,3,9,7,4],7) = 74.96 incorrect" << endl;
	  }
	  else {cout << "Challenge 5 passed!" << endl;}
	}
  }
   
  // Challenge Hits
  void challenge1Hints(){
	if(m_hint1 == 0){
	  cout << "Hint 1" << endl;
	  cout << "Are using output stream operator correctly? Syntax: cout << <what you want to print>" << endl; 
	  m_hint1++;
	}
	else if(m_hint1 == 1){
	  cout << "Hint 2" << endl;
	  cout << "Check the syntax of the string you are trying to print. It should be \"Hello World!\". Include double quotes because we are printing a string" << endl; 
	  m_hint1++;
	}
	else if(m_hint1 == 2){
	  cout << "Hint 3" << endl;
	  cout << "The grader is case sensitive, are H and W capitalized?" << endl; 
	  m_hint1++;
	}else{
	  cout<< "\nYou have used all the hints for this challenge, do you want to see the answer?" << endl;
	  cout << "1) Yes\n2) No" << endl;
	  int choice;
	  answers >> choice;
	  if(choice==1){
		challenges1Answer();
	  }
	  return; 
	}  
	return; 
  }
  void challenge2Hints(){
	if(m_hint2 == 0){
	  cout << "Hint 1" << endl;
	  cout << "In C/C++, characters should be enclosed in single quotes. Are the char operators in your if statements encoding in the correct quotes? Example: if (operation == '+')" << endl;
	  m_hint2++;
	}else if(m_hint2 == 1){
	  cout << "Hint 2" << endl;
	  cout << "Make sure to include the correct operator (==,!=, <, >, <=, >=) and the correct operands in the if statements. Example: if (operation == '+') return var1 + var2;" << endl; 
	  m_hint2++;
	}else if(m_hint2 == 2){
	  cout << "Hint 3" << endl;
	  cout << "Instead of creating an answer varible, you can return the result of the operation directly in the if statements. Example: return var1 + var2;" << endl;
	  m_hint2++;
	}else{
	  cout<< "\nYou have used all the hints for this challenge, do you want to see the answer?" << endl;
	  cout << "1) Yes\n2) No" << endl;
	  int choice;
	  answers >> choice;
	  if(choice==1){
		challenges2Answer();
	  }
	  return; 
	}  
	return; 
  }
  void challenge3Hints(){
	if(m_hint3 == 0){
	  cout << "Hint 1" << endl;
	  cout << "For Loop: Create a new variable to store the total number of people at the park. Initialize it to 0 and use a for loop to iterate through the array of people at each ride and add it to the total people variable." << endl;
	  cout << "While Loop: Create a new variable to store the index of Jozi. Initialize it to 0 and use a while loop to iterate through the list of camper's names. Check if the current name is 'Jozi' and return the index if found." << endl;
	  m_hint3++;
	}
	else if(m_hint3 == 1){
	  cout << "Hint 2" << endl;
	  cout << "Syntax: To get the value of an array at index i use <ArrayName>[i]. Remember arrays are 0 indexed." << endl;
	  m_hint3++;
	}
	else if(m_hint3 == 2){
	  cout << "Hint 3" << endl;
	  cout << "Name sure you are returning the correct value for each function. For loop: TOTAL number of people. While loop: INDEX of Jozi's name" << endl; 
	  m_hint3++;
	}
	else{
	  cout<< "\nYou have used all the hints for this challenge, do you want to see the answer?" << endl;
	  cout << "1) Yes\n2) No" << endl;
	  int choice;
	  answers >> choice;
	  if(choice==1){
		challenges3Answer();
	  }
	  return; 
	}  
	return; 
	
  }
  void challenge4Hints(){
	if(m_hint4 == 0){
	  cout << "Hint 1" << endl;
	  cout << "To check if the speed within a range, check 2 conditions in the if statements. Example sudocode: is speed >= 0 AND speed <=25  " << endl;
	  m_hint4++;
	}
	else if(m_hint4 == 1){
	  cout << "Hint 2" << endl;
	  cout << "Ensure the ranges are mutually exclusive and cover all possible valid inputs with no overlap." << endl; 
	  m_hint4++;
	}
	else if(m_hint4 == 2){
	  cout << "Hint 3" << endl;
	  cout << "Make sure you are returning the correct thrill level for each range. Example: return 1 for speeds between 0-25 mph." << endl; 
	  m_hint4++;
	}else{
	  cout<< "\nYou have used all the hints for this challenge, do you want to see the answer?" << endl;
	  cout << "1) Yes\n2) No" << endl;
	  int choice;
	  answers >> choice;
	  if(choice==1){
		challenges4Answer();
	  }
	  return; 
	}  
	return; 
  }
  void challenge5Hints(){
	if(m_hint5 == 0){
	  cout << "Hint 1" << endl;
	  cout << "To convert kilograms to pounds, multiply the weight by 2.20462." << endl;
	  m_hint5++;
	}else if(m_hint5 == 1){
	  cout << "Hint 2" << endl;
	  cout << "To calculate the total weight of the campers, iterate through the array and add each weight to the total weight variable." << endl;
	  m_hint5++;
	}else if(m_hint5 == 2){
	  cout << "Hint 3" << endl;
	  cout << "Call the conversion function for each weight before adding it to the total. Example: totalLbs += convertToLbs(weight[i]);" << endl; 
	  m_hint5++;
	}else{
	  cout<< "\nYou have used all the hints for this challenge, do you want to see the answer?" << endl;
	  cout << "1) Yes\n2) No" << endl;
	  int choice;
	  answers >> choice;
	  if(choice==1){
		challenges5Answer();
	  }
	  return; 
	}  
	return; 
  }
  
  // Challenge Answers
  void challenges1Answer(){
	cout << "The answer to challenge 1 is: " << endl;
	cout << "cout << \"Hello World!\"" << endl;
  }
  void challenges2Answer(){
	string code = "if (operation == '+') {\n"
	  "    return var1 + var2;\n"
	  "} else if (operation == '-') {\n"
	  "    return var1 - var2;\n"
	  "} else if (operation == '*') {\n"
	  "    return var1 * var2;\n"
	  "} else if (operation == '/') {\n"
	  "    return var1 / var2;\n"
	  "} else {\n"
	  "    return -1;\n"
	  "}";
	cout << "The answer to challenge 2 is: " << endl;
	cout << code << endl;
	
  }
  void challenges3Answer(){
	
	string code1 = "int totalPeople_forLoop(int people[], int numRides) {\n"
	  "    int totalPeople = 0;\n"
	  "    for (int i = 0; i < numRides; i++) {\n"
	  "        totalPeople += people[i];\n"
	  "    }\n"
	  "    return totalPeople;\n"
	  "}";
	string code2 = "int findCamper_whileLoop(int campers[], int numCampers) {\n"
	  "    int index = 0;\n"
	  "    while (index < numCampers) {\n"
	  "        if (campers[index] == \"Jozi\") {\n"
	  "            return index;\n"
	  "        }\n"
	  "        index++;\n"
	  "    }\n"
	  "    return -1;\n"
	  "}";
	
	cout << "The answer to challenge 3 is: " << endl;
	cout << code1 << endl;
	cout << code2 << endl;
  }
  void challenges4Answer(){
	string code = "int calculateThrillLevel(int speed) {\n"
	  "    // Add code here\n"
	  "    if (speed >= 0 && speed <= 25) {\n"
	  "        return 1;\n"
	  "    } else if (speed >= 26 && speed <= 50) {\n"
	  "        return 2;\n"
	  "    } else if (speed >= 51 && speed <= 100) {\n"
	  "        return 3;\n"
	  "    } else if (speed >= 101 && speed <= 120) {\n"
	  "        return 4;\n"
	  "    } else {\n"
	  "        return 5;\n"
	  "    }\n"
	  "}";
	cout << "The answer to challenge 4 is: " << endl;
	cout << code << endl; 
  }
  void challenges5Answer(){
	string code = "double convertToLbs(double weight) {\n"
	  "    weight = weight * 2.20462;\n"
	  "    return weight;\n"
	  "}\n"
	  "\n"
	  "double totalWeight(double partsWeights[], int numParts) {\n"
	  "    double totalLbs = 0;\n"
	  "    for (int i = 0; i < numParts; i++) {\n"
	  "        totalLbs += convertToLbs(partsWeights[i]);\n"
	  "    }\n"
	  "    return totalLbs;\n"
	  "}";
	cout << "The answer to challenge 5 is: " << endl;
	cout << code << endl; 
  }
};

int main() {
    autograder autograder;

	ifstream input("input.txt");
	if(!input.is_open()) {cout << "Not Open" << endl;}
	
	cout << "\nChoose Action:" << endl;
	cout << "1) Check Challenges\n2) Get Hints" << endl;
	int choice;
	input >> choice;
	cout << choice << endl;
	if (choice == 1) {
	  cout << "\nChoose Challenge to Check:" << endl;
	  cout << " 1) Check Challenge 1\n 2) Check Challenge 2\n 3) Check Challenge 3\n 4) Check Challenge 4\n 5) Check Challenge 5\n 6) Back\n" << endl;
	  int challenge;
	  input >> challenge;
	  switch (challenge) {
	  case 1: autograder.checkChallenge1(); break;
	  case 2: autograder.checkChallenge2(); break;
	  case 3: autograder.checkChallenge3(); break;
	  case 4: autograder.checkChallenge4(); break;
	  case 5: autograder.checkChallenge5(); break;
	  case 6: break;
	  default: cout << "Invalid Challenge Number!" << endl;	
	  }
	}
	else if (choice == 2) {
	  cout << "\nChoose Challenge to Get Hints:" << endl;
	  cout << " 1) Challenge 1\n 2) Challenge 2\n 3) Challenge 3\n 4) Challenge 4\n 5) Challenge 5\n 6) Back\n" << endl;
	  int challenge;
	  input >> challenge;
	  switch (challenge) {
	  case 1: autograder.challenge1Hints(); break;
	  case 2: autograder.challenge2Hints(); break;
	  case 3: autograder.challenge3Hints(); break;
	  case 4: autograder.challenge4Hints(); break;
	  case 5: autograder.challenge5Hints(); break;
	  case 6: break;
	  default: cout << "Invalid Challenge Number!\n" << endl;
	  }
	  
	}
	else {
	  cout << "Invalid Choice!\n" << endl;
	}

	input.close();
	
    return 0;
}
