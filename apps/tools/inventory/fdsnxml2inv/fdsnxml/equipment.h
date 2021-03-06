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


#ifndef SEISCOMP_FDSNXML_EQUIPMENT_H
#define SEISCOMP_FDSNXML_EQUIPMENT_H


#include <fdsnxml/metadata.h>
#include <vector>
#include <string>
#include <fdsnxml/date.h>
#include <seiscomp/core/baseobject.h>
#include <seiscomp/core/exceptions.h>


namespace Seiscomp {
namespace FDSNXML {

DEFINE_SMARTPOINTER(DateType);
DEFINE_SMARTPOINTER(Identifier);



DEFINE_SMARTPOINTER(Equipment);


/**
 * \brief Equipment currently used by all channels in a station.
 */
class Equipment : public Core::BaseObject {
	DECLARE_CASTS(Equipment);
	DECLARE_RTTI;
	DECLARE_METAOBJECT_DERIVED;

	// ------------------------------------------------------------------
	//  Xstruction
	// ------------------------------------------------------------------
	public:
		//! Constructor
		Equipment();

		//! Copy constructor
		Equipment(const Equipment &other);

		//! Destructor
		~Equipment();


	// ------------------------------------------------------------------
	//  Operators
	// ------------------------------------------------------------------
	public:
		//! Copies the metadata of other to this
		Equipment& operator=(const Equipment &other);
		bool operator==(const Equipment &other) const;


	// ------------------------------------------------------------------
	//  Setters/Getters
	// ------------------------------------------------------------------
	public:
		//! XML tag: Type
		void setType(const std::string& type);
		const std::string& type() const;

		//! XML tag: Description
		void setDescription(const std::string& description);
		const std::string& description() const;

		//! XML tag: Manufacturer
		void setManufacturer(const std::string& manufacturer);
		const std::string& manufacturer() const;

		//! XML tag: Vendor
		void setVendor(const std::string& vendor);
		const std::string& vendor() const;

		//! XML tag: Model
		void setModel(const std::string& model);
		const std::string& model() const;

		//! XML tag: SerialNumber
		void setSerialNumber(const std::string& serialNumber);
		const std::string& serialNumber() const;

		//! XML tag: InstallationDate
		void setInstallationDate(const OPT(DateTime)& installationDate);
		DateTime installationDate() const;

		//! XML tag: RemovalDate
		void setRemovalDate(const OPT(DateTime)& removalDate);
		DateTime removalDate() const;

		//! This field contains a string that should serve as a unique resource
		//! identifier. This identifier can be interpreted differently depending
		//! on the datacenter/software that generated the document. Also, we
		//! recommend to use something like GENERATOR:Meaningful ID. As a common
		//! behaviour equipment with the same ID should contains the same
		//! information/be derived from the same base instruments.
		//! XML tag: resourceId
		void setResourceId(const std::string& resourceId);
		const std::string& resourceId() const;

	
	// ------------------------------------------------------------------
	//  Public interface
	// ------------------------------------------------------------------
	public:
		/**
		 * Add an object.
		 * @param obj The object pointer
		 * @return true The object has been added
		 * @return false The object has not been added
		 *               because it already exists in the list
		 *               or it already has another parent
		 */
		bool addCalibrationDate(DateType *obj);
		bool addIdentifier(Identifier *obj);

		/**
		 * Removes an object.
		 * @param obj The object pointer
		 * @return true The object has been removed
		 * @return false The object has not been removed
		 *               because it does not exist in the list
		 */
		bool removeCalibrationDate(DateType *obj);
		bool removeIdentifier(Identifier *obj);

		/**
		 * Removes an object of a particular class.
		 * @param i The object index
		 * @return true The object has been removed
		 * @return false The index is out of bounds
		 */
		bool removeCalibrationDate(size_t i);
		bool removeIdentifier(size_t i);

		//! Retrieve the number of objects of a particular class
		size_t calibrationDateCount() const;
		size_t identifierCount() const;

		//! Index access
		//! @return The object at index i
		DateType* calibrationDate(size_t i) const;
		Identifier* identifier(size_t i) const;


	// ------------------------------------------------------------------
	//  Implementation
	// ------------------------------------------------------------------
	private:
		// Attributes
		std::string _type;
		std::string _description;
		std::string _manufacturer;
		std::string _vendor;
		std::string _model;
		std::string _serialNumber;
		OPT(DateTime) _installationDate;
		OPT(DateTime) _removalDate;
		std::string _resourceId;

		// Aggregations
		std::vector<DateTypePtr> _calibrationDates;
		std::vector<IdentifierPtr> _identifiers;
};


}
}


#endif
