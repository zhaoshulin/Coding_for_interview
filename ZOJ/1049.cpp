#include <iostream>

#include <string>



using namespace std;



int main()

{

	string s;

	char c;

	int i;



	while(cin >> s >> c){

		for(i = 0; i < s.size(); i ++){

			if(s[i] != c)

				cout << s[i];

		}

		cout << endl;

	}



	return 0;

}