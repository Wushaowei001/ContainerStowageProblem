#include "StackContainer.h"

// ------------------------ Properties -------------------------------
void	StackContainer::SetLocationId(int pLocationId)
{
     _locationId = pLocationId;     
}


int	StackContainer::GetLocationId()
{
    return _locationId;  
}

void	StackContainer::SetStackId(int pStackId)
{
     _stackId = pStackId;
}
     
int	StackContainer::GetStackId()
{
    return _stackId;   
}

void	StackContainer::SetMaxWeigth(double pMaxWeigth)
{
     _maxWeigth = pMaxWeigth;   
}

double	StackContainer::GetMaxWeigth()
{
       return _maxWeigth;       
}

void	StackContainer::SetMaxHeigth(double pMaxHeigth)
{
     _maxHeigth = pMaxHeigth;      
}

double	StackContainer::GetMaxHeigth()
{
       return _maxHeigth;                
}

void StackContainer::StackContainer::SetCellList(list<Cell> pCellList)
{
     _cellList = pCellList;   
}

list<Cell>	 StackContainer::GetCellList()
{
    return _cellList;   
}

// ------------------------ Methods ----------------------------------



StackContainer::StackContainer(){}
StackContainer::~StackContainer(){}
