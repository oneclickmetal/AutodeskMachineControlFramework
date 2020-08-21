/*++

Copyright (C) 2020 Autodesk Inc.

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Autodesk Inc. nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 'AS IS' AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL AUTODESK INC. BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


This file has been generated by the Automatic Component Toolkit (ACT) version 1.7.0-develop.

Abstract: This is an autogenerated C++-Header file in order to allow an easy
 use of MC Driver ScanLab Open Interface Extension

Interface version: 1.0.0

*/

#ifndef __LIBMCDRIVER_SCANLABOIE_CPPHEADER_DYNAMIC_CPP
#define __LIBMCDRIVER_SCANLABOIE_CPPHEADER_DYNAMIC_CPP

#include "libmcdriver_scanlaboie_types.hpp"
#include "libmcdriver_scanlaboie_dynamic.h"

#include "libmcdriverenv_dynamic.hpp"

#ifdef _WIN32
#include <windows.h>
#else // _WIN32
#include <dlfcn.h>
#endif // _WIN32
#include <string>
#include <memory>
#include <vector>
#include <exception>

namespace LibMCDriver_ScanLabOIE {

/*************************************************************************************************************************
 Forward Declaration of all classes
**************************************************************************************************************************/
class CWrapper;
class CBase;
class CDriver;
class CDriver_ScanLab_OIE;

/*************************************************************************************************************************
 Declaration of deprecated class types
**************************************************************************************************************************/
typedef CWrapper CLibMCDriver_ScanLabOIEWrapper;
typedef CBase CLibMCDriver_ScanLabOIEBase;
typedef CDriver CLibMCDriver_ScanLabOIEDriver;
typedef CDriver_ScanLab_OIE CLibMCDriver_ScanLabOIEDriver_ScanLab_OIE;

/*************************************************************************************************************************
 Declaration of shared pointer types
**************************************************************************************************************************/
typedef std::shared_ptr<CWrapper> PWrapper;
typedef std::shared_ptr<CBase> PBase;
typedef std::shared_ptr<CDriver> PDriver;
typedef std::shared_ptr<CDriver_ScanLab_OIE> PDriver_ScanLab_OIE;

/*************************************************************************************************************************
 Declaration of deprecated shared pointer types
**************************************************************************************************************************/
typedef PWrapper PLibMCDriver_ScanLabOIEWrapper;
typedef PBase PLibMCDriver_ScanLabOIEBase;
typedef PDriver PLibMCDriver_ScanLabOIEDriver;
typedef PDriver_ScanLab_OIE PLibMCDriver_ScanLabOIEDriver_ScanLab_OIE;


/*************************************************************************************************************************
 classParam Definition
**************************************************************************************************************************/

template<class T> class classParam {
private:
	const T* m_ptr;

public:
	classParam(const T* ptr)
		: m_ptr (ptr)
	{
	}

	classParam(std::shared_ptr <T> sharedPtr)
		: m_ptr (sharedPtr.get())
	{
	}

	LibMCDriver_ScanLabOIEHandle GetHandle()
	{
		if (m_ptr != nullptr)
			return m_ptr->handle();
		return nullptr;
	}
};

/*************************************************************************************************************************
 Class ELibMCDriver_ScanLabOIEException 
**************************************************************************************************************************/
class ELibMCDriver_ScanLabOIEException : public std::exception {
protected:
	/**
	* Error code for the Exception.
	*/
	LibMCDriver_ScanLabOIEResult m_errorCode;
	/**
	* Error message for the Exception.
	*/
	std::string m_errorMessage;

public:
	/**
	* Exception Constructor.
	*/
	ELibMCDriver_ScanLabOIEException(LibMCDriver_ScanLabOIEResult errorCode, const std::string & sErrorMessage)
		: m_errorMessage("LibMCDriver_ScanLabOIE Error " + std::to_string(errorCode) + " (" + sErrorMessage + ")")
	{
		m_errorCode = errorCode;
	}

	/**
	* Returns error code
	*/
	LibMCDriver_ScanLabOIEResult getErrorCode() const noexcept
	{
		return m_errorCode;
	}

	/**
	* Returns error message
	*/
	const char* what() const noexcept
	{
		return m_errorMessage.c_str();
	}

};

/*************************************************************************************************************************
 Class CInputVector
**************************************************************************************************************************/
template <typename T>
class CInputVector {
private:
	
