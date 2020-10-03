#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

class BaseID {

};

class UniqueId : public BaseID {

};

class JobId: public BaseID {

};

class JobId: public UniqueId{

};

int main()
{
  cout << " str " << endl;
}