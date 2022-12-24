/* Write a program in C++ to use map associative container. The keys will be the names of states
and the values will be the populations of the states. When the program runs, the user is
prompted to type the name of a state. The program then looks in the map, using the state name
as an index and returns the population of the state.

APPROACH:---
1. Creating a empty associative container
2. Insert key as name of state
3. Insert value as population of the state
4. Accept input (name of state) from user and display population of that state.
 */
 
 #include<iostream>
 #include<map>
 #include<string>
 using namespace std;
 int main()
 {
 	typedef map<string, int> mapType;
 	mapType populationMap;     //create a empty map
 	
 	//Insert elements in map (random order)
 	populationMap.insert(pair<string, int>("Maharashtra",123144123));
 	populationMap.insert(pair<string, int>("Rajasthan",801234567));
 	populationMap.insert(pair<string, int>("Hariyana",546789160));
 	populationMap.insert(pair<string, int>("Gujarat",123144123));
 	populationMap.insert(pair<string, int>("Tamilnadu",123123));
 	
 	//iterator/index for map
 	mapType::iterator iter;
 	
 	//display the size of the map
 	cout<<"* * * POPULATION OF STATES IN INDIA * * *"<<endl;
 	cout<<"Size of populationMap : "<<populationMap.size()<<endl;
 	
 	//find will return an iterator to the matching element if it is found or to the end of the map if the key is not found
 	string state_name;
 	cout<<"\nEnter name of the state : ";
 	cin>>state_name;
 	
 	iter = populationMap.find(state_name);
 	if(iter != populationMap.end())
 		cout<<state_name<<"'s population is "<<iter->second;
 	else
 		cout<<"Key is not in populationMap"<<endl;
 		
 	populationMap.clear();
 	return 0;
 }
