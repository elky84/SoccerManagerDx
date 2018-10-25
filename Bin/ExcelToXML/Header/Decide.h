#pragma once

namespace ExcelData
{

class DecideInfo
{
public:
	DecideInfo()
	{
		memset(&m_Type, 0, sizeof(m_Type));

		memset(&m_Targeting, 0, sizeof(m_Targeting));

		memset(&m_Standard_Detail, 0, sizeof(m_Standard_Detail));

		memset(&m_Standard, 0, sizeof(m_Standard));

		memset(&m_Index, 0, sizeof(m_Index));

	}

	int& TypeReference()
	{
		return m_Type;
	}

	int Type() const
	{
		return m_Type;
	}

	void Type(const int& _Type)
	{
		m_Type = _Type;
	}

	int& TargetingReference()
	{
		return m_Targeting;
	}

	int Targeting() const
	{
		return m_Targeting;
	}

	void Targeting(const int& _Targeting)
	{
		m_Targeting = _Targeting;
	}

	int& Standard_DetailReference()
	{
		return m_Standard_Detail;
	}

	int Standard_Detail() const
	{
		return m_Standard_Detail;
	}

	void Standard_Detail(const int& _Standard_Detail)
	{
		m_Standard_Detail = _Standard_Detail;
	}

	int& StandardReference()
	{
		return m_Standard;
	}

	int Standard() const
	{
		return m_Standard;
	}

	void Standard(const int& _Standard)
	{
		m_Standard = _Standard;
	}

	int& IndexReference()
	{
		return m_Index;
	}

	int Index() const
	{
		return m_Index;
	}

	void Index(const int& _Index)
	{
		m_Index = _Index;
	}

private:
	int m_Type;
	int m_Targeting;
	int m_Standard_Detail;
	int m_Standard;
	int m_Index;
};

class DecideInfoData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		DecideInfo Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/DecideInfo.XML");
		if( false == parser.read_file(L"./XML/DecideInfo.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/DecideInfo.XML");
			return false;
		}

		if ( false == parser.execute(L"/DecideInfoList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /DecideInfoList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"Index", Instance.IndexReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.IndexReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Standard", Instance.StandardReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.StandardReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Standard_Detail", Instance.Standard_DetailReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Standard_DetailReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Targeting", Instance.TargetingReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.TargetingReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Type", Instance.TypeReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.TypeReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, DecideInfo>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, DecideInfo& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, DecideInfo>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, DecideInfo> m_Map;
};

__declspec(selectany) DecideInfoData DecideInfoDataInstance;

} // ExcelData

