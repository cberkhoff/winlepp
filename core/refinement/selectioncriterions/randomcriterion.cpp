#include "randomcriterion.h"
#include <stdlib.h>
#include <time.h>

RandomCriterion::RandomCriterion(int aceptedPercent)
{
	_acceptedPercent = aceptedPercent;
	srand ( time(NULL) );
}

RandomCriterion::~RandomCriterion()
{
}

bool RandomCriterion::isSelected(Triangle *t){
	if(_acceptedPercent >= (rand() % 100 + 1))
		return true;
	else
		return false;
}
