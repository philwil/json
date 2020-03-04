#include <iostream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>
// I want to parse "21 pi2  data motors power"
// into jj["pi2"]["data"]["motors"]["power"] = 21
using json = nlohmann::json;

using namespace std;

int myStr( vector<string> &v, string ip)
{

  string word = ""; 
   for (auto x : ip) 
   { 
       if (x == ' ') 
       { 
           cout << word << endl;
	   v.push_back(word);
           word = ""; 
       } 
       else
       { 
           word = word + x; 
       } 
   }
   v.push_back(word);
   cout << word << endl; 
  return 0;
}

int main()
{

  string input = "pi2 data motors power 21";
       
    // create JSON values
    json j_object = {{"one", 1}, {"two", 2}};
    json j_array = {1, 2, 4, 8, 16};
    json j_test = {};
    //j_test["one"] = ;
    j_test["one"]["two"] = 2;
    j_test["one"]["two+"] = 3;
    
    // example for an object
    for (auto& x : j_object.items())
    {
        cout << "key: " << x.key() << ", value: " << x.value() << '\n';
    }

    // example for an array
    for (auto& x : j_array.items())
    {
        cout << "key: " << x.key() << ", value: " << x.value() << '\n';
    }

    cout << " test :" << j_test << '\n' ;
    
    for (auto& x : j_test.items())
    {
        cout << "key: " << x.key() << ", value: " << x.value() << '\n';
    }
    vector<string> v;
    myStr(v, input);
    cout << " v size :" << v.size() << endl;
    cout << " v [3] :" << v[3] << endl;
    v.erase(v.begin()+1);
    cout << " v [3] pop:" << v[3] << endl;

}
