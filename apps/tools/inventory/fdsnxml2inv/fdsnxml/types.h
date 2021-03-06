/***************************************************************************
 * Copyright (C) gempa GmbH                                                *
 * Contact: gempa GmbH (seiscomp-dev@gempa.de)                             *
 *                                                                         *
 * This file may be used under the terms of the GNU Affero                 *
 * Public License version 3.0 as published by the Free Software Foundation *
 * and appearing in the file LICENSE included in the packaging of this     *
 * file. Please review the following information to ensure the GNU Affero  *
 * Public License version 3.0 requirements will be met:                    *
 * https://www.gnu.org/licenses/agpl-3.0.html.                             *
 ***************************************************************************/


#ifndef SEISCOMP_FDSNXML_TYPES_H
#define SEISCOMP_FDSNXML_TYPES_H


#include <seiscomp/core/enumeration.h>


namespace Seiscomp {
namespace FDSNXML {



MAKEENUM(
	RestrictedStatusType,
	EVALUES(
		RST_OPEN,
		RST_CLOSED,
		RST_PARTIAL
	),
	ENAMES(
		"open",
		"closed",
		"partial"
	)
);


MAKEENUM(
	OutputType,
	EVALUES(
		OT_TRIGGERED,
		OT_CONTINUOUS,
		OT_HEALTH,
		OT_GEOPHYSICAL,
		OT_WEATHER,
		OT_FLAG,
		OT_SYNTHESIZED,
		OT_INPUT,
		OT_EXPERIMENTAL,
		OT_MAINTENANCE,
		OT_BEAM
	),
	ENAMES(
		"TRIGGERED",
		"CONTINUOUS",
		"HEALTH",
		"GEOPHYSICAL",
		"WEATHER",
		"FLAG",
		"SYNTHESIZED",
		"INPUT",
		"EXPERIMENTAL",
		"MAINTENANCE",
		"BEAM"
	)
);


MAKEENUM(
	SymmetryType,
	EVALUES(
		ST_NONE,
		ST_EVEN,
		ST_ODD
	),
	ENAMES(
		"NONE",
		"EVEN",
		"ODD"
	)
);


MAKEENUM(
	PzTransferFunctionType,
	EVALUES(
		PZTFT_LAPLACE_RAD,
		PZTFT_LAPLACE_HZ,
		PZTFT_DIGITAL_Z_TRANSFORM
	),
	ENAMES(
		"LAPLACE (RADIANS/SECOND)",
		"LAPLACE (HERTZ)",
		"DIGITAL (Z-TRANSFORM)"
	)
);


MAKEENUM(
	CfTransferFunctionType,
	EVALUES(
		CFTFT_ANALOG_RAD,
		CFTFT_ANALOG_HZ,
		CFTFT_DIGITAL
	),
	ENAMES(
		"ANALOG (RAD/SEC)",
		"ANALOG (HZ)",
		"DIGITAL"
	)
);


MAKEENUM(
	ApproximationType,
	EVALUES(
		AT_MACLAURIN
	),
	ENAMES(
		"MACLAURIN"
	)
);



}
}


#endif