	const T* m_data;
	size_t m_size;
	
public:
	
	CInputVector( const std::vector<T>& vec)
		: m_data( vec.data() ), m_size( vec.size() )
	{
	}
	
	CInputVector( const T* in_data, size_t in_size)
		: m_data( in_data ), m_size(in_size )
	{
	}
	
	const T* data() const
	{
		return m_data;
	}
	
	size_t size() const
	{
		return m_size;
	}
	
};

// declare deprecated class name
template<typename T>
using CLibMCDriver_ScanLabOIEInputVector = CInputVector<T>;

/*************************************************************************************************************************
 Class CWrapper 
**************************************************************************************************************************/
class CWrapper {
public:
	
	CWrapper(void* pSymbolLookupMethod)
	{
		CheckError(nullptr, initWrapperTable(&m_WrapperTable));
		CheckError(nullptr, loadWrapperTableFromSymbolLookupMethod(&m_WrapperTable, pSymbolLookupMethod));
		
		CheckError(nullptr, checkBinaryVersion());
	}
	
	CWrapper(const std::string &sFileName)
	{
		CheckError(nullptr, initWrapperTable(&m_WrapperTable));
		CheckError(nullptr, loadWrapperTable(&m_WrapperTable, sFileName.c_str()));
		
		CheckError(nullptr, checkBinaryVersion());
	}
	
	static PWrapper loadLibrary(const std::string &sFileName)
	{
		return std::make_shared<CWrapper>(sFileName);
	}
	
	static PWrapper loadLibraryFromSymbolLookupMethod(void* pSymbolLookupMethod)
	{
		return std::make_shared<CWrapper>(pSymbolLookupMethod);
	}
	
	~CWrapper()
	{
		releaseWrapperTable(&m_WrapperTable);
	}
	
	inline void CheckError(CBase * pBaseClass, LibMCDriver_ScanLabOIEResult nResult);

	inline void GetVersion(LibMCDriver_ScanLabOIE_uint32 & nMajor, LibMCDriver_ScanLabOIE_uint32 & nMinor, LibMCDriver_ScanLabOIE_uint32 & nMicro);
	inline bool GetLastError(classParam<CBase> pInstance, std::string & sErrorMessage);
	inline void ReleaseInstance(classParam<CBase> pInstance);
	inline void AcquireInstance(classParam<CBase> pInstance);
	inline void InjectComponent(const std::string & sNameSpace, const LibMCDriver_ScanLabOIE_pvoid pSymbolAddressMethod);
	inline LibMCDriver_ScanLabOIE_pvoid GetSymbolLookupMethod();
	inline PDriver CreateDriver(const std::string & sName, const std::string & sType, classParam<LibMCDriverEnv::CDriverEnvironment> pDriverEnvironment);

private:
	sLibMCDriver_ScanLabOIEDynamicWrapperTable m_WrapperTable;
	// Injected Components
	LibMCDriverEnv::PWrapper m_pLibMCDriverEnvWrapper;

	
	LibMCDriver_ScanLabOIEResult checkBinaryVersion()
	{
		LibMCDriver_ScanLabOIE_uint32 nMajor, nMinor, nMicro;
		GetVersion(nMajor, nMinor, nMicro);
		if ( (nMajor != LIBMCDRIVER_SCANLABOIE_VERSION_MAJOR) || (nMinor < LIBMCDRIVER_SCANLABOIE_VERSION_MINOR) ) {
			return LIBMCDRIVER_SCANLABOIE_ERROR_INCOMPATIBLEBINARYVERSION;
		}
		return LIBMCDRIVER_SCANLABOIE_SUCCESS;
	}
	LibMCDriver_ScanLabOIEResult initWrapperTable(sLibMCDriver_ScanLabOIEDynamicWrapperTable * pWrapperTable);
	LibMCDriver_ScanLabOIEResult releaseWrapperTable(sLibMCDriver_ScanLabOIEDynamicWrapperTable * pWrapperTable);
	LibMCDriver_ScanLabOIEResult loadWrapperTable(sLibMCDriver_ScanLabOIEDynamicWrapperTable * pWrapperTable, const char * pLibraryFileName);
	LibMCDriver_ScanLabOIEResult loadWrapperTableFromSymbolLookupMethod(sLibMCDriver_ScanLabOIEDynamicWrapperTable * pWrapperTable, void* pSymbolLookupMethod);

