#include "myString.h"

int main()
{
  String str;
  cout << "Input: ";
  cin>>str;
  cout << "You entered: " << str << endl;
  int length = str.size();
  cout << "Length: " << length << endl;

  for(int i = 0; i < length; i++)
  {
    cout << "str[" << i << "] = " << str[i] << endl;
  }
  cout << endl;

  String a = "test";
  String b = "string";
  cout << a << " : " << b << endl;
  cout << a + b << endl;
  cout << a << " : " << b << endl;

  return 0;
}
