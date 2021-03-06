/**
 * @file	StowageInfo
 * @author  Adolfo Leon Canizales Murcia (leon99adolfo@gmail.com)
 * @version 1.0
 * @section DESCRIPTION
 * StowageInfo class.
 */
#ifndef StowageInfo_h
#define StowageInfo_h

#include "StackContainer.h"
#include "EqualContainer.h"
#include "EqualStack.h"
#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

class StowageInfo
{
      private:
              // ------------------------ Properties ------------------------------- 
              int                    _numPortsDischarge;
              int                    _numContainerLoad;
              int                    _numVirtualCont;
              int                    _numContainerLoaded;
              int                    _numStacks;
              int                    _numCell;
              int                    _numLocations;
              int                    _numTiers;
              vector<int>            _listPortsDischarges;
              vector<int>            _listLocations;
              map<int, ContainerBox> _listContainerLoad;
              map<int, ContainerBox> _listContainerLoaded;
              map<int, StackContainer> _listStacks;
              vector<Cell>           _listCells;

              /**
               * Charge container in memory
               */
              void ChargeContainer(map<int, ContainerBox> pListContainer, bool pValFirst);
                            
      public:
             /* Calculated variables */
            int			_nuMinPOD;	   // maximum POD
            int			_nuMaxPOD;	   // maximum POD
            int         _nuMaxLength;  // maximum length
            double      _nuMaxHeight;  // maximum height
            double      _nuMaxWeight;  // maximum weight
            double      _nuMaxStackHeight; // Maximum height of the stack
            bool		LevelDistribute;
            bool		ActiveRC;
			/* Model variables */
			vector<int>			Stacks;			// Stack index set
			vector<int>			Slots;			// Slot index set
            vector<int>			Cont;        	// Container index set
            vector<int>			Slots_A;     	// Aft slots index set
            vector<int>			Slots_F;     	// Fore slots index set
            map<int, vector<int> >Slots_K;     	// Slots of stack K index set
            map<int, vector<int> >Slots_K_A;   	// Aft slots of stack K index set
			map<int, vector<int> >Slots_K_F;	// Fore slots of stack K index set
			map<int, int>      	Slots_R;     	// Reefer slot index set
			vector<int>    		Slots_NR;    	// Non Reefer slot index set
			vector<int>    		Slots_NRC;   	// Slots in cell with no reefer plugs index set
            vector<int>        	Slots_20;    	// 20' capacity slots index set
            vector<int>      	Slots_40;    	// 40' capacity slots index set
			vector<int>        	Cont_V;      	// Virtual containers index set
            vector<int>        	Cont_L;      	// Loaded containers index set
            vector<int>         Cont_20;        // 20' containers index set
            vector<int>         Cont_40;        // 40' containers index set
            map<int, int>       Cont_40_A;      // 40' containers index set (Aft)
            map<int, int>       Cont_40_F;      // 40' containers index set (Fore)            
            vector<int>         Cont_20_R;      // 20' reefer containers index set
            vector<int>         Cont_40_R;      // 40' reefer containers index set
            map<int, int>       Cont_NR;        // Non-reefer containers index set
            map<int, vector<int> >CellNull;     	// null Cell
			map<int, double>    Weight;      	// Weight of container i
            map<int, int> 		POD;         	// Ports of discharges of container i
            map<int, int>      	Length;      	// Leight of container i
            map<int, double>    Height;      	// Height of container i
            map<int, int>       Cont_EL;        // Number of container with Length L.
            map<int, int>       Cont_EP;        // Number of container with discharge port P.
            map<int, int>		ContLoadedSlot;
			map<int, map<int, int> >	ContLoadedByStackCell; // Containers loaded by stack and cell.
			map<int, int>		ContLoadedMaxCell; // Maximum cell by stack
            map<double, int>    Cont_EW;        // Number of container with equal weight 
            map<double, int>    Cont_EH;        // Number of container with equal height
            int                 ContNormal;     // Number of normal containers
            int                 ContCUBE;       // Number of high-cube containers
            map<int, Cell>		CellBySlot;		// cell by slot
            int					WeightTotal;	// sum of weight container
            vector<EqualContainer>	SameContainer; // Set equal container
            vector<EqualStack>	SameStackTmp;		// Set equal stack
            vector<EqualStack>	SameStack;		// Set equal stack
            map<int, vector<Cell> > ListCellByStack; // cells by stack
            map<int, int> 		SlotRByStack; // Slots reffer by slots
            vector<int>			SortSlotRByStack;  // sort SlotRByStack
			map<int, int> 		varianceH; // Variance H
			map<int, int> 		varianceW; // Variance W
			map<int, int> 		varianceL; // Variance L
			map<int, int> 		varianceP; // Variance P
			vector<int>	 		variance; // Variance P
			