	friend class CBase;
	friend class CDriver;
	friend class CDriver_ScanLab_OIE;

};

	
/*************************************************************************************************************************
 Class CBase 
**************************************************************************************************************************/
class CBase {
public:
	
protected:
	/* Wrapper Object that created the class. */
	CWrapper * m_pWrapper;
	/* Handle to Instance in library*/
	LibMCDriver_ScanLabOIEHandle m_pHandle;

	/* Checks for an Error code and raises Exceptions */
	void CheckError(LibMCDriver_ScanLabOIEResult nResult)
	{
		if (m_pWrapper != nullptr)
			m_pWrapper->CheckError(this, nResult);
	}
public:
	/**
	* CBase::CBase - Constructor for Base class.
	*/
	CBase(CWrapper * pWrapper, LibMCDriver_ScanLabOIEHandle pHandle)
		: m_pWrapper(pWrapper), m_pHandle(pHandle)
	{
	}

	/**
	* CBase::~CBase - Destructor for Base class.
	*/
	virtual ~CBase()
	{
		if (m_pWrapper != nullptr)
			m_pWrapper->ReleaseInstance(this);
		m_pWrapper = nullptr;
	}

	/**
	* CBase::handle - Returns handle to instance.
	*/
	LibMCDriver_ScanLabOIEHandle handle() const
	{
		return m_pHandle;
	}

	/**
	* CBase::wrapper - Returns wrapper instance.
	*/
	CWrapper * wrapper() const
	{
		return m_pWrapper;
	}
	
	friend class CWrapper;
};
	
/*************************************************************************************************************************
 Class CDriver 
**************************************************************************************************************************/
class CDriver : public CBase {
public:
	
	/**
	* CDriver::CDriver - Constructor for Driver class.
	*/
	CDriver(CWrapper* pWrapper, LibMCDriver_ScanLabOIEHandle pHandle)
		: CBase(pWrapper, pHandle)
	{
	}
	
	inline std::string GetName();
	inline std::string GetType();
	inline void GetVersion(LibMCDriver_ScanLabOIE_uint32 & nMajor, LibMCDriver_ScanLabOIE_uint32 & nMinor, LibMCDriver_ScanLabOIE_uint32 & nMicro, std::string & sBuild);
	inline void GetHeaderInformation(std::string & sNameSpace, std::string & sBaseName);
};
	
/*************************************************************************************************************************
 Class CDriver_ScanLab_OIE 
**************************************************************************************************************************/
class CDriver_ScanLab_OIE : public CDriver {
public:
	
	/**
	* CDriver_ScanLab_OIE::CDriver_ScanLab_OIE - Constructor for Driver_ScanLab_OIE class.
	*/
	CDriver_ScanLab_OIE(CWrapper* pWrapper, LibMCDriver_ScanLabOIEHandle pHandle)
		: CDriver(pWrapper, pHandle)
	{
	}
	
};
	
	/**
	* CWrapper::GetVersion - retrieves the binary version of this library.
	* @param[out] nMajor - returns the major version of this library
	* @param[out] nMinor - returns the minor version of this library
	* @param[out] nMicro - returns the micro version of this library
	*/
	inline void CWrapper::GetVersion(LibMCDriver_ScanLabOIE_uint32 & nMajor, LibMCDriver_ScanLabOIE_uint32 & nMinor, LibMCDriver_ScanLabOIE_uint32 & nMicro)
	{
		CheckError(nullptr,m_WrapperTable.m_GetVersion(&nMajor, &nMinor, &nMicro));
	}
	
	/**
	* CWrapper::GetLastError - Returns the last error recorded on this object
	* @param[in] pInstance - Instance Handle
	* @param[out] sErrorMessage - Message of the last error
	* @return Is there a last error to query
	*/
	inline bool CWrapper::GetLastError(classParam<CBase> pInstance, std::string & sErrorMessage)
	{
		LibMCDriver_ScanLabOIEHandle hInstance = pInstance.GetHandle();
		LibMCDriver_ScanLabOIE_uint32 bytesNeededErrorMessage = 0;
		LibMCDriver_ScanLabOIE_uint32 bytesWrittenErrorMessage = 0;
		bool resultHasError = 0;
		CheckError(nullptr,m_WrapperTable.m_GetLastError(hInstance, 0, &bytesNeededErrorMessage, nullptr, &resultHasError));
		std::vector<char> bufferErrorMessage(bytesNeededErrorMessage);
		CheckError(nullptr,m_WrapperTable.m_GetLastError(hInstance, bytesNeededErrorMessage, &bytesWrittenErrorMessage, &bufferErrorMessage[0], &resultHasError));
		sErrorMessage = std::string(&bufferErrorMessage[0]);
		
		return resultHasError;
	}
	
