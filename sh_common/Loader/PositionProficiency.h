#pragma once

namespace ExcelData
{

class PositionProficiency
{
public:
	PositionProficiency()
	{
		memset(&m_SW, 0, sizeof(m_SW));

		memset(&m_SS, 0, sizeof(m_SS));

		memset(&m_RWF, 0, sizeof(m_RWF));

		memset(&m_RWB, 0, sizeof(m_RWB));

		memset(&m_RM, 0, sizeof(m_RM));

		memset(&m_RB, 0, sizeof(m_RB));

		memset(&m_RAM, 0, sizeof(m_RAM));

		memset(&m_LWF, 0, sizeof(m_LWF));

		memset(&m_LWB, 0, sizeof(m_LWB));

		memset(&m_LM, 0, sizeof(m_LM));

		memset(&m_LB, 0, sizeof(m_LB));

		memset(&m_LAM, 0, sizeof(m_LAM));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_GK, 0, sizeof(m_GK));

		memset(&m_DM, 0, sizeof(m_DM));

		memset(&m_CM, 0, sizeof(m_CM));

		memset(&m_CF, 0, sizeof(m_CF));

		memset(&m_CB, 0, sizeof(m_CB));

		memset(&m_AMC, 0, sizeof(m_AMC));

	}

	int& SWReference()
	{
		return m_SW;
	}

	int SW() const
	{
		return m_SW;
	}

	void SW(const int& _SW)
	{
		m_SW = _SW;
	}

	int& SSReference()
	{
		return m_SS;
	}

	int SS() const
	{
		return m_SS;
	}

	void SS(const int& _SS)
	{
		m_SS = _SS;
	}

	int& RWFReference()
	{
		return m_RWF;
	}

	int RWF() const
	{
		return m_RWF;
	}

	void RWF(const int& _RWF)
	{
		m_RWF = _RWF;
	}

	int& RWBReference()
	{
		return m_RWB;
	}

	int RWB() const
	{
		return m_RWB;
	}

	void RWB(const int& _RWB)
	{
		m_RWB = _RWB;
	}

	int& RMReference()
	{
		return m_RM;
	}

	int RM() const
	{
		return m_RM;
	}

	void RM(const int& _RM)
	{
		m_RM = _RM;
	}

	int& RBReference()
	{
		return m_RB;
	}

	int RB() const
	{
		return m_RB;
	}

	void RB(const int& _RB)
	{
		m_RB = _RB;
	}

	int& RAMReference()
	{
		return m_RAM;
	}

	int RAM() const
	{
		return m_RAM;
	}

	void RAM(const int& _RAM)
	{
		m_RAM = _RAM;
	}

	int& LWFReference()
	{
		return m_LWF;
	}

	int LWF() const
	{
		return m_LWF;
	}

	void LWF(const int& _LWF)
	{
		m_LWF = _LWF;
	}

	int& LWBReference()
	{
		return m_LWB;
	}

	int LWB() const
	{
		return m_LWB;
	}

	void LWB(const int& _LWB)
	{
		m_LWB = _LWB;
	}

	int& LMReference()
	{
		return m_LM;
	}

	int LM() const
	{
		return m_LM;
	}

	void LM(const int& _LM)
	{
		m_LM = _LM;
	}

	int& LBReference()
	{
		return m_LB;
	}

	int LB() const
	{
		return m_LB;
	}

	void LB(const int& _LB)
	{
		m_LB = _LB;
	}

	int& LAMReference()
	{
		return m_LAM;
	}

	int LAM() const
	{
		return m_LAM;
	}

	void LAM(const int& _LAM)
	{
		m_LAM = _LAM;
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

	int& GKReference()
	{
		return m_GK;
	}

	int GK() const
	{
		return m_GK;
	}

	void GK(const int& _GK)
	{
		m_GK = _GK;
	}

	int& DMReference()
	{
		return m_DM;
	}

	int DM() const
	{
		return m_DM;
	}

	void DM(const int& _DM)
	{
		m_DM = _DM;
	}

	int& CMReference()
	{
		return m_CM;
	}

	int CM() const
	{
		return m_CM;
	}

	void CM(const int& _CM)
	{
		m_CM = _CM;
	}

	int& CFReference()
	{
		return m_CF;
	}

	int CF() const
	{
		return m_CF;
	}

	void CF(const int& _CF)
	{
		m_CF = _CF;
	}

	int& CBReference()
	{
		return m_CB;
	}

	int CB() const
	{
		return m_CB;
	}

	void CB(const int& _CB)
	{
		m_CB = _CB;
	}

	int& AMCReference()
	{
		return m_AMC;
	}

	int AMC() const
	{
		return m_AMC;
	}

	void AMC(const int& _AMC)
	{
		m_AMC = _AMC;
	}

private:
	int m_SW;
	int m_SS;
	int m_RWF;
	int m_RWB;
	int m_RM;
	int m_RB;
	int m_RAM;
	int m_LWF;
	int m_LWB;
	int m_LM;
	int m_LB;
	int m_LAM;
	int m_Index;
	int m_GK;
	int m_DM;
	int m_CM;
	int m_CF;
	int m_CB;
	int m_AMC;
};

class PositionProficiencyData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		PositionProficiency Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/PositionProficiency.XML");
		if( false == parser.read_file(L"./XML/PositionProficiency.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/PositionProficiency.XML");
			return false;
		}

		if ( false == parser.execute(L"/PositionProficiencyList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /PositionProficiencyList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"AMC", Instance.AMCReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.AMCReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"CB", Instance.CBReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.CBReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"CF", Instance.CFReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.CFReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"CM", Instance.CMReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.CMReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"DM", Instance.DMReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.DMReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"GK", Instance.GKReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.GKReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Index", Instance.IndexReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.IndexReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"LAM", Instance.LAMReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.LAMReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"LB", Instance.LBReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.LBReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"LM", Instance.LMReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.LMReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"LWB", Instance.LWBReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.LWBReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"LWF", Instance.LWFReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.LWFReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"RAM", Instance.RAMReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.RAMReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"RB", Instance.RBReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.RBReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"RM", Instance.RMReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.RMReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"RWB", Instance.RWBReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.RWBReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"RWF", Instance.RWFReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.RWFReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"SS", Instance.SSReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.SSReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"SW", Instance.SWReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.SWReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, PositionProficiency>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, PositionProficiency& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, PositionProficiency>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, PositionProficiency> m_Map;
};

__declspec(selectany) PositionProficiencyData PositionProficiencyDataInstance;

} // ExcelData

