//#include <string>
//#include <iostream>
//using namespace std;
//
//string search(string& values, string param) {
//	string a;
//	for (int i = values.find(param) + param.size() + 1;i <= values.size();i++) {
//		if (values[i] == ',') break;
//		a += values[i];
//	}
//	return a;
//}
//
//int main()
//{
//	a:string values;
//	getline(std::cin, values);
//	string temp;
//	getline(std::cin, temp);
//	int start, end, t;
//	string arg,insrt;
//
//
//r:for (int index = 0; index <= temp.size();index++)
//{
//	if (temp[index] == '[')
//	{
//		arg.clear();
//		start = index;
//		for (int i = index + 1; i <= temp.size();i++)
//		{
//
//			index = i;
//			end = i;
//			if (temp[index] == ']') break;
//			arg += temp[i];
//		}
//
//		if ((values.find(arg) != string::npos)) {
//			temp.erase(start, end - start + 1);
//			temp.insert(start, search(values, arg));
//			goto r;
//		}
//
//	}
//}
//cout << temp << "\n";goto a;
//}


//task 2
#include <string>
#include <iostream>
using namespace std;
struct ParamForPassword {
	bool size		= 0;
	bool upper		= 0;
	bool lower		= 0;
	bool symbols	= 0;
	bool digit		= 0;
};
int main()
{
	r:string password;
	getline(std::cin, password);

	string symbols= "#$%&'()*+,-./:;<=>?@[\]^_`{|}";
	string numbers = "123456789";
	string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string lower = "abcdefghijklmnopqrstuvwxyz";

	ParamForPassword check;
	if (password.size() >= 8) check.size = 1;
	for (int i = 0;i <= password.size();i++)
	{
		if (!check.upper)	if (upper.find(password[i])		!= string::npos) check.upper	= 1;
		if (!check.lower)	if (lower.find(password[i])		!= string::npos) check.lower	= 1;
		if (!check.symbols) if (symbols.find(password[i])	!= string::npos) check.symbols	= 1;
		if (!check.digit)	if (numbers.find(password[i])	!= string::npos) check.digit	= 1;
	}
	
	if (!check.size)	cout << "The password must be 8 characters long" << endl;
	if (!check.upper)	cout << "The password must have at least one upper case letter" << endl;
	if (!check.lower)	cout << "The password must have at least one lower case letter" << endl;
	if (!check.symbols) cout << "The password must have at least one special character" << endl;
	if (!check.digit)	cout << "The password must have at least one digit" << endl;
	else cout <<"The password is valid" << endl;
	goto r;
	return 0;
}