	/**
	* CWrapper::ReleaseInstance - Releases shared ownership of an Instance
	* @param[in] pInstance - Instance Handle
	*/
	inline void CWrapper::ReleaseInstance(classParam<CBase> pInstance)
	{
		LibMCDriver_ScanLabOIEHandle hInstance = pInstance.GetHandle();
		CheckError(nullptr,m_WrapperTable.m_ReleaseInstance(hInstance));
	}
	
	/**
	* CWrapper::AcquireInstance - Acquires shared ownership of an Instance
	* @param[in] pInstance - Instance Handle
	*/
	inline void CWrapper::AcquireInstance(classParam<CBase> pInstance)
	{
		LibMCDriver_ScanLabOIEHandle hInstance = pInstance.GetHandle();
		CheckError(nullptr,m_WrapperTable.m_AcquireInstance(hInstance));
	}
	
	/**
	* CWrapper::InjectComponent - Injects an imported component for usage within this component
	* @param[in] sNameSpace - NameSpace of the injected component
	* @param[in] pSymbolAddressMethod - Address of the SymbolAddressMethod of the injected component
	*/
	inline void CWrapper::InjectComponent(const std::string & sNameSpace, const LibMCDriver_ScanLabOIE_pvoid pSymbolAddressMethod)
	{
		CheckError(nullptr,m_WrapperTable.m_InjectComponent(sNameSpace.c_str(), pSymbolAddressMethod));
		
		bool bNameSpaceFound = false;
		if (sNameSpace == "LibMCDriverEnv") {
			if (m_pLibMCDriverEnvWrapper != nullptr) {
				throw ELibMCDriver_ScanLabOIEException(LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTLOADLIBRARY, "Library with namespace " + sNameSpace + " is already registered.");
			}
			m_pLibMCDriverEnvWrapper = LibMCDriverEnv::CWrapper::loadLibraryFromSymbolLookupMethod(pSymbolAddressMethod);
			bNameSpaceFound = true;
		}
		if (!bNameSpaceFound)
			throw ELibMCDriver_ScanLabOIEException(LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTLOADLIBRARY, "Unknown namespace " + sNameSpace);
	}
	
	/**
	* CWrapper::GetSymbolLookupMethod - Returns the address of the SymbolLookupMethod
	* @return Address of the SymbolAddressMethod
	*/
	inline LibMCDriver_ScanLabOIE_pvoid CWrapper::GetSymbolLookupMethod()
	{
		LibMCDriver_ScanLabOIE_pvoid resultSymbolLookupMethod = 0;
		CheckError(nullptr,m_WrapperTable.m_GetSymbolLookupMethod(&resultSymbolLookupMethod));
		
		return resultSymbolLookupMethod;
	}
	
	/**
	* CWrapper::CreateDriver - Creates a driver instance with a specific name.
	* @param[in] sName - Name of driver to be created.
	* @param[in] sType - Type of driver to be created.
	* @param[in] pDriverEnvironment - Environment of this driver.
	* @return New Driver instance
	*/
	inline PDriver CWrapper::CreateDriver(const std::string & sName, const std::string & sType, classParam<LibMCDriverEnv::CDriverEnvironment> pDriverEnvironment)
	{
		LibMCDriverEnvHandle hDriverEnvironment = pDriverEnvironment.GetHandle();
		LibMCDriver_ScanLabOIEHandle hInstance = nullptr;
		CheckError(nullptr,m_WrapperTable.m_CreateDriver(sName.c_str(), sType.c_str(), hDriverEnvironment, &hInstance));
		
		if (!hInstance) {
			CheckError(nullptr,LIBMCDRIVER_SCANLABOIE_ERROR_INVALIDPARAM);
		}
		return std::make_shared<CDriver>(this, hInstance);
	}
	
