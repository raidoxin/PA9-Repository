void id::setID(string & newID)
{
	IDno = newID;
}

void id::setBirth(string & newDoB)
{
	DoB = newDoB;
}

void id::setSex(bool newsex)
{
	sex = newsex;
}

void id::setFirst(string & newFirst)
{
	firstN = newFirst;
}

void id::setLast(string & newLast)
{
	lastN = newLast;
}
void id::setdate(string & newDate)
{
  date= newDate;
}
void id::setcountry(string & newCountry)
{
  country = newCountry;
}
/// getters
string & id::getID()
{
	return IDno;
}

string & id::getDoB()
{
	return DoB;
}

bool & id::getSex()
{
	return sex;
}

string & id::getFirstN()
{
	return firstN;
}

string & id::getLastN()
{
	return lastN;
}
string & id::getCity()
{
  return city;
}
string & id::getdate()
{
  return date;
}
