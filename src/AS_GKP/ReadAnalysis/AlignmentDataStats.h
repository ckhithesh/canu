/**************************************************************************
 * This file is part of Celera Assembler, a software program that
 * assembles whole-genome shotgun reads into contigs and scaffolds.
 * Copyright (C) 2005, J. Craig Venter Institute. All rights reserved.
 * Author: Brian Walenz
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received (LICENSE.txt) a copy of the GNU General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *************************************************************************/

#ifndef ALIGNMENTDATASTATS_H
#define ALIGNMENTDATASTATS_H

static const char* rcsid_ALIGNMENTDATASTATS_H = "$Id: AlignmentDataStats.h,v 1.2 2011-09-05 21:23:26 mkotelbajcvi Exp $";

#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

#include "AS_global.h"
#include "ReadAlignment.h"

namespace ReadAnalysis
{
	class AlignmentDataStats
	{
	public:
		AlignmentDataStats();
		
		size_t getNumReads(size_t baseIndex);
		vector<AS_IID>& getReads(size_t baseIndex, vector<AS_IID>& buffer);
		void addRead(ReadAlignment* readAlign);
		
		size_t getNumReads()
		{
			return this->numReads;
		}
		
		size_t getMinReadLength()
		{
			return this->minReadLength;
		}
		
		size_t getMaxReadLength()
		{
			return this->maxReadLength;
		}
		
		double getMeanReadLength()
		{
			return this->meanReadLength;
		}
		
	protected:
		size_t numReads;
		size_t minReadLength;
		size_t maxReadLength;
		double meanReadLength;
		map<size_t, vector<AS_IID>*> readLengthMap;
	};
}

#endif