	inline void CWrapper::CheckError(CBase * pBaseClass, LibMCDriver_ScanLabOIEResult nResult)
	{
		if (nResult != 0) {
			std::string sErrorMessage;
			if (pBaseClass != nullptr) {
				GetLastError(pBaseClass, sErrorMessage);
			}
			throw ELibMCDriver_ScanLabOIEException(nResult, sErrorMessage);
		}
	}
	

	inline LibMCDriver_ScanLabOIEResult CWrapper::initWrapperTable(sLibMCDriver_ScanLabOIEDynamicWrapperTable * pWrapperTable)
	{
		if (pWrapperTable == nullptr)
			return LIBMCDRIVER_SCANLABOIE_ERROR_INVALIDPARAM;
		
		pWrapperTable->m_LibraryHandle = nullptr;
		pWrapperTable->m_Driver_GetName = nullptr;
		pWrapperTable->m_Driver_GetType = nullptr;
		pWrapperTable->m_Driver_GetVersion = nullptr;
		pWrapperTable->m_Driver_GetHeaderInformation = nullptr;
		pWrapperTable->m_GetVersion = nullptr;
		pWrapperTable->m_GetLastError = nullptr;
		pWrapperTable->m_ReleaseInstance = nullptr;
		pWrapperTable->m_AcquireInstance = nullptr;
		pWrapperTable->m_InjectComponent = nullptr;
		pWrapperTable->m_GetSymbolLookupMethod = nullptr;
		pWrapperTable->m_CreateDriver = nullptr;
		
		return LIBMCDRIVER_SCANLABOIE_SUCCESS;
	}

	inline LibMCDriver_ScanLabOIEResult CWrapper::releaseWrapperTable(sLibMCDriver_ScanLabOIEDynamicWrapperTable * pWrapperTable)
	{
		if (pWrapperTable == nullptr)
			return LIBMCDRIVER_SCANLABOIE_ERROR_INVALIDPARAM;
		
		if (pWrapperTable->m_LibraryHandle != nullptr) {
		#ifdef _WIN32
			HMODULE hModule = (HMODULE) pWrapperTable->m_LibraryHandle;
			FreeLibrary(hModule);
		#else // _WIN32
			dlclose(pWrapperTable->m_LibraryHandle);
		#endif // _WIN32
			return initWrapperTable(pWrapperTable);
		}
		
		return LIBMCDRIVER_SCANLABOIE_SUCCESS;
	}

