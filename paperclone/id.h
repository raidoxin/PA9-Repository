
#include "document.h"
class id
{
private:
  string IDno;
	string DoB;
	bool sex;
	string firstN;
  string lastN;
  bool valid;
  //unique to id
  string date;
  string city;
  //corruptors
  void corruptIdno(int odds);
	void corruptDob(int odds);
	void corruptsex(int odds);
	void corruptfirstN(int odds);
  void corruptlastN(int odds);
public:
	void setID(string & newID);
	void setBirth(string & newDoB);
	void setSex(bool newsex);
	void setFirst(string & newFirst);
  void setLast(string & newLast);
  void setcity(string & newcity);
  void setdate(string & newdate);
  
  
	string & getID();
	string & getDoB();
	bool & getSex();
	string & getFirstN();
  string & getLastN();
  string & getdate();
  string & getcity();
  
  void master_corruptor(int odds);
  void print_all();





}
