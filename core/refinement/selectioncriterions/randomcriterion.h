#ifndef RANDOMCRITERION_H_
#define RANDOMCRITERION_H_

#include "selectioncriterion.h"

class RandomCriterion : public SelectionCriterion
{
	int _acceptedPercent;
public:
	RandomCriterion(int acceptedPercent);
	virtual ~RandomCriterion();
	virtual bool isSelected(Triangle *t);
};

#endif /*RANDOMCRITERION_H_*/