	inline LibMCDriver_ScanLabOIEResult CWrapper::loadWrapperTable(sLibMCDriver_ScanLabOIEDynamicWrapperTable * pWrapperTable, const char * pLibraryFileName)
	{
		if (pWrapperTable == nullptr)
			return LIBMCDRIVER_SCANLABOIE_ERROR_INVALIDPARAM;
		if (pLibraryFileName == nullptr)
			return LIBMCDRIVER_SCANLABOIE_ERROR_INVALIDPARAM;
		
		#ifdef _WIN32
		// Convert filename to UTF16-string
		int nLength = (int)strlen(pLibraryFileName);
		int nBufferSize = nLength * 2 + 2;
		std::vector<wchar_t> wsLibraryFileName(nBufferSize);
		int nResult = MultiByteToWideChar(CP_UTF8, 0, pLibraryFileName, nLength, &wsLibraryFileName[0], nBufferSize);
		if (nResult == 0)
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTLOADLIBRARY;
		
		HMODULE hLibrary = LoadLibraryW(wsLibraryFileName.data());
		if (hLibrary == 0) 
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTLOADLIBRARY;
		#else // _WIN32
		void* hLibrary = dlopen(pLibraryFileName, RTLD_LAZY);
		if (hLibrary == 0) 
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTLOADLIBRARY;
		dlerror();
		#endif // _WIN32
		
		#ifdef _WIN32
		pWrapperTable->m_Driver_GetName = (PLibMCDriver_ScanLabOIEDriver_GetNamePtr) GetProcAddress(hLibrary, "libmcdriver_scanlaboie_driver_getname");
		#else // _WIN32
		pWrapperTable->m_Driver_GetName = (PLibMCDriver_ScanLabOIEDriver_GetNamePtr) dlsym(hLibrary, "libmcdriver_scanlaboie_driver_getname");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_Driver_GetName == nullptr)
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_Driver_GetType = (PLibMCDriver_ScanLabOIEDriver_GetTypePtr) GetProcAddress(hLibrary, "libmcdriver_scanlaboie_driver_gettype");
		#else // _WIN32
		pWrapperTable->m_Driver_GetType = (PLibMCDriver_ScanLabOIEDriver_GetTypePtr) dlsym(hLibrary, "libmcdriver_scanlaboie_driver_gettype");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_Driver_GetType == nullptr)
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_Driver_GetVersion = (PLibMCDriver_ScanLabOIEDriver_GetVersionPtr) GetProcAddress(hLibrary, "libmcdriver_scanlaboie_driver_getversion");
		#else // _WIN32
		pWrapperTable->m_Driver_GetVersion = (PLibMCDriver_ScanLabOIEDriver_GetVersionPtr) dlsym(hLibrary, "libmcdriver_scanlaboie_driver_getversion");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_Driver_GetVersion == nullptr)
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_Driver_GetHeaderInformation = (PLibMCDriver_ScanLabOIEDriver_GetHeaderInformationPtr) GetProcAddress(hLibrary, "libmcdriver_scanlaboie_driver_getheaderinformation");
		#else // _WIN32
		pWrapperTable->m_Driver_GetHeaderInformation = (PLibMCDriver_ScanLabOIEDriver_GetHeaderInformationPtr) dlsym(hLibrary, "libmcdriver_scanlaboie_driver_getheaderinformation");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_Driver_GetHeaderInformation == nullptr)
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_GetVersion = (PLibMCDriver_ScanLabOIEGetVersionPtr) GetProcAddress(hLibrary, "libmcdriver_scanlaboie_getversion");
		#else // _WIN32
		pWrapperTable->m_GetVersion = (PLibMCDriver_ScanLabOIEGetVersionPtr) dlsym(hLibrary, "libmcdriver_scanlaboie_getversion");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_GetVersion == nullptr)
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_GetLastError = (PLibMCDriver_ScanLabOIEGetLastErrorPtr) GetProcAddress(hLibrary, "libmcdriver_scanlaboie_getlasterror");
		#else // _WIN32
		pWrapperTable->m_GetLastError = (PLibMCDriver_ScanLabOIEGetLastErrorPtr) dlsym(hLibrary, "libmcdriver_scanlaboie_getlasterror");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_GetLastError == nullptr)
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_ReleaseInstance = (PLibMCDriver_ScanLabOIEReleaseInstancePtr) GetProcAddress(hLibrary, "libmcdriver_scanlaboie_releaseinstance");
		#else // _WIN32
		pWrapperTable->m_ReleaseInstance = (PLibMCDriver_ScanLabOIEReleaseInstancePtr) dlsym(hLibrary, "libmcdriver_scanlaboie_releaseinstance");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_ReleaseInstance == nullptr)
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_AcquireInstance = (PLibMCDriver_ScanLabOIEAcquireInstancePtr) GetProcAddress(hLibrary, "libmcdriver_scanlaboie_acquireinstance");
		#else // _WIN32
		pWrapperTable->m_AcquireInstance = (PLibMCDriver_ScanLabOIEAcquireInstancePtr) dlsym(hLibrary, "libmcdriver_scanlaboie_acquireinstance");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_AcquireInstance == nullptr)
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_InjectComponent = (PLibMCDriver_ScanLabOIEInjectComponentPtr) GetProcAddress(hLibrary, "libmcdriver_scanlaboie_injectcomponent");
		#else // _WIN32
		pWrapperTable->m_InjectComponent = (PLibMCDriver_ScanLabOIEInjectComponentPtr) dlsym(hLibrary, "libmcdriver_scanlaboie_injectcomponent");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_InjectComponent == nullptr)
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_GetSymbolLookupMethod = (PLibMCDriver_ScanLabOIEGetSymbolLookupMethodPtr) GetProcAddress(hLibrary, "libmcdriver_scanlaboie_getsymbollookupmethod");
		#else // _WIN32
		pWrapperTable->m_GetSymbolLookupMethod = (PLibMCDriver_ScanLabOIEGetSymbolLookupMethodPtr) dlsym(hLibrary, "libmcdriver_scanlaboie_getsymbollookupmethod");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_GetSymbolLookupMethod == nullptr)
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_CreateDriver = (PLibMCDriver_ScanLabOIECreateDriverPtr) GetProcAddress(hLibrary, "libmcdriver_scanlaboie_createdriver");
		#else // _WIN32
		pWrapperTable->m_CreateDriver = (PLibMCDriver_ScanLabOIECreateDriverPtr) dlsym(hLibrary, "libmcdriver_scanlaboie_createdriver");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_CreateDriver == nullptr)
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		pWrapperTable->m_LibraryHandle = hLibrary;
		return LIBMCDRIVER_SCANLABOIE_SUCCESS;
	}

	inline LibMCDriver_ScanLabOIEResult CWrapper::loadWrapperTableFromSymbolLookupMethod(sLibMCDriver_ScanLabOIEDynamicWrapperTable * pWrapperTable, void* pSymbolLookupMethod)
{
		if (pWrapperTable == nullptr)
			return LIBMCDRIVER_SCANLABOIE_ERROR_INVALIDPARAM;
		if (pSymbolLookupMethod == nullptr)
			return LIBMCDRIVER_SCANLABOIE_ERROR_INVALIDPARAM;
		
		typedef LibMCDriver_ScanLabOIEResult(*SymbolLookupType)(const char*, void**);
		
		SymbolLookupType pLookup = (SymbolLookupType)pSymbolLookupMethod;
		
		LibMCDriver_ScanLabOIEResult eLookupError = LIBMCDRIVER_SCANLABOIE_SUCCESS;
		eLookupError = (*pLookup)("libmcdriver_scanlaboie_driver_getname", (void**)&(pWrapperTable->m_Driver_GetName));
		if ( (eLookupError != 0) || (pWrapperTable->m_Driver_GetName == nullptr) )
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmcdriver_scanlaboie_driver_gettype", (void**)&(pWrapperTable->m_Driver_GetType));
		if ( (eLookupError != 0) || (pWrapperTable->m_Driver_GetType == nullptr) )
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmcdriver_scanlaboie_driver_getversion", (void**)&(pWrapperTable->m_Driver_GetVersion));
		if ( (eLookupError != 0) || (pWrapperTable->m_Driver_GetVersion == nullptr) )
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmcdriver_scanlaboie_driver_getheaderinformation", (void**)&(pWrapperTable->m_Driver_GetHeaderInformation));
		if ( (eLookupError != 0) || (pWrapperTable->m_Driver_GetHeaderInformation == nullptr) )
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmcdriver_scanlaboie_getversion", (void**)&(pWrapperTable->m_GetVersion));
		if ( (eLookupError != 0) || (pWrapperTable->m_GetVersion == nullptr) )
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmcdriver_scanlaboie_getlasterror", (void**)&(pWrapperTable->m_GetLastError));
		if ( (eLookupError != 0) || (pWrapperTable->m_GetLastError == nullptr) )
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmcdriver_scanlaboie_releaseinstance", (void**)&(pWrapperTable->m_ReleaseInstance));
		if ( (eLookupError != 0) || (pWrapperTable->m_ReleaseInstance == nullptr) )
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmcdriver_scanlaboie_acquireinstance", (void**)&(pWrapperTable->m_AcquireInstance));
		if ( (eLookupError != 0) || (pWrapperTable->m_AcquireInstance == nullptr) )
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmcdriver_scanlaboie_injectcomponent", (void**)&(pWrapperTable->m_InjectComponent));
		if ( (eLookupError != 0) || (pWrapperTable->m_InjectComponent == nullptr) )
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmcdriver_scanlaboie_getsymbollookupmethod", (void**)&(pWrapperTable->m_GetSymbolLookupMethod));
		if ( (eLookupError != 0) || (pWrapperTable->m_GetSymbolLookupMethod == nullptr) )
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("libmcdriver_scanlaboie_createdriver", (void**)&(pWrapperTable->m_CreateDriver));
		if ( (eLookupError != 0) || (pWrapperTable->m_CreateDriver == nullptr) )
			return LIBMCDRIVER_SCANLABOIE_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		return LIBMCDRIVER_SCANLABOIE_SUCCESS;
}

	
	
	/**
	 * Method definitions for class CBase
	 */
	
	/**
	 * Method definitions for class CDriver
	 */
	
	/**
	* CDriver::GetName - returns the name identifier of the driver
	* @return Name of the driver.
	*/
	std::string CDriver::GetName()
	{
		LibMCDriver_ScanLabOIE_uint32 bytesNeededName = 0;
		LibMCDriver_ScanLabOIE_uint32 bytesWrittenName = 0;
		CheckError(m_pWrapper->m_WrapperTable.m_Driver_GetName(m_pHandle, 0, &bytesNeededName, nullptr));
		std::vector<char> bufferName(bytesNeededName);
		CheckError(m_pWrapper->m_WrapperTable.m_Driver_GetName(m_pHandle, bytesNeededName, &bytesWrittenName, &bufferName[0]));
		
		return std::string(&bufferName[0]);
	}
	
	/**
	* CDriver::GetType - returns the type identifier of the driver
	* @return Type of the driver.
	*/
	std::string CDriver::GetType()
	{
		LibMCDriver_ScanLabOIE_uint32 bytesNeededType = 0;
		LibMCDriver_ScanLabOIE_uint32 bytesWrittenType = 0;
		CheckError(m_pWrapper->m_WrapperTable.m_Driver_GetType(m_pHandle, 0, &bytesNeededType, nullptr));
		std::vector<char> bufferType(bytesNeededType);
		CheckError(m_pWrapper->m_WrapperTable.m_Driver_GetType(m_pHandle, bytesNeededType, &bytesWrittenType, &bufferType[0]));
		
		return std::string(&bufferType[0]);
	}
	
	/**
	* CDriver::GetVersion - returns the version identifiers of the driver
	* @param[out] nMajor - Major version.
	* @param[out] nMinor - Minor version.
	* @param[out] nMicro - Micro version.
	* @param[out] sBuild - Build identifier.
	*/
	void CDriver::GetVersion(LibMCDriver_ScanLabOIE_uint32 & nMajor, LibMCDriver_ScanLabOIE_uint32 & nMinor, LibMCDriver_ScanLabOIE_uint32 & nMicro, std::string & sBuild)
	{
		LibMCDriver_ScanLabOIE_uint32 bytesNeededBuild = 0;
		LibMCDriver_ScanLabOIE_uint32 bytesWrittenBuild = 0;
		CheckError(m_pWrapper->m_WrapperTable.m_Driver_GetVersion(m_pHandle, &nMajor, &nMinor, &nMicro, 0, &bytesNeededBuild, nullptr));
		std::vector<char> bufferBuild(bytesNeededBuild);
		CheckError(m_pWrapper->m_WrapperTable.m_Driver_GetVersion(m_pHandle, &nMajor, &nMinor, &nMicro, bytesNeededBuild, &bytesWrittenBuild, &bufferBuild[0]));
		sBuild = std::string(&bufferBuild[0]);
	}
	
	/**
	* CDriver::GetHeaderInformation - returns the header information
	* @param[out] sNameSpace - NameSpace of the driver.
	* @param[out] sBaseName - BaseName of the driver.
	*/
	void CDriver::GetHeaderInformation(std::string & sNameSpace, std::string & sBaseName)
	{
		LibMCDriver_ScanLabOIE_uint32 bytesNeededNameSpace = 0;
		LibMCDriver_ScanLabOIE_uint32 bytesWrittenNameSpace = 0;
		LibMCDriver_ScanLabOIE_uint32 bytesNeededBaseName = 0;
		LibMCDriver_ScanLabOIE_uint32 bytesWrittenBaseName = 0;
		CheckError(m_pWrapper->m_WrapperTable.m_Driver_GetHeaderInformation(m_pHandle, 0, &bytesNeededNameSpace, nullptr, 0, &bytesNeededBaseName, nullptr));
		std::vector<char> bufferNameSpace(bytesNeededNameSpace);
		std::vector<char> bufferBaseName(bytesNeededBaseName);
		CheckError(m_pWrapper->m_WrapperTable.m_Driver_GetHeaderInformation(m_pHandle, bytesNeededNameSpace, &bytesWrittenNameSpace, &bufferNameSpace[0], bytesNeededBaseName, &bytesWrittenBaseName, &bufferBaseName[0]));
		sNameSpace = std::string(&bufferNameSpace[0]);
		sBaseName = std::string(&bufferBaseName[0]);
	}
	
	/**
	 * Method definitions for class CDriver_ScanLab_OIE
	 */

} // namespace LibMCDriver_ScanLabOIE

#endif // __LIBMCDRIVER_SCANLABOIE_CPPHEADER_DYNAMIC_CPP
