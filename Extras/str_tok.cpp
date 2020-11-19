// A C/C++ program for splitting a string 
// using strtok() 
#include <stdio.h> 
#include <string.h> 
#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
	// char str[] = "Geeks-for-Geeks"; 

	// // Returns first token 
	// char* token = strtok(str, "-"); 
    // // cout<<*token<<endl;
    // printf("%s",token);
	// // Keep printing tokens while one of the 
	// // delimiters present in str[]. 
	// while (token != NULL) { 
	// 	printf("%s\n", token); 
	// 	token = strtok(NULL, "-"); 
	// } 

    // CPP program to illustrate *char 

	char* str1 = "This is GeeksForGeeks"; 

	cout << *str1 << endl; 

	int size = 30; 

	//an allocate size dynamically. 
	char* str2 = (char*)malloc(sizeof(char) * size); 

	str2 = "GeeksForGeeks For Everyone"; 

	cout << str2	; 



	return 0; 
} 
