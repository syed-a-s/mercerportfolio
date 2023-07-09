
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string word = "fiel";
	string wordN = "";

	for (int i = 0;  i < word.length()-1;  i++)
	{
		wordN += word.substr(0, i);
		wordN += word[i+1];
		wordN += word[i];
		wordN += word.substr(i+2);
		cout << wordN << endl;
		wordN = "";  //reset it back to original word

/*
		if (D.find(wordN))
  		{
  			cout << "Suggested Spelling is " << wordN << endl;
 			found = true;
  		} 
*/
	}


	return 0;
}