             // ------------------------ Properties -------------------------------
    		 /**
    		 *	NumPortsDischarge Property SET
    		 *	@param pNumPortsDischarge
    		 */
             void    SetNumPortsDischarge(int pNumPortsDischarge);
             /**
    		 *	LocationId Property GET
    		 */
             int     GetNumPortsDischarge();
             
             /**
    		 *	NumContainerLoad Property SET
    		 *	@param pNumContainerLoad
    		 */
             void    SetNumContainerLoad(int pNumContainerLoad);
             /**
    		 *	NumContainerLoad Property GET
    		 */
             int     GetNumContainerLoad();
             
             /**
    		 *	NumContainerLoaded Property SET
    		 *	@param pNumContainerLoaded
    		 */
             void    SetNumContainerLoaded(int pNumContainerLoaded);
             /**
    		 *	LocationId Property GET
    		 */
             int     GetNumContainerLoaded();
             
             /**
    		 *	SetNumVirtualCont Property SET
    		 *	@param pNumVirtualCont
    		 */
             void    SetNumVirtualCont(int pNumVirtualCont);
             /**
    		 *	GetNumVirtualCont Property GET
    		 */
             int     GetNumVirtualCont();
             
             
             /**
    		 *	NumStacks Property SET
    		 *	@param pNumStacks
    		 */
             void    SetNumStacks(int pNumStacks);
             /**
    		 *	NumStacks Property GET
    		 */
             int     GetNumStacks();
             
             /**
    		 *	NumCell Property SET
    		 *	@param pNumCell
    		 */
             void    SetNumCell(int pNumCell);
             /**
    		 *	NumCell Property GET
    		 */
             int     GetNumCell();
             
             /**
    		 *	NumLocations Property SET
    		 *	@param pNumLocations
    		 */
             void    SetNumLocations(int pNumLocations);
             /**
    		 *	NumLocations Property GET
    		 */
             int     GetNumLocations();
             
             /**
    		 *	NumTiers Property SET
    		 *	@param pNumTiers
    		 */
             void    SetNumTiers(int pNumTiers);
             /**
    		 *	NumTiers Property GET
    		 */
             int     GetNumTiers();
             
             /**
    		 *	ListPortsDischarges Property SET
    		 *	@param pListPortsDischarges
    		 */
             void    SetListPortsDischarges(vector<int> pListPortsDischarges);
             /**
    		 *	ListPortsDischarges Property GET
    		 */
             vector<int> GetListPortsDischarges();
             
             
             /**
    		 *	ListLocations Property SET
    		 *	@param pListLocations
    		 */
             void    SetListLocations(vector<int> pListLocations);
             /**
    		 *	ListLocations Property GET
    		 */
             vector<int> GetListLocations();
             
             
             /**
    		 *	ListContainerLoad Property SET
    		 *	@param pListContainerLoad
    		 */
             void    SetListContainerLoad(map<int, ContainerBox> pListContainerLoad);
             /**
    		 *	ListContainerLoad Property GET
    		 */
             map<int, ContainerBox> GetListContainerLoad();
             
             
             /**
    		 *	ListContainerLoaded Property SET
    		 *	@param pListContainerLoaded
    		 */
             void    SetListContainerLoaded(map<int, ContainerBox> pListContainerLoaded);
             /**
    		 *	ListContainerLoaded Property GET
    		 */
             map<int, ContainerBox> GetListContainerLoaded();
             
             /**
    		 *	ListStacks Property SET
    		 *	@param pListStacks
    		 */
             void    SetListStacks(map<int, StackContainer> pListStacks);
             /**
    		 *	ListStacks Property GET
    		 */
             map<int, StackContainer> GetListStacks();
             
             
             /**
    		 *	ListCells Property SET
    		 *	@param pListCells
    		 */
             void    SetListCells(vector<Cell> pListCells);
             /**
    		 *	ListCells Property GET
    		 */
             vector<Cell> GetListCells();           
       
			 bool IsValidLoadedCont();
       
             // ------------------------ Methods ----------------------------------
    		/**
    		 *	Constructor
    		 */
    		StowageInfo();
    		/**
    		 *	Destructor
    		 */
    		//~StowageInfo();
    		/**
    		 * Charge Data
    		 */
    		void ChargeData();
                          
};

#endif